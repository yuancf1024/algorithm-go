/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 环形子序列最大和 25分
 * 
 * 给一个整数数字串{a1,a2,a3...,an}将其首尾相连，
 * 组成一个环形，它的子序列是指这个数组连续的一段，
 * 比如a3,a4...,ai或者ai..an,a1,a2.
 * 请从这个环上选取两个不重叠的非空子序列，
 * 使这两个子序列中的所有数字之和最大。
 * 
输入描述：
输入的第一行是一个正整数n(2<=n<=50000),
第二行是用空格隔开的数组A的n个数，
依次为a1,a2,a3,...an (|ai|<=20000)

输出描述：
每组数据输出一行，包含一个数，
即所求的这两个子序列之和。


示例1：
3
1 -1 0

1
示例2：
4
1 -1 1 -1

2

示例3：
5
1 -1 1 -1 1

3
 */

#include <bits/stdc++.h>

using namespace std;

int findLongestMax(vector<int>& nums) {
    int sum = 0;
    for (auto& x : nums) {
        sum += x;
    }
    int curmax = 0;
    int totalmax = 0;
    for (int i = 1; i < nums.size(); ++i) {
        curmax = max(curmax + nums[i], nums[i]);
        totalmax = max(curmax, totalmax);
    }
    int totalmin = nums[1];
    int curmin = nums[1];
    if (nums.size() > 2) {

        for (int i = 2; i < nums.size() - 1; ++i) {
            curmin = min(curmin + nums[i], nums[i]);
            totalmin = min(curmin, totalmin);
        }
    }
    return max(sum - totalmin, totalmax);
}

int main() { int n;
    cin >> n;
    vector<int> nums;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums.push_back(t);
    }

    // TODO

    int res = findLongestMax(nums);
    cout << res << endl;
    /*贪心：分两次找到最大环形连续子序和
     */

    return 0;
}