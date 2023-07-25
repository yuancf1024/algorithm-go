/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小红的孤独数
 * 
 * 小红拿到了一个数组，她每次可以选择一个数使其加k。
 * 小红希望数组中的每个数都和其他元素不同，
 * 她想知道最小的操作次数是多少?
 * 
输入描述：
第一行输入两个正整数n和k，用空格隔开。
第二行输入n个正整数ai，用空格隔开。
1<=n,k,ai<=10^5

输出描述：
一个整数，代表最小的操作次数。

示例1：
5 2
2 3 1 3 4

1
 */

/*
用集合超时：Pass 20%

*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 核心代码
    int res = 0;
    /*
    思路：用无序集合
    */
    unordered_set<int> set;

    for (int i = 0; i < n; ++i) {
        if (!set.count(a[i])) {
            set.insert(a[i]);
        } else {
            while (set.count(a[i])) {
                res++;
                a[i] += k;
            }
            set.insert(a[i]);
        }
    }

    // 用哈希表
    // unordered_map<int, int> map;
    // for (int i = 0; i < n; ++i) {
    //     map[a[i]]++;
    // }

    // for (auto it = map.begin(); it != map.end(); it++) {
    //     if (it->second > 1) {
            
    //     }
    // }
    cout << res << endl;

    // for (auto& x : a) {
    //     cout << x << " ";
    // }
    return 0;
}