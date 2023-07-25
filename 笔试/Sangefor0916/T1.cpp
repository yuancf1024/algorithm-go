/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * 最大公约数 10分
 * 
 * 假设有正整数a和b，范围是[1,100000]
 * 求a与b的最大公约数
 * 现在给定a与b，输出其最大公约数
 * 
输入描述：
数据只有一行，2个正整数

输出描述:
输出结果位正整数

示例1：
12 16
4

 */

/*
2022-09-16晚 复盘
思路：
要求最小公约数，可以采用遍历的方式，
只要满足该数可同时被a、b整除即可。

*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int a, b;
    cin >> a >> b;

    // 核心代码
    int i = a > b ? b : a;
    for (i; i >= 1; i--) {
        if ((a%i) == 0 && (b%i) == 0) {
            break;
        }
    }
    cout << i << endl;
    return 0;
}