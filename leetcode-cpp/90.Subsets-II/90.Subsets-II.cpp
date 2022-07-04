/* 90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，
请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
 
提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // used[i-1] == true, 说明同一树枝candidates[i-1]使用过
            // used[i-1] == false, 说明同一树层candidates[i-1]使用过
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true; // 标记为数枝中已使用
            backtracking(nums, i + 1, used);
            used[i] = false; // 回溯
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) { 
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0, used);
        return result;
    }
};

/*
回溯算法的模板
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择: 本层集合中元素(树中节点孩子的数量就是集合的大小)) {
        处理节点;
        backtracking(路径, 选择列表); // 递归
        回溯, 撤销处理结果
    }
}

要清楚子集问题和组合问题、分割问题的的区别，
- 子集是收集树形结构中树的所有节点的结果。
- 而组合问题、分割问题是收集树形结构中叶子节点的结果。

这道题目和78.子集 (opens new window)区别就是集合里有重复元素了，而且求取的子集要去重。

那么关于回溯算法中的去重问题，在40.组合总和II (opens new window)中已经详细讲解过了，和本题是一个套路。

剧透一下，后期要讲解的排列问题里去重也是这个套路，所以理解“树层去重”和“树枝去重”非常重要。
*/