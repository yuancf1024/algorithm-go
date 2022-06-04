/* 7-1 520表白
在 520 这个日子里，拼题 A 请你实现一个小功能，帮助用户向自己喜欢的数字表白。

输入格式：
输入在一行中给出一个不超过 1000 的正整数 N，是用户最喜欢的一个数字。

输出格式：
在一行中按以下格式输出对 N 的表白：

N! 520!
*/
/*
input:
233

output:
233! 520!

*/

#include <bits/stdc++.h>
using namespace std;

int main() { 
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    cout << n << "! "
         << "520!" << '\n';
    return 0;
}