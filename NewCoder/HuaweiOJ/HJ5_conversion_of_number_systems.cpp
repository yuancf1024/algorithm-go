/**
 * @file HJ5_conversion_of_number_systems.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * HJ5 进制转换
 * 描述
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

数据范围：保证结果在 1≤n≤2^31−1 

输入描述：

输入一个十六进制的数值字符串。

输出描述：

输出该数值的十进制字符串。不同组的测试用例用\n隔开。

示例1

输入：
0xAA


输出：
170
 */

// 方法1：利用C++特殊函数
// #include <bits/stdc++.h>

// using namespace std;

// int main() { 
//     // int a, b;
//     int a;
//     // cin >> hex >> a; // 将输入的数a转换为16进制
//     // cout << a << endl; // a被表示成了16进制，这里以再转换成10进制输出
//     while (cin >> hex >> a) {
//         cout << a << endl;
//     }
//     return 0;
// }

/*
C++输出十六进制是cout << hex<<< a;
而八进制是cout << oct << a;
*/

// 方法2：将十六进制转换成十进制
#include <bits/stdc++.h>

using namespace std;

int main() { 
    char str[101];
    int i = 0, count, sum;
    while (gets(str)) { // 用于多次输入
        count = strlen(str); // 计算字符串的长度
        sum = 0;
        for (i = count - 1; i >= 0; i--) { // 从十六进制个位开始，每位都转换成十进制
            if (str[i] >= '0' && str[i] <+ '9') { // 数字字符转换
                sum += (str[i] - 48) * pow(16, count - i - 1);
            }
            else if (str[i] >= 'A' && str[i] <= 'F') { // 字母字符转换
                sum += (str[i] - 55) * pow(16, count - i - 1); // A对应ascii的65，但是这里A对应10，所以减去55
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

/**
 * @brief 思路
 * 方法1：利用C++特殊函数
 * 运行时间：4ms
超过10.27% 用C++提交的代码
占用内存：452KB
超过36.20%用C++提交的代码

 * 方法2：将字符串转换成十进制的数，程序就能通过，
 看来题目的目的只是将十六进制转换成十进制
运行时间：4ms
超过10.28% 用C++提交的代码
占用内存：456KB
超过32.35%用C++提交的代码
 */