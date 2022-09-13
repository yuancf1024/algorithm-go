/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 3 计算字符串重新排列数
 * 给定一个只包含大写英文字母的字符串S，要求你给出对S重新排列的
 * 所有不相同的排列数

样例1：
ABA
3

样例2：
ABCDEFGHHA
907200

样例3：
AABBCC
90

 */

/*
思路：回溯
包含重复元素的排列
可参考代码随想录

Pass 97% 未通过用例超出内存限制

可以啦
考试能过97%也能过笔试，拿到面试机会

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> res;
    vector<char> path;
    vector<vector<char>> permuteUnique(vector<char>& nums) { 
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    // 回溯递归函数
    void backtracking(vector<char>& nums, vector<bool>& used) {
        // 找到一组排列结果 直接返回
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // used[i-1] == false,说明同一树枝nums[i-1]使用过
            // used[i-1] == true,说明同一树层nums[i-1]使用过
            // 如果同一树层nums[i-1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true; // 将数字nums[i]标记已访问
                path.push_back(nums[i]);
                backtracking(nums, used); // 递归
                path.pop_back(); // 回溯
                used[i] = false;
            }
        }
    }
};

int main() { 
    string s;
    cin >> s;
    vector<char> nums;
    for (auto& x : s) {
        nums.push_back(x);
    }

    // 核心代码
    vector<vector<char>> res;
    Solution solution;
    res = solution.permuteUnique(nums);
    cout << res.size() << endl;
    return 0;
}