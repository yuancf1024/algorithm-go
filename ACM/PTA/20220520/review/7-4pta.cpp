/* 7-4 关于奇数的等式
给定任一正奇数 n>3 和一个解的上界 m>3，求三个正奇数 x、y、z，
满足 0<x<y<z≤m 且有等式 3/n=1/x+1/y+1/z。

输入格式：
输入给出正奇数 3<n<400 和解的上界 m≤1000。

输出格式：
在一行中输出给定范围内最小的一组解 x y z
（即存在多组解时取最小的 x，并列时取最小的 y）。
数字间以 1 个空格分隔，行首尾不得有多余空格。

如果给定范围内无解，则输出 No solution in (3, m]. 
其中 m 是给定的上界。

输入样例 1：
27 500

输出样例 1：
11 55 495

输入样例 2：
27 50

输出样例 2：
No solution in (3, 50].

*/

/*
题目分析/解题思路

暴力枚举 x, y, z 的话我们的时间复杂度为 O（m^3/8)，
这个时间复杂度有些紧张，我们考虑变换原式来降低时间复杂度。

3/n = 1/x + 1/y + 1/z
3xyz = n(xy + yz + xz)
3xyz - n(x + y)z = nxy
z = nxy / (3xy - n(x+y))

所以我们可以发现我们只需要枚举前两个数即可，
现在算法的时间复杂度为O（m^2/4)。

*/

#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> f(int n, int m) { 
    for (int i = 1; i <= m; i += 2) {
        for (int j = i + 2; j <= m; j += 2) {
            int x = i * j * n;
            int y = 3 * i * j - n * (i + j);
            if (x % y)
                continue;
            int k = x / y;
            if (k > m or k <= j)
                continue;
            return {i, j, k};
        }
    }
    return {0, 0, 0};
}

int main() { 
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    auto [x, y, z] = f(n, m); // structured bindings only available with ‘-std=c++17’ or ‘-std=gnu++17’
    if (x > 0)
        cout << x << ' ' << y << ' ' << z << '\n';
    else
        cout << "No solution in (3, " << m << "].\n";
    return 0;
}