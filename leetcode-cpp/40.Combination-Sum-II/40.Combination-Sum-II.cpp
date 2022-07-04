/* 40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 
提示:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

class Solution {
private:
    vector<vector<int>> result; // 存放组合集合
    vector<int> path; // 符合条件的组合
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum > target) { // 这个条件其实可以省略
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
                // used[i-1] == true, 说明同一数枝candidates[i-1]使用过
                // used[i-1] == false, 说明同一树层candidates[i-1]使用过
                // 要对同一数层使用过的元素进行跳过
                if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) {
                    continue;
                }
                sum += candidates[i];
                path.push_back(candidates[i]);
                used[i] = true;
                backtracking(candidates, target, sum, i + 1, used); // // 和39.组合总和的区别1：这里是i+1，每个数字在每个组合中只能使用一次
                used[i] = false; // 回溯
                sum -= candidates[i];
                path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同元素都挨在一起
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
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

这道题目和39.组合总和 (opens new window)如下区别：

本题candidates 中的每个数字在每个组合中只能使用一次。
本题数组candidates的元素是有重复的，而39.组合总和 (opens new window)是无重复元素的数组candidates

本题的难点在于区别2中：集合（数组candidates）有重复元素，但还不能有重复的组合。

一些同学可能想了：我把所有组合求出来，再用set或者map去重，这么做很容易超时！

所以要在搜索的过程中就去掉重复组合。

很多同学在去重的问题上想不明白，其实很多题解也没有讲清楚，反正代码是能过的，感觉是那么回事，稀里糊涂的先把题目过了。

这个去重为什么很难理解呢，所谓去重，其实就是使用过的元素不能重复选取。 这么一说好像很简单！

都知道组合问题可以抽象为树形结构，那么“使用过”在这个树形结构上是有两个维度的，一个维度是同一树枝上使用过，一个维度是同一树层上使用过。没有理解这两个层面上的“使用过” 是造成大家没有彻底理解去重的根本原因。

那么问题来了，我们是要同一树层上使用过，还是同一树枝上使用过呢？

回看一下题目，元素在同一个组合内是可以重复的，怎么重复都没事，但两个组合不能相同。

所以我们要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重。

为了理解去重我们来举一个例子，candidates = [1, 1, 2], target = 3，（方便起见candidates已经排序了）

强调一下，树层去重的话，需要对数组排序！
*/