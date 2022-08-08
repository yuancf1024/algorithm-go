/**
 * @file 444.Sequence-Reconstruction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * leetcode-444.重建序列
 * 
给定一个长度为 n 的整数数组 nums ，其中 nums 是范围为 [1，n] 的整数的排列。
还提供了一个 2D 整数数组 sequences ，其中 sequences[i] 是 nums 的子序列。
检查 nums 是否是唯一的最短 超序列 。
最短 超序列 是 长度最短 的序列，并且所有序列 sequences[i] 都是它的子序列。
对于给定的数组 sequences ，可能存在多个有效的 超序列 。

例如，对于 sequences = [[1,2],[1,3]] ，有两个最短的 超序列 ，[1,2,3] 和 [1,3,2] 。

而对于 sequences = [[1,2],[1,3],[1,2,3]] ，
唯一可能的最短 超序列 是 [1,2,3] 。[1,2,3,4] 是可能的超序列，但不是最短的。
如果 nums 是序列的唯一最短 超序列 ，则返回 true ，否则返回 false 。
子序列 是一个可以通过从另一个序列中删除一些元素或不删除任何元素，
而不改变其余元素的顺序的序列。

示例 1：
输入：nums = [1,2,3], sequences = [[1,2],[1,3]]
输出：false

解释：有两种可能的超序列：[1,2,3]和[1,3,2]。
序列 [1,2] 是[1,2,3]和[1,3,2]的子序列。
序列 [1,3] 是[1,2,3]和[1,3,2]的子序列。
因为 nums 不是唯一最短的超序列，所以返回false。

示例 2：
输入：nums = [1,2,3], sequences = [[1,2]]
输出：false

解释：最短可能的超序列为 [1,2]。
序列 [1,2] 是它的子序列：[1,2]。
因为 nums 不是最短的超序列，所以返回false。

示例 3：
输入：nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
输出：true

解释：最短可能的超序列为[1,2,3]。
序列 [1,2] 是它的一个子序列：[1,2,3]。
序列 [1,3] 是它的一个子序列：[1,2,3]。
序列 [2,3] 是它的一个子序列：[1,2,3]。
因为 nums 是唯一最短的超序列，所以返回true。
 
提示：

n == nums.length
1 <= n <= 10^4
nums 是 [1, n] 范围内所有整数的排列
1 <= sequences.length <= 10^4
1 <= sequences[i].length <= 10^4
1 <= sum(sequences[i].length) <= 10^5
1 <= sequences[i][j] <= n
sequences 的所有数组都是 唯一 的
sequences[i] 是 nums 的一个子序列
 */

// 拓扑排序
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> from(n + 1);
        vector<int> inDegree(n + 1, 0);
        for (vector<int>& v : sequences) { // 1. 初始时遍历sequences中的所有元素
            for (int i = 1; i < v.size(); i++) { // v[i-1] -> v[i]
                from[v[i - 1]].push_back(v[i]);
                inDegree[v[i]]++; // 后面的节点入度+1
            }
        }
        queue<int> zero;
        for (int i = 1; i <= n; ++i) { // 遍历所有节点，将入度为0的节点入队
            if (inDegree[i] == 0) {
                zero.push(i);
            }
        }
        while (zero.size()) {
            if (zero.size() != 1) { // 如果同时有多个入度为0的节点，就无法判断这些节点之间的相对顺序
                return false; // 返回false
            }
            int thisFrom = zero.front(); // 出队
            zero.pop();
            for (int& thisTo : from[thisFrom]) { // thisFrom 行对应的是thisFrom节点指向的节点
                inDegree[thisTo]--; // 去掉从这个节点开始的所有的边，并把去掉的边所指向的节点的入度-1
                if (!inDegree[thisTo]) { // 节点入度为0，入队
                    zero.push(thisTo);
                }
            }
        }
        for (int i = 1; i <= n; ++i) { // 排序结束后，所有节点的入度必须全部为0 才返回true
            if (inDegree[i]) {
                return false;
            }
        }
        return true; // 同时满足条件1：整个排序过程中，队列中最多有1个节点 & 条件2：排序结束后，所有节点的入度必须全部为0
    }
};

/**
 * @brief 参考大佬@LetMeFly 的题解
我们根据样例来分析：

样例一：
nums = [1,2,3], sequences = [[1,2],[1,3]]

样例一中，我们已知排列[1, 2, 3]的两个子序列[1, 2]和[1, 3]。
这就说明：1必须出现在2的前面并且1必须出现在3的前面。
（因为子序列中元素相对位置必须保持不变）
但是2和3哪个在前哪个在后呢？根据给定输入[[1,2],[1,3]]无法判断。
因此，样例一不能唯一确定“超序列”

样例二：
nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]

样例二中，我们已知排列[1, 2, 3]的三个子序列[1, 2]、[1, 3]和[2, 3]。
这就说明1在2前、1在3前、2在3前。

那么要满足上述三个条件，有且仅有一种排列方式：[1, 2, 3]
因此样例二能唯一确定“超序列”[1, 2, 3]

实现思路：

“1在2前、1在3前”让我们很容易想到拓扑排序。

我们可以构建一张图，图中节点是nums中的每一个元素。
如果1在2前就添加一条1→2的边。

那么样例一的图将被构建为：


从入度为0的节点1开始进行拓扑排序，排序之后发现剩下两个节点，
彼此之间无法确定相对顺序。

样例二的图将被构建为：


从入度为0的节点1开始进行拓扑排序，排序之后只剩下了最终节点3

具体实现方法

1. 初始时遍历sequences中的所有元素，对于sequences中的[a, b, c]，
构建一条a→b的边和一条b→c的边，并把b和c的入度+1
2. 遍历所有节点，将入度为0的节点入队。
不断从队列中取出节点，去掉从这个节点开始的所有的边，
并把去掉的边所指向的节点的入度-1。
（假如从节点a出发有两条边a→b和a→c，那么b和c的入度-1）
3. 直到队列为空

注意：
1. 整个排序过程中，队列中最多有1个节点。
（那是因为如果同时有多个入度为0的节点，就无法判断这些节点之间的相对顺序）
2. 排序结束后，所有节点的入度必须全部为0

如果同时满足上述两个条件，就返回true

时间复杂度O(n + m)，其中n是排列的长度，m是sequences中元素的个数
空间复杂度O(n + m)
 * 
 */