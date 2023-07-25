/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 牛牛的球 30分
 * 
 * 牛牛有一个半径为r的球，他想知道这个球的体积。
 * 球的体积公式是4/3*pi*r^3,pi取3.14，r是一个整数
 * 
输入：
输入球的半径
输出：
输出球的体积

示例1：

3

113.04

 */

// #include <bits/stdc++.h>

// using namespace std;

// int main() { 
//     double Pi = 3.14;
//     int r;
//     // scanf("%d\n", &r);
//     while (cin >> r) {
//         // cin >> r;
//         double area = (4 / 3) * Pi * r*r*r;
//         printf("%.2f\n", area);
//     }
//     return 0;
// }

/*
AC 100%
*/
#include <bits/stdc++.h>

using namespace std;

int main() { 
    double Pi = 3.14;
    int r;
    // scanf("%d\n", &r);
    while (cin >> r) {
        // cin >> r;
        // double area = (4 / 3) * Pi * r*r*r; // 这样写就有bug
        double area = (4  * Pi * r*r*r )/ 3;
        printf("%.2f\n", area);
    }
    return 0;
}