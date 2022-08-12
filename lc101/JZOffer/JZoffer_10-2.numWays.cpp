/**
 * @file JZoffer_10-2.numWays.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 剑指 Offer 10- II. 青蛙跳台阶问题
 * 
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），
如计算初始结果为：1000000008，请返回 1。

示例 1：
输入：n = 2
输出：2

示例 2：
输入：n = 7
输出：21

示例 3：
输入：n = 0
输出：1
提示：

0 <= n <= 100
 */

// 复写 2022-08-12 DP + 滚动数组
// 思路类似于Fib数列
class Solution {
public:
    int numWays(int n) {
        if (n < 2) { // 考虑边界条件
            return 1;
        }
        int p = 0, q = 0, r = 1;
        int MOD = 1e9+7;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};