/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 二进制位运算
 * 
 * Python有位运算，是直接将数字看成二进制，
 * 直接对二进制的每一位进行运算。
 * 现输入两个十进制整数x、y，
 * 请计算它们的位与、位或，输出按照十进制的形式
 * 
输入描述：
一行输入两个整数x，y，以空格间隔
输出描述：
第一行输出x位与y
第二行输出x位或y

输入：
1 2
输出
0
3
 */

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int x, y;
    cin >> x >> y;

    cout << (x & y) << endl;
    cout << (x | y) << endl;

    return 0;
}