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
思路: 根据题目给出的等式做变换，通分后变成整数的等式。然后，
暴力匹配找到符合要求的（题目条件说明了是奇数所以只需要处理奇数）。
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    bool find = false;
    for (int x = 1; x <= m; x += 2) { //三层遍历，只处理奇数
        for (int y = x + 2; y <= m; y += 2) {
            for (int z = y + 2; z <= m; z += 2) {
                if (3 * x * y * z == n * (x * y + x * z + y * z)) {
                    // //如果满足要求，则输出并
                    cout << x << " " << y << " " << z;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        if (find) break;
    }
    if (!find) cout << "No solution in (3, " << m << "].";
    return 0;
}