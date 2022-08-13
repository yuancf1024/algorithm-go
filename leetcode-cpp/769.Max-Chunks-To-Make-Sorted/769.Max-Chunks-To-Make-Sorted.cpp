/**
 * @file 769.Max-Chunks-To-Make-Sorted.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * leetcode-769.最多能完成排序的块
 * 
 给定一个长度为 n 的整数数组 arr ，
 它表示在 [0, n - 1] 范围内的整数的排列。

我们将 arr 分割成若干 块 (即分区)，并对每个块单独排序。
将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。
返回数组能分成的最多块数量。

示例 1:
输入: arr = [4,3,2,1,0]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。

示例 2:
输入: arr = [1,0,2,3,4]
输出: 4
解释:
我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
 
提示:

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
arr 中每个元素都 不同
 */

// 贪心
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) { 
        int ans = 0, sum = 0; // sum记录当前区间的元素值之和
        int total = 0; // total记录当前区间的下标和
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            total += i;
            /* 当sum==total时，说明当前区间中所有元素和所有下标存在一一对应关系
            则当前区间就可以当作一个块
            */
           if (sum == total) {
               ans++;
               sum = 0, total = 0; // 归零
           }
        }
        return ans;
    }
};

/**
 * @brief 
 * 看以下例子，符合题意的块已经划分好了


下标： 0 1 2 | 3 4 | 5 6 7 
元素： 2 1 0 | 4 3 | 7 6 5
发现了么？在每块内，所有元素和所有下标之间都有一一对应关系，
就好像小朋友做连线题一样，这样，就一定有下标之和==元素之和。

所以，我们可以遍历数组，每当出现下标之和等于元素之和的一个区间，
就贪心的把该区间划分为一个块，然后在继续寻找下一个满足要求的区间。

 */


// 方法1 暴力
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) { 
        int ans = 0, maxNum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxNum = max(maxNum, arr[i]);
            if (maxNum == i) {
                ans++;
            }
        }
        return ans;
    }
};

/*
思想： 从左到右找到最大值，因为最后排序后，最大值在“此值”索引下，
所以这一段数据，就对着。所以数量++
*/

/**
 * @brief 
 * 方法一： 暴力
思路和算法

首先找到从左块开始最小块的大小。
如果前 k 个元素为 [0, 1, ..., k-1]，
可以直接把他们分为一个块。
当我们需要检查 [0, 1, ..., n-1] 中前 k+1 个元素是不是 [0, 1, ..., k] 的时候，
只需要检查其中最大的数是不是 k 就可以了。

复杂度分析

时间复杂度: O(N)，其中 N 为数组 arr 的长度。

空间复杂度: O(1)。
 */