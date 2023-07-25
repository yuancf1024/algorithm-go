/**
 * @file T1_architecture.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-01
 * 
 * @copyright Copyright (c) 2022
 * B站后端基础架构方向笔试编程题
 * 
 * 一个自然数可以分解为若干个自然数相乘，对于指定自然数n；
 * 请求每种分解自然数之和最小的一个。
 * 说明：不考虑1，若是素数，则是它本身
 * 例子：如6=2*3，或是它本身，则2+3最小
 * 
 */

/*
TestCae1：
6

5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        dp[i] = i;
    }
    for (int i = 2; i < dp.size(); ++i) {
        for (int j = i / 2; j >= 1; --j) { // 
            if (i % j == 0) {
                dp[i] = min(dp[i], j + dp[i / j]); // j * (i/j)等于 i 这里很巧妙
            }
        }
    }
    cout << dp[dp.size() - 1];
    return 0;
}