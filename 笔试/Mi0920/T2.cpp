/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * 米小兔的英语考试
时间限制： 3000MS
内存限制： 589824KB
题目描述：

老师发给米小兔一串排列好的卡片，
每个卡片上都有一个英文字母，组成的字符串为s。
老师要求，米小兔可以通过增加卡片、抽出卡片、
替换卡片的方式（26个英文字母均可替换），
将卡片排列成目标字符串t。
你能算一算，米小兔最少需要操作几次吗？

输入描述

字符串s和字符串t

输出描述
操作次数

样例输入
"horse"
"ros"

样例输出
3

提示
字符串s和t的长度<=500

且字符串s和t均由小写英文字母组成
 */

/*
AC 50%
*/

#include <bits/stdc++.h>

using namespace std;

int main() { string s, t;
    cin >> s;
    cin >> t;
    // 核心代码

    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(510, vector<int>(510));

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i-1] == t[i-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] =
                    min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;

            }
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}