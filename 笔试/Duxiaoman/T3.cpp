/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * P型回文串 20分
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小明和小红都很喜欢收集字符串。
小明喜欢收集周期为P的字符串，小红喜欢收集回文串。
当一个回文串的周期为P时，我们称它为“P型回文串”。

现在给你一个长度为P的整数倍的字符串，
请问你最少改变几个字符能将它变成一个P型回文串？

一个字符串的周期为P，当且仅当字符串中任意两个距离
之差为P的位置上的字符均相等。

一个字符串是回文串，当且仅当字符串前后翻转后与原串相等。

输入描述
本题采用多组数据测试，
第一行有一个整数t,代表测试数据组数。

接下来每组数据中：

第一行有两个整数n,p(1≤p≤n≤2x10^5)分别
代表字符串长度与P的大小，n是p的整数倍。

第二行有一个长度为n的字符串s，s中均为小写字母。

输出描述
对于每组数据输出一行，表示能达到要求的
最少改变字符的次数。


样例输入
2
6 2
cdccdc
6 3
zpzzpz

样例输出
2
0
 */

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int t;
    cin >> t;

    while (t>0) {
        t--;
        string s;
        int n, p;
        cin >> n >> p;
        cin >> s;
        // 核心代码
        int res = 0;

        cout << res << endl;
    }
    return 0;
}