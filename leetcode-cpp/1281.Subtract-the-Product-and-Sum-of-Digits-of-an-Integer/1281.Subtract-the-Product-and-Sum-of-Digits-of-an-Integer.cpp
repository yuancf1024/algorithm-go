/**
 * @file 1281.Subtract-the-Product-and-Sum-of-Digits-of-an-Integer.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1281.整数的各位积和之差
 * @version 0.1
 * @date 2023-08-09
 * 
 * @copyright Copyright (c) 2023
 * 给你一个整数 n，请你帮忙计算并返回该整数
 * 「各位数字之积」与「各位数字之和」的差。
示例 1：
输入：n = 234
输出：15 
解释：
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15

示例 2：
输入：n = 4421
输出：21
解释： 
各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
 

提示：

1 <= n <= 10^5
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 自己的实现
    int subtractProductAndSum(int n) {
        int ans = 0;
        int mul = 1, sum = 0;
        // 考虑边界情况
        if (n >= 0 && n < 10) {
            return 0;
        }
        while ( n > 0) {
            int t = 0;
            t = n % 10;
            mul *= t;
            sum += t;
            n /= 10;
        }
        ans = mul - sum;
        return ans;
    }

    // leetcode官方题解
    int subtractProductAndSum2(int n) {
        int m = 1, s = 0;
        while (n) {
            int x = n % 10;
            n /= 10;
            m *= x;
            s += x;
        }
        return m - s; 
    }

    // C++ 一行代码搞定
    int subtractProductAndSum3(int n, int sup = 1, int sum = 0) {
        return n ? subtractProductAndSum3(n / 10, n % 10 * sup, sum + n % 10) : sup - sum;
    }

    // 使用for循环实现的版本
    int subtractProductAndSum4(int n) {
        int mul = 1, sum = 0;
        for (int cur; n > 0; mul *= cur, sum += cur, n /= 10) {
            cur = n % 10;
        }
        return mul - sum;
    }
};

int main() {
    int n = 4421;
    int res = Solution().subtractProductAndSum3(n);
    cout << res << endl;

    return 0;
}

/**
 * @brief leetcode官方题解
 * 方法一：模拟
思路与算法

我们只需要依次取出数字 n 中的各位数字，
并计算各个数字的乘积 m 以及数字和 s，
最后返回 m−s 即可。

我们可以依次取出 n 的最低位来得到 n 的各位数字：

- 通过「取模」操作 n mod 10得到此时 n 的最低位。
- 通过「整除」操作 n=⌊n/10⌋来去掉当前 n 的最低位。

复杂度分析

时间复杂度：O(log⁡n)，其中 n为题目给定的数字。
空间复杂度：O(1)，仅使用常量空间。
 */