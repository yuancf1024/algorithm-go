/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 实验数据
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小昱做了很久的实验得到了一个用正整数表示的实验数据，
并记录在了纸上。但是由于做完实验太过激动，
他一不小心把墨水打翻溅在了纸上，
导致数据中一些位置上的数字看不清楚。
他仍记得这个数据有以下三个特征：

1. 这个数是正整数，且没有前导零（即数的最高位不是0）

2. 这个数任意两个相邻数位的数字不同

3. 这个数可以被3整除

他现在很关心在满足以上特征的条件下，
这个数字最小为多少。

输入描述
输入一个由数字0-9和‘?’构成的字符串。
若输入的第i个字符为问号，
则表示数据从高位往低位数的第i位被墨水遮盖，
不能确定是哪个数字；否则，表示这一位未被墨水遮盖，
是一个确定的数。

输出描述
输出一个正整数，表示实验数据最小可能是多少。 

样例输入
?12?0?9??

样例输出
212101902

提示
输入的字符串长度不超过100000，且至少为1。

所有数据均保证合法，保证存在合法解，
且至少含有1个‘?’。

最高位为‘?’表示最高位被遮挡无法确定。
因为第一条特征限制，最高位不能为0。
因为第二位为1，根据第二条限制，最高位不能为1。
所以最高位只能是2到9中的任意一个数字，
当最高位为2时，实验数据会最小。
第4、6、8、9位数字也被墨水遮挡，
当第4、6位为数字1，
第8位为数字为0，
第9位为数字2时满足小昱记忆中数据的特征，
且是可能出现的最小值。
 */

/*
Pass 45%
末尾增加判断条件 Pass 55%
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    string str;
    cin >> str;
    if (str[0] == '?') {
        if (str[1] == '1') {
            str[0] = '2';
        }
        else {
            str[0] = '1';
        }
    }

    for (int i = 1; i < str.size()-1; ++i) {
        if (str[i] == '?' ) {
            if (str[i-1] != '0' && str[i+1] != '0') {
                str[i] = '0';
            }
            else if (str[i-1] != '1' && str[i+1] != '1') {
                str[i] = '1';
            }
            else if (str[i-1] != '2' && str[i+1] != '2'){
                str[i] = '2';
            }
        }
    }
    int a = str.size() - 1;
    if (str[a] == '?') {
        if (str[a-1] != '0') {
            str[a] = '0';
        } else {
            str[a] = '1';
        }
    }

    // cout << str << endl;
    ll res = stoi(str);
    while (res % 3 != 0) {
        if (str[a]+1 != str[a-1]) {
            res++;
        }
        else {
            res += 2;
        }
    }
    cout << res << endl;

    return 0;
}
    // for (int i = 1; i < str.size()-1; ++i) {
    //     int t = 0;
    //     if (str[i] == '?') {
    //         while (char(t) == str[i-1] || char(t) == str[i+1]) {
    //             t++;
    //         }
    //         str[i] = char(t);
    //     }
    // }

    // int a = str.size() - 1;
    // if (str[a] == '?') {
    //     int t = 0;
    //     while (str[a] == char(t)) {
    //         t++;
    //     }
    //     str[a] = char(t);
    // }
    // cout << str << endl;
    // ll res = 0;
    // for (int i = 0; i < str.size() ; ++i) {
    //     res += (str[i] - '0') * pow(10,str.size()-i);
    // }
    // while (res % 3 != 0) {
    //     res++;
    // }
        
