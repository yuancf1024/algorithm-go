/* 77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// 原始版本
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) { // 控制树的横向遍历
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1); // 递归: 控制树的纵向遍历，注意下一层搜索要从i+1开始
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) { 
        result.clear(); // 可以不写
        path.clear(); // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

/*
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
*/

// 剪枝优化的版本
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 剪枝优化的地方&控制树的横向遍历
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1); // 递归: 控制树的纵向遍历，注意下一层搜索要从i+1开始
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) { 
        result.clear(); // 可以不写
        path.clear(); // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

/*
分析剪枝过程：

接下来看一下优化过程如下：
1. 已经选择的元素个数：path.size();
2. 还需要的元素个数为: k - path.size();
3. 在集合n中至多要从该起始位置 : n - (k - path.size()) + 1，开始遍历

为什么有个+1呢，因为包括起始位置，我们要是一个左闭的集合。
举个例子，n = 4，k = 3， 目前已经选取的元素为0（path.size为0），
n - (k - 0) + 1 即 4 - ( 3 - 0) + 1 = 2。

从2开始搜索都是合理的，可以是组合[2, 3, 4]。
这里大家想不懂的话，建议也举一个例子，就知道是不是要+1了。
*/
