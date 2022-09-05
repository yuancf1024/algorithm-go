/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * 米小游的史莱姆消除
 * 
米小游有n只史莱姆拍成一排，她可以选择一些史莱姆进行消除。
消除规则如下：
1. 选择两只相邻的史莱姆。
2. 选择的两只史莱姆，如果其中一只是火史莱姆，
另一只是水史莱姆，那么可以将两只史莱姆消除。
3. 消除了两只史莱姆后，右边的史莱姆会往左填补空隙。
4. 岩史莱姆不参与消除。

米小游用字符'f'表示火史莱姆(fire),
's'表示岩史莱姆(stone),
'w'表示水史莱姆(water).
也就是说，米小游可以删除"fw"子串和"wf"子串。

输入描述：
一个长度不超过200000，仅由'f','w','s'三种字符组成的字符串

输出描述：
一个整数，代表米小游可以消除最多史莱姆数量。

示例1：
sswfwsf

2
 */

/*
用例通过率25%

说明还有哪些边界情况没有考虑到

会是哪里没有考虑到呢？

2022-09-05复盘
要考虑消除之后，后面的那个能不能和前面的一个继续消除，用栈清晰明了。
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;

    // 核心代码
    ll n = s.length();
    ll res = 0;
    for (ll i = 0; i < n - 1; i+=2) {
        if ((s[i] == 'f' && s[i+1] == 'w') || (s[i] == 'w' && s[i+1] == 'f')) {
            
            res += 2;
        }
    }

    cout << res << endl;
    return 0;
}