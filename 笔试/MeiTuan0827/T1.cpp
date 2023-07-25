/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * 神奇字符
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小美在摆弄她的字符串。
最近小团送了小美一个特殊字符 ' * '，
这个字符可以和其他所有字符匹配，
除了这个字符外，其他字符只能自己和自己匹配。
小美先前有一个字符串S，长度为n，
现在她又新组合了一个可有特殊字符 ' * ' 的字符串s，
长度为m。

小美想知道有多少个位置 i，
使得S[i+j]与s[j]对于1≤j≤m均能匹配上？
其中X[y]代表字符串X中第y位的字符。

输入描述
第一行两个空格隔开的正整数n和m，
分别表示字符串S和字符串s的长度。

接下来一行长度为n的仅包含小写英文字母的字符串S

接下来一行长度为m的包含小写英文字母
以及特殊字符 ' * ' 的字符串s

对于所有数据，1≤m≤n≤2000

输出描述
输出一行一个整数，表示满足要求的位置数量

样例输入
7 3
abcaacc
a*c

样例输出
3

提示
可以对i=0,3,4这三个位置的子串
abc、aac、acc匹配上a*c，即

abcaacc

abcaacc

abcaacc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    string S, s;

    cin >> n >> m;

    cin >> S;
    cin >> s;

    // 核心代码
    // AC!
    int res = 0;

    for (int i = 0; i < n - m + 1; ++i) {
        int num = 0;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '*') {
                continue;
            }
            if (S[i+j] == s[j]) {
                num++;
            }
            if (num == m-1) {
                res++;
            }
        } 
    }

    cout << res << endl;

    // cout << n << " " << m << endl;

    // cout << S << " " << s << endl;
    return 0;
}