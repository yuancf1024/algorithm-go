/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 小红的01串构造 20分
 * 
 * 小红希望你构造一个长度n的01串，其中恰好有k个1，
 * 且恰好有t对相邻字符都是1.
 * 
输入描述：
三个正整数n,k,t 空格隔开
1<=n<=10^5
0<=k,t<=n

输出描述：
如果无法完成构造，输出-1
否则，输出任意一个满足的01串即可

Test Case1：

3 2 1

110

3 2 2

-1

 */

/*
全部输出-1：通过率12.5%


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    // 核心代码
    // 长度为n
    // 1的数量为k
    // 相邻字符都是1 为t
    string s = "";
    if (k >= t*2) {
        
        for (int i = 0; i < t; ++i) {
            s += "11";
        }
        for (int j = 0; j < (k - 2 * t); ++j) {
            s += "01";
        }
        for (int x = 0; x < (n - 2 * k + 2 * t); ++x) {
            s += '0';
        }
    } else {
        cout << -1 << endl;
    }

    cout << s << endl;
    return 0;
}