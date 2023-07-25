/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 分数最大的字符串 20分
时间限制： 3000MS
内存限制： 589824KB
题目描述：
定义一个字符串的分数为：

对于出现在子串中的字母，最大的出现次数和最小的出现次数的差值。

注意：只统计出现在子串中的字母。

例如对于串 abb而言，
a出现1次，b出现2次，因此分数为2-1=1

输入中将给出若干个字符串。
你的任务是求出分数最大的字符串的分数为多少。

字符串数量n <= 400, 每个字符串的长度 <= 1000

输入描述
第一行一个正整数n，表示接下来有n个字符串。

接下来n行，每行一个字符串。每个字符串仅包含小写字母。

输出描述
一行一个正整数描述分数最大的字符串分数。

样例输入

4
aab
abcd
cccc
abacad

样例输出
2

提示
四个字符串的分数分别是：
aab 分数为 1
abcd 分数为0 
cccc 分数为0 
abacad 分数为2

其中最大的是abacad为2

1. Pass 55%

2. 改成用新的vector统计map最大值和最小值后 AC
 */

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 核心代码
    vector<int> res;
    
    for (auto& s : nums) {
        unordered_map<char, int> map;
        int max1 = 0, min1 = 1;
        for (int i = 0; i < s.size(); ++i) {
            map[s[i]]++;
            // if (map[s[i]] >= max1) {
            //     max1 = map[s[i]];
            // }
            // if (map[s[i]] <= 1) {
            //     min1 = map[s[i]];
            // }
        }
        // 求最小和最大
        vector<int> a;
        for (auto& x : map) {
            a.push_back(x.second);
        }
        max1 = *max_element(a.begin(), a.end());
        min1 = *min_element(a.begin(), a.end());
        if (max1 == s.size()) {
            res.push_back(0);
        } else {
            res.push_back(max1 - min1);
        }
    }

    cout << *max_element(res.begin(), res.end());
    return 0;
}