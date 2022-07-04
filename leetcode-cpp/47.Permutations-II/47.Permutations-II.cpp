/* 47. 全排列 II
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

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // used[i-1] == true, 说明同一数枝nums[i-1]使用过
            // used[i-1] == false, 说明同一数层nums[i-1]使用过
            // 如果同一数层nums[i-1]使用过则跳过
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) { 
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

/*
回溯算法的3个关键点
1. 回溯函数模板返回值以及参数
2. 回溯函数终止条件
3. 回溯搜索的遍历过程

- 回溯模板
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

这道题目和46.全排列的区别在与给定一个可包含重复数字的序列，
要返回所有不重复的全排列。

还要强调的是去重一定要对元素进行排序，这样我们才方便通过相邻的节点来
判断是否重复使用了。

我们对同一树层，前一位（也就是nums[i-1]）如果使用过，那么就进行去重。

一般来说：组合问题和排列问题是在树形结构的叶子节点上收集结果，
而子集问题就是取树上所有节点的结果。

*/