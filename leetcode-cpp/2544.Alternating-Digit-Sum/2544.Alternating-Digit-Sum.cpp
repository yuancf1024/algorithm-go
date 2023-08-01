/**
 * @file 2544.Alternating-Digit-Sum.cpp
 * @author your name (you@domain.com)
 * @brief 2544. 交替数字和
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个正整数n。n 中的每一位数字都会按下述规则分配一个符号：

- 最高有效位 上的数字分配到 正 号。
- 剩余每位上数字的符号都与其相邻数字相反。

返回所有数字及其对应符号的和。

示例 1：

输入：n = 521
输出：4
解释：(+5) + (-2) + (+1) = 4

示例 2：

输入：n = 111
输出：1
解释：(+1) + (-1) + (+1) = 1

示例 3：
输入：n = 886996
输出：0
解释：
(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0
 

提示：

1 <= n <= 10^9
 
 */

#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        while (n > 0) {
            ans += n % 10 * sign;
            sign = - sign;
            n /= 10;
        }

       return -sign * ans; 
    }
};

int main() {
    int num = 886996;
    int res = Solution().alternateDigitSum(num);

    cout << res << endl;

    return 0;
}

/**
 * @brief 官方题解leetcode-2544. 交替数字和
 * 
方法一：数学
思路与算法

给你一个正整数n，要求计算n的数字交替和。

我们用sign来表示数字的正负，并初始化为1。
每一步中，我们将n对10取模，得到个位数字，
把它和sign 相乘求和，将sign取相反数，
再把n除以10。不断重复这一步骤，直到n为零。
这样我们就得到了数字交替和。

最后，因为最高有效位上的数字分配到正号，
我们将结果乘以−sign 后返回。
 */