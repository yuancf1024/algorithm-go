/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 比大小 10分
 * 
小吉和小雷发现了两个数，但是两个数字是不同进制的，
他们想知道谁的数字更大。

输入描述：

第一行分别输入两个数字的长度和进制len1, k1,len2,k2
0<len1, len2<=9
2<=k1,k2<=9


之后两行输入两个数字n，m
0<n,m<2147483647

输出描述：
如果第一个数小输出"<",
如果第一个数大输出">",
如果两个数相等输出"=".

示例1：
3 7 3 8
222
222

<
 */

/*
1. 用例通过40%
*/

#include <bits/stdc++.h>

using namespace std;

// 将N进制转换为10进制
long Ntansform10(string s, int k) { 
    long t1 = 0, t;
    int l = sizeof(s);
    for (int i = 0; i < l; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            t = s[i] - '0';
        }
        t1 = t1 * k + t;
    }
    return t1;
}

int main() { 
    int len1, k1, len2, k2;
    cin >> len1 >> k1 >> len2 >> k2;

    // TODO
    string s1, s2;
    cin >> s1;
    cin >> s2;

    long a1 = Ntansform10(s1, k1);
    long a2 = Ntansform10(s2, k2);
    if (a1 > a1) {
        cout << '>' << endl;
    } 
    else if (a1 < a2) {
        cout << '<' << endl;
    }
    else {
        cout << '=' << endl;
    }

    return 0;
}