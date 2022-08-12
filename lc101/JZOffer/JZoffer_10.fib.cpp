/**
 * @file JZoffer_10.fib.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列
的第 n 项（即 F(N)）。斐波那契数列的定义如下：
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），
如计算初始结果为：1000000008，请返回 1。

示例 1：
输入：n = 2
输出：1

示例 2：
输入：n = 5
输出：5

提示：
0 <= n <= 100

 */


// 递归 效率很低的算法
// 超时
class Solution {
public:
    int fib(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
};

// DP + 滚动数组
class Solution {
public:
    int fib(int n) { int MOD = 1e9 + 7;
        if (n < 2) {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i) {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};

/**
 * @brief 
 * 方法一：动态规划
斐波那契数的边界条件是 F(0)=0 和 F(1)=1。
当 n>1 时，每一项的和都等于前两项的和，
因此有如下递推关系：
F(n)=F(n-1)+F(n-2)

由于斐波那契数存在递推关系，
因此可以使用动态规划求解。
动态规划的状态转移方程即为上述递推关系，
边界条件为 F(0) 和 F(1)。

根据状态转移方程和边界条件，可以得到时间复杂度和
空间复杂度都是 O(n) 的实现。
由于 F(n) 只和 F(n−1) 与 F(n−2) 有关，
因此可以使用「滚动数组思想」把空间复杂度优化成 O(1)。
如下的代码中给出的就是这种实现。

计算过程中，答案需要取模 1e9+7。

复杂度分析
时间复杂度：O(n)。
空间复杂度：O(1)。
 */