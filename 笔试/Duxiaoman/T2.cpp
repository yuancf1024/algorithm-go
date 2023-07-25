/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 积雪 20分
时间限制： 3000MS
内存限制： 589824KB
题目描述：
在水平的大地上常常下雪。
地面从西向东用一条水平坐标轴表示，
每次下雪时，会使得一段连续的地面上
[ l, r )产生深度为1的积雪。
在下过很多场雪后，你想知道积雪深度
至少达到h的地面总长度。

输入描述
输入两个整数n,h(1≤n,h≤10^5)表示有n场雪，
要求深度大于等于h的地面总长度。

然后输入n行，每行包含两个整数l,r(0≤l＜r≤10^5)
表示下雪的位置。

输出描述

输出一个整数S，表示积雪达到h的地面总长度。

样例输入

5 3
1 10
0 4
3 4
4 8
7 10

样例输出
2

超时 TLE

所有测试数据正确率为 73%！


 */

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n, h;
    cin >> n >> h;
    int min1 = 0, max1 = 0;
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; ++i) {
        cin >> left[i] >> right[i];
    }

    min1 = *min_element(left.begin(), left.end());
    max1 = *max_element(right.begin(), right.end());
    // 核心代码
    
    int count = 0;
    for (int i = min1; i < max1; ++i) {
        int res = 0;
        for (int j = 0; j < n; ++j) {
            if (i >= left[j] && i <right[j]) {
                res++;
            }
            if (res == h) {
                count++;
                break;
            }
        }
        
    }

    cout << count << endl;
    return 0;
}