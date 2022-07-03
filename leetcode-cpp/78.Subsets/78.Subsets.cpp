/* 78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。
返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：
输入：nums = [0]
输出：[[],[0]]

*/

class Solution {
private:
    vector<vector<int>> result; // 二维数组result存放子集组合
    vector<int> path; // 全局变量数组path为子集收集元素
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path); // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startIndex >= nums.size()) { // 终止条件可以不加
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) { 
        result.clear();
        path.clear();
        backtracking(nums, 0);
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
*/