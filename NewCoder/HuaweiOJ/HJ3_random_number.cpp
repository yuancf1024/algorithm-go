/**
 * @file HJ3_random_number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022

HJ3 明明的随机数

描述

明明生成了N个1到500之间的随机整数。请你删去其中重复的数字，
即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，
按照排好的顺序输出。

数据范围：1≤n≤1000  ，输入的数字大小满足 1≤val≤500 

输入描述：

第一行先输入随机整数的个数 N 。 
接下来的 N 行每行输入一个整数，代表明明生成的随机数。 
具体格式可以参考下面的"示例"。

输出描述：
输出多行，表示输入数据处理后的结果

示例1

输入：
3
2
2
1

输出：
1
2

说明：

输入解释：
第一个数字是3，也即这个小样例的N=3，说明用计算机生成了3个1到500之间
的随机整数，接下来每行一个随机数字，共3行，也即这3个随机数字为：
2
2
1

所以样例的输出为：
1
2       
 */

// 方法1：自己实现 使用STL迭代器
// #include<bits/stdc++.h>

// using namespace std;

// int main() { 
//     int N;
//     // int nums[1000];
//     // cin >> N;
//     // while (N--) {
//     //     cin >> nums[1000 - N];
//     // }
//     // cout << sizeof(nums)/sizeof(nums[0]) << endl;
//     vector<int> nums;
//     int temp;
//     cin >> N;
//     while (N--) {
//         cin >> temp;
//         nums.push_back(temp);
//     }

//     // 核心代码
//     sort(nums.begin(), nums.end());
//     vector<int>::iterator it;
//     for (it = nums.begin(); it != nums.end(); it++) {
//         if (*it != *(it-1)) {
//             cout << *it << endl;
//         }
//     } 
//     return 0;
// }

// 方法2：参考@挥着牛鞭的男孩
// 类似桶排序
// #include <iostream>

// using namespace std;

// int main() { int N, n; 
//     while (cin >> N) {
//         int a[1001] = {0};
//         while (N--) {
//             cin >> n;
//             a[n] = 1;
//         }
//         for (int i = 0; i < 1001; i++) {
//             if (a[i]) {
//                 cout << i << endl;
//             }
//         } 
//     }
//     return 0;
// }

// 方法3：set去重
#include <bits/stdc++.h>

using namespace std;

int main() { int loop = 0; 
    while (cin >> loop) {
        int a[1001], tem, i = 0;
        for (int i = 0; i < loop; i++) {
            cin >> a[i];
        }
        set<int> num(a, a + loop);
        for (set<int>::iterator it = num.begin(); it != num.end(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}

/*
思路：
方法1：对输入的数组进行排序，对排好序的数组中重复的数字选择性的输出第一个

运行时间：5ms
超过1.56% 用C++提交的代码
占用内存：408KB
超过91.57%用C++提交的代码

方法2：以数组下标来存随机数，下标对应的数组值为1，来说明是否是存储的随机数
同时间接的去重

运行时间：4ms
超过20.76% 用C++提交的代码
占用内存：408KB
超过91.58%用C++提交的代码

方法3：使用STL set容器完成去重

运行时间：4ms
超过20.76% 用C++提交的代码
占用内存：484KB
超过14.46%用C++提交的代码

*/