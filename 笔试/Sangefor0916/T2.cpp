/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * 病毒闯关记 12分
 *  
 * 
 * 
输入描述：
给定正整数n和x，分别表示主机数和主机的辨识精确度
接下来n个正整数a[i]分别表示n个主机的辨识度

输出描述：
输出一个整数，表示小绿最少需要变化多少次伪装度，
才能入侵n个主机

示例1：
输入
5 4
4 9 6 7 8

输出
0

数据范围
1<=n<=100000
1<=a[i]，x <1000000000
 */

/*
2022-09-16晚 复盘

思路：大佬的思路是贪心

贪心，把每一个数变成一个区间，然后维护一个最小区间，
最小区间变化了几次，就是答案

*/

// 容易理解的贪心版本 
#include <bits/stdc++.h>

using namespace std;

int a[100100];

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = a[0] - x, r = a[0] + x, cnt = 0;
    for (int i = 0; i < n;++i) {
        if (a[i] >= l-x && a[i] <= r+x) { // ?
            if (a[i]+x <= r) { // 更新r
                r = a[i] + x;
            }
            if (a[i]-x >= l) { // 更新l
                l = a[i] - x;
            }
        }
        else { // a[i]的值超出范围了，小绿需要变化v a[i]+x >=r || a[i]-x<=l
            cnt++;
            l = a[i] - x, r = a[i] + x;
        }
    }
    cout << cnt;
    return 0;
}

// // 大佬的贪心实现 不太好理解
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> v(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> v[i];
//     }
//     // 核心代码
//     int ans = 0;
//     for (int i = 0; i < n; ++i) {
//         int m = v[i], M = v[i];
//         int j = i;
//         while (j+1 < n && max(M, v[j+1]) - min(m, v[j+1]) <= 2*k) {
//             M = max(M, v[++j]);
//             m = min(m, v[j]);
//         }
//         if (j < n-1) {
//             ans++;
//         }
//         i = j;
//     }
//     cout << ans << endl;
//     return 0;
// }

// // 我的垃圾代码
// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// int main() {
//     int n;
//     ll x;
//     ll sum=0;
//     cin >> n;
//     cin >> x;
//     vector<ll> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//         sum += a[i];
//     }

//     // 核心代码
//     ll res = 0;
//     // 初始伪装度 为数组的平均值
//     ll v = sum / n;

//     ll count = 0;
//     // 统计超出范围的次数
//     for (int i = 0; i < n; ++i) {
//         if ((a[i] > v+x) && (a[i] < v-x)) {
//             res++;
//             v = a[i];
//         }
//     }
//     cout << res << endl;
//     return 0;
// }