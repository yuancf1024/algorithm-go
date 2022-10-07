/**
 * @file 279.Perfect-Squares.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-279.完全平方数
 * 
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；
换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：

1 <= n <= 104
 */

#include <bits/stdc++.h>

using namespace std;

// 方法1：DP 动态规划
class Solution {
public:
    int numSquares(int n) { 
        vector<int> f(n + 1);
        for (int i = 1; i <= n; ++i) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

// 参考硬币问题的实现
class Solution {
public:
    int numSquares(int n) { 
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i; // 最坏的情况：所有被加起来的完全平方数都是1
            for (int j = 1; i - j * j >= 0; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1); 
                // dp[i]表示数字i最少可以由几个完全平方数相加构成
            }
        }
        return dp[n];
    }
};
/*
dp[i]表示数字i最少可以由几个完全平方数相加构成
位置i只依赖i-j*j的位置，如i-1、i-4、i-9等等位置，才能满足完全平方分割的条件。
因此dp[i]可以取的最小值即为1+min(dp[i-1], dp[i-4], dp[i-9]...)
*/

/**
 * @brief 
 * 方法一：动态规划
思路及算法

我们可以依据题目的要求写出状态表达式：
f[i] 表示最少需要多少个数的平方来表示整数i。

这些数必然落在区间 [1,\sqrt{n}]。我们可以枚举这些数，
假设当前枚举到j，那么我们还需要取若干数的平方，构成 i-(j^2)。
此时我们发现该子问题和原问题类似，只是规模变小了。
这符合了动态规划的要求，于是我们可以写出状态转移方程。

f[i]=1+\min_{j=1}^{\lfloor\sqrt{i}\rfloor}{f[i-j^2]}

其中 f[0]=0 为边界条件，实际上我们无法表示数字0，
只是为了保证状态转移过程中遇到j 恰为 \sqrt{i}的情况合法。

同时因为计算f[i] 时所需要用到的状态仅有 f[i-j^2]，必然小于i，
因此我们只需要从小到大地枚举i 来计算f[i] 即可。

复杂度分析

时间复杂度：O(n\sqrt{n})，其中n为给定的正整数。
状态转移方程的时间复杂度为 O(\sqrt{n})，共需要计算n 个状态，
因此总时间复杂度为 O(n \sqrt{n})。
空间复杂度：O(n)。我们需要O(n) 的空间保存状态。

 */