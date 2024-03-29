/**
 * @file 122.Best-Time-to-Buy-and-Sell-Stock-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 * leetcode-122.买卖股票的最佳时机 II
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。
你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

示例 1：
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。

示例 2：
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     总利润为 4 。

示例 3：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。

提示：

1 <= prices.length <= 3 * 10^4
0 <= prices[i] <= 10^4

 */
#include <bits/stdc++.h>

using namespace std;


// DP 不太优雅的实现
class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

// DP的优雅实现
class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        // int dp[n][2];
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};


/**
 * @brief 
 * 方法一：动态规划
考虑到「不能同时参与多笔交易」，因此每天交易结束后只可能存在手里
有一支股票或者没有股票的状态。

定义状态dp[i][0] 表示第i 天交易完后手里没有股票的最大利润，
dp[i][1] 表示第i 天交易完后手里持有一支股票的最大利润（i 从 0开始）。

- 考虑dp[i][0] 的转移方程，如果这一天交易完后手里没有股票，
那么可能的转移状态为前一天已经没有股票，即 dp[i−1][0]，
或者前一天结束的时候手里持有一支股票，即 dp[i−1][1]，
这时候我们要将其卖出，并获得prices[i] 的收益。
因此为了收益最大化，我们列出如下的转移方程：

dp[i][0]=max{dp[i−1][0],dp[i−1][1]+prices[i]}

- 再来考虑 dp[i][1]，按照同样的方式考虑转移状态，
那么可能的转移状态为前一天已经持有一支股票，即 dp[i−1][1]，
或者前一天结束时还没有股票，即dp[i−1][0]，
这时候我们要将其买入，并减少prices[i] 的收益。可以列出如下的转移方程：

dp[i][1]=max{dp[i−1][1],dp[i−1][0]−prices[i]}

对于初始状态，根据状态定义我们可以知道第 0 天交易结束的时候dp[0][0]=0，
dp[0][1]=−prices[0]。

因此，我们只要从前往后依次计算状态即可。
由于全部交易结束后，持有股票的收益一定低于不持有股票的收益，
因此这时候dp[n−1][0] 的收益必然是大于 dp[n−1][1] 的，
最后的答案即为dp[n−1][0]。


注意到上面的状态转移方程中，每一天的状态只与前一天的状态有关，
而与更早的状态都无关，因此我们不必存储这些无关的状态，
只需要将dp[i−1][0] 和 dp[i−1][1] 存放在两个变量中，
通过它们计算出dp[i][0] 和 dp[i][1] 并存回对应的变量，
以便于第i+1 天的状态转移即可。


复杂度分析

时间复杂度：O(n)，其中n为数组的长度。一共有2n 个状态，
每次状态转移的时间复杂度为 O(1)，因此时间复杂度为 O(2n)=O(n)。

空间复杂度：O(n)。我们需要开辟O(n) 空间存储动态规划中的所有状态。
如果使用空间优化，空间复杂度可以优化至O(1)。

 */

// 方法二：贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};
/**
 * @brief 
 * 方法二：贪心
由于股票的购买没有限制，因此整个问题等价于寻找x个不相交的区间 
(l_i,r_i]使得如下的等式最大化

∑xa[r_i]−a[l_i]

其中l_i表示在第l_i天买入，r_i表示在第r_i天卖出。

同时我们注意到对于(l_i,r_i]这一个区间贡献的价值a[r_i]-a[l_i]，
其实等价于 (l_i,l_i+1],(l_i+1,l_i+2],...,(r_i-1,r_i]
(这若干个区间长度为1的区间的价值和，即

a[r_i]-a[l_i]=(a[r_i]-a[r_i-1])+(a[r_i-1]-a[r_i-2])+...+
(a[l_i+1]-a[l_i])


因此问题可以简化为找x个长度为1的区间 (l_i,l_i+1]使得
∑ a[l_i​+1]−a[l_i] 价值最大化。
i=1
x
​
贪心的角度考虑我们每次选择贡献大于0的区间即能使得答案最大化，
因此最后答案为
     n−1
ans = ∑  max{0, a[i]−a[i−1]}
     i=1
其中n为数组的长度。

需要说明的是，贪心算法只能用于计算最大利润，
计算的过程并不是实际的交易过程。

考虑题目中的例子[1,2,3,4,5]，数组的长度n=5，
由于对所有的1≤i<n 都有a[i]>a[i-1]，因此答案为

    n−1
ans= ∑ a[i]−a[i−1]=4
    i=1
但是实际的交易过程并不是进行4次买入和4次卖出，而是在第1天买入，第5天卖出。

复杂度分析
时间复杂度：O(n)，其中n为数组的长度。我们只需要遍历一次数组即可。
空间复杂度：O(1)。只需要常数空间存放若干变量。
 */