/**
 * @file 47.Permutations-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 47. 全排列 II
给定一个可包含重复数字的序列 nums ，
按任意顺序 返回所有不重复的全排列。

示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

提示：
1 <= nums.length <= 8
-10 <= nums[i] <= 10
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) { 
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    // 回溯递归函数
    void backtracking(vector<int>& nums, vector<bool>& used) {
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