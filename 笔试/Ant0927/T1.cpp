/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小红的排列构造 14分
 * 
 * 小红希望你构造一个排列，满足对于排列中的每一项ai
 * 都满足：ai+i均不是质数(下标i从1开始)
 * 
 * 长度为n的排列是指：一个长度为n的数组，
 * 其中1到n每个正整数恰好出现1次。
 * 例如：[2,1,3]是排列，而[1,3,4,3]不是排列
 * 
输入描述：
一个正整数n，代表待构造的排列长度
1<=n<=10^5

输出描述：
如果无法构造，则输出-1
否则输出一个长度为n的满足要求的排列。
有多解时输出任意即可。

示例1：
1

-1

示例2：
10

9 4 6 2 1 8 3 10 7 5

 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 核心代码
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {

    } 
    cout << -1 << endl;
    return 0;
}

