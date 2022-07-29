/* 6131. 不可能得到的最短骰子序列
给你一个长度为 n 的整数数组 rolls 和一个整数 k 。
你扔一个 k 面的骰子 n 次，骰子的每个面分别是 1 到 k ，
其中第 i 次扔得到的数字是 rolls[i] 。

请你返回 无法 从 rolls 中得到的 最短 骰子子序列的长度。

扔一个 k 面的骰子 len 次得到的是一个长度为 len 的 骰子子序列 。

注意 ，子序列只需要保持在原数组中的顺序，不需要连续。

示例 1：
输入：rolls = [4,2,1,2,3,3,2,4,1], k = 4
输出：3

解释：所有长度为 1 的骰子子序列 [1] ，[2] ，[3] ，[4] 都可以从原数组中得到。
所有长度为 2 的骰子子序列 [1, 1] ，[1, 2] ，... ，[4, 4] 都可以从原数组中得到。
子序列 [1, 4, 2] 无法从原数组中得到，所以我们返回 3 。
还有别的子序列也无法从原数组中得到。

示例 2：
输入：rolls = [1,1,2,2], k = 2
输出：2

解释：所有长度为 1 的子序列 [1] ，[2] 都可以从原数组中得到。
子序列 [2, 1] 无法从原数组中得到，所以我们返回 2 。
还有别的子序列也无法从原数组中得到，但 [2, 1] 是最短的子序列。

示例 3：
输入：rolls = [1,1,3,2,2,2,3,3], k = 4
输出：1

解释：子序列 [4] 无法从原数组中得到，所以我们返回 1 。
还有别的子序列也无法从原数组中得到，但 [4] 是最短的子序列。
 
提示：

n == rolls.length
1 <= n <= 10^5
1 <= rolls[i] <= k <= 10^5
*/

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 1, left = k, mark[k + 1]; // mark[v]标记v属于哪个子段
        memset(mark, 0, sizeof(mark));
        for (int v : rolls) {
            if (mark[v] < ans) {
                mark[v] = ans;
                if (--left == 0) { // 用left表示该段还剩下没找到的元素个数
                    left = k;
                    ++ans;
                }
            }
        }
        return ans;
    }

    // 该实现有待商榷
    // int shortestSequence(vector<int>& rolls, int k) { 
    //     int ans = 1;
    //     set<int> s;
    //     for (int v : rolls) {
    //         if (!s.find(v)) {
    //             s.insert(v);
    //         }
    //         if (s.size() == k) {
    //             ans++;
    //             set<int> s;
    //         }
    //     }
    //     return ans;
    // }
};

/*
@黑小嘿 文字总结，更容易理解
这种题，灵神给这么严谨的提示还是很难看懂的，看视频好点

- 不断去找 1～k（作为一段），m段，答案就是 m +1
    - 当1～k都找到即找到了一段，m段，长度为m的子序列就都可以从原数组中得到
- 实现方法（灵神视频都有讲，我mark一下方法1：
    - 方法1. 用set实现好理解，找到 1～k就结束，再清空set重新找
    - 方法2.只要初始化一次空间，用mark数组标记1～k个元素在哪一段，用left表示该段还剩下没找到的元素个数，
    当left等于0，即都找到，ans才+1
- 我测试用时和内存消耗都是 第2种方法好
*/

/*
解题思路：参考@灵茶山艾府

- 提示 1
考虑包含 1 到 k 的最短前缀 ，无法得到的子序列的第一个数必然在里面。

- 提示 2-1
这个前缀的最后一个数 x，在前缀中只会出现一次。

反证：如果 x 出现多次，那么我们可以缩短前缀，同样可以包含 1 到 k。

- 提示 2-2
我们可以取 x 当做子序列的第一个数。

- 提示 3
去掉这个前缀，考虑下一个包含 1 到 k 的最短前缀。
在提示 2-2 的前提下，子序列的第二个数必然在这个前缀中。
同样地，取前缀最后一个数当做子序列的第二个数。

根据提示 2-1，按照这种取法，取到的这两个数组成的子序列，
一定不会都位于第一个前缀中
（读者可以用这两个数相同和不同来分类讨论）。
因此这种取法是正确的。

- 提示 4
不断重复这一过程，直到剩余部分无法包含 1 到 k 时停止。

设我们取到了 m 个数，对应着 rolls 的 m 个子段。
由于每一段都包含 1 到 k，rolls 必然包含长度为 m 的子序列：
每一段都选一个元素即可组成这样的子序列。

因此答案至少为 m+1。

我们可以构造出一个长为 m+1 的子序列，它不在 rolls 中：
前 m 个数分别取各个子段的最后一个数，第 m+1 个数取不在剩余部分中的数。

代码实现时，可以在遍历数组的同时，用一个 mark 数组标记当前元素属于哪个子段。
这种做法的好处是每次调用时只会申请一次空间，效率更高。

复杂度分析
时间复杂度：O(n+k)，其中 n 为 rolls 的长度。
空间复杂度：O(k)。

思考题
给你 n，k 和答案 ans，请你构造一个长为 n 的 rolls 数组，
使得 shortestSequence(rolls, k) 的输出恰好为 ans。

*/
