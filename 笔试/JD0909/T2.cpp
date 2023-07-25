/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小红的数染色方案 20分
 * 
 * 小红拿到了一个长度为n的数组。
 * 
 * 她希望把一些数(不少于2个数)染红，
 * 满足任意两个染红的数之和都是偶数。
 * 
 * 小红想知道，一共有多少种不同的染色方案？
 * 答案对10^9+7取模。
 * 
 * 我们认为，对于两个方案，只要存在某个数的
 * 染色情况不同，则认为是两种不同的方案。
 * 
输入描述：
第一行输入一个正整数n，代表数组的长度。
第二行输入n个正整数ai，代表小红拿到的数组。
数据范围：2<=n<=10^5, 1<=ai<=10^9
输出描述：
输出一个整数，代表染色方案对10^9+7取模的值。

示例1：
5
1 2 5 2 8

5

 */

/*
程序运行有bug，函数subsets运行起来就停不下来了

*/


#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int findAll(vector<int>& nums) { 
//         int ans = 0; // 统计染色数量
        

//     }

//     // 辅函数
//     int backstracking(vector<int>& nums, int num) {
//         if (num == nums.size()) {

//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return res;
    }

    // 回溯函数
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i]==nums[i-1] && used[i-1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};

bool isOu(vector<int>& nums) { 
    int sum = 0; 
    for (auto& a : nums) {
        sum += a;
    }
    return !(sum % 2);
}

int main() {
    int n;
    vector<int> nums(n);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 核心代码
    // 思路：应该就是普通的回溯
    // 求出数组的所有子集
    // 统计子集元素数量大于1&&元素之和为偶数的数量
    Solution s;
    vector<vector<int>> sets;

    sets = s.subsets(nums);
    int res = 0;

    // 遍历统计
    for (auto& x : sets) {
        if (x.size() > 1 && isOu(x)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}