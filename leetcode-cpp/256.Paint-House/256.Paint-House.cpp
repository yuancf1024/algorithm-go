/* 256.Paint-House 剑指 Offer II 091. 粉刷房子
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、
蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子
并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，
所以房子粉刷成不同颜色的花费成本也是不同的。
每个房子粉刷成不同颜色的花费是以一个 n x 3 的
正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；
costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。

请计算出粉刷完所有房子最少的花费成本。

示例 1：
输入: costs = [[17,2,17],[16,16,5],[14,3,19]]
输出: 10
解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
     最少花费: 2 + 5 + 3 = 10。

示例 2：
输入: costs = [[7,6,2]]
输出: 2
 
提示:
costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20

*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) { 
        int n = costs.size();
        // 定义：当第i个房子粉刷颜色j时，粉刷[0..i] 这些房子所需的最少花费为dp[i][j]
        // 其中j = 0, 1, 2 分别代表三种颜色
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // base case
        for (int j = 0; j < 3; j++) {
            // 粉刷第一个房子的花费是确定的
            dp[0][j] = costs[0][j];
        }

        // 状态转移，穷举所有选择
        for (int i = 1; i < n; i++) {
            // 颜色0 只能挨着颜色1或颜色2
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            // 颜色1 只能挨着颜色0或颜色2
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            // 颜色2 只能挨着颜色0或颜色1
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }

        // 计算题目要求的结果
        int res = 100000;
        for (int j = 0; j < 3; j++) {
            res = min(res, dp[n - 1][j]);
        }
        return res;
    }
};

/* 参考labuladong算法思路

这道题有些类似 最长递增子序列 和 最大子数组和，
因为它们定义 dp 数组的方式都是「以 xx 结尾的最值是 dp[i]」。

这道题对 dp 数组的定义是：

当第 i 个房子粉刷颜色 j 时，
粉刷 [0..i] 这些房子所需的最少花费为 dp[i][j]。

有了这个定义，题目想求的答案就是 sum(dp[n-1][..])。

又因为题目说相同的颜色不能相邻，所以状态转移方程为：

// 颜色 0 只能挨着颜色 1 或颜色 2
dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
// 颜色 1 只能挨着颜色 0 或颜色 2
dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
// 颜色 2 只能挨着颜色 0 或颜色 1
dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];

*/

// C++ 经典dp(原地)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) { int n = costs.size();
        for (int i = 1; i < n; ++i) {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};