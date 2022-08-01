/**
 * @file HJ_string_separation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * HJ4 字符串分隔
 * 描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述：
连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串

示例1

输入：
abc


输出：
abc00000
 */

// #include <string>
// #include <stdlib>
// #include <vector>


// 方法1：递归处理
// #include <iostream>
// #include <string>
// using namespace std;

// void func(string str) {
//     // 先处理最后的末尾字符
//     if (str == "") {
//         return;
//     }
//     if (str.size() <= 8) {
//         str.append(8 - str.size(), '0');
//         cout << str << endl;
//         return;
//     }
//     cout << str.substr(0, 8) << endl;
//     func(str.substr(8, str.size()));
// }

// int main() {
//     string str1;
//     cin >> str1;
//     func(str1);
//     // func(str2);
//     return 0;
// }

// 方法2：模拟
// #include <iostream>

// using namespace std;

// int main() { 
//     string str; 

//     while (getline(cin, str)) {
//         while(str.size() > 8) {
//             cout << str.substr(0, 8) << endl;
//             str = str.substr(8);
//         }
//         cout << str.append(8 - str.size(), '0') << endl;
//     }
//     return 0;
// }

// 方法3: 先补0，然后每隔8个字符输出打印
#include <bits/stdc++.h>

using namespace std;

int main() { string str; 
    while (cin >> str) {
        // 补0
        int len = str.size();
        if (len % 8 != 0) {
            int count = 8 - len % 8;
            str.append(count, '0');
        }

        // 按格式输出
        int newLen = str.size();
        for (int i = 0; i < newLen; i += 8) {
            cout << str.substr(i, 8) << endl;
        }
    }
    return 0;
}

/**
 * @brief 
 * 方法1：按题意模拟
 * 使用字符串函数substr截取，以长度为8递归处理
 * 运行时间：4ms
超过15.23% 用C++提交的代码
占用内存：460KB
超过34.23%用C++提交的代码

方法2：模拟
运行时间：4ms
超过15.20% 用C++提交的代码
占用内存：400KB
超过98.46%用C++提交的代码

方法3：
先对不为8的倍数的字符串结尾补0，使其刚好为8的倍数。
然后每隔8个字符输出并打印换行符。

运行时间：4ms
超过15.20% 用C++提交的代码
占用内存：512KB
超过11.41%用C++提交的代码

 */