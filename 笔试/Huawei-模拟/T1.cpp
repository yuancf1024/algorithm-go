/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 1. Words
 * 计算整个句子的平均重量
 * 
样例1：
Who Love Solo
3.00
 */

/*
Pass 100%
*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    string s;
    getline(cin, s);

    // 核心代码
    int num = 1; // 统计单词个数
    int alpha = 0;
    for (auto& x : s) {
        if (x == ' ') {
            num++;
        }
        if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
            alpha++;
        }
    }
    float res = float(alpha) / float(num);
    printf("%.2f\n", res);
    // cout << num << " " << alpha;
    return 0;
}