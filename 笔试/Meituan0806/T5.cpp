/**
 * @file T5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
第五题
题目：
初始字符串为MeiTuan，每次对字符串做 str = str + str.reverse() + "wow"
的操作，无限循环。后面给你一个k，问你位置k的字符为什么。

将字符串s丢入机器后则输出新字符串s+reverse(s)+"wow"。
初始字符串为"MeiTuan"，不停的反复将新字符串丢入机器，
求得到的无限长字符串的第k位字母（1 ≤ k ≤ 1e18）

思路

找规律
无限循环后 是 str+str.reverse()+"wowwow"的无限循环


理解：
先枚举几个，再找规律
1 MeiTuan
2 MeiTuannauTieMwow
3 MeiTuannauTieMwowwow MeiTuannauTieMwow

 */

#include <bits/stdc++.h>

using namespace std;

int main() { int k;
    cin >> k;
    /*
    找规律无限循环后 是 str+str.reverse()+"wowwow"的无限循环
    MeiTuannauTieMwowwow 20个字符
    */
    string str = "MeiTuannauTieMwowwow";
    cout << str.size() << endl;
    cout << str[(k-1) % 20] << endl;
    // while () {

    // }
}