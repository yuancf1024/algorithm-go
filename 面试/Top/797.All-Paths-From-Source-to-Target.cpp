/**
 * @file 797.All-Paths-From-Source-to-Target.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 给你一个有 n 个节点的 有向无环图（DAG），
 * 请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

 graph[i] 是一个从节点 i 可以访问的所有节点的列表
（即从节点 i 到节点 graph[i][j]存在一条有向边）。

示例 1：
输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

示例 2：
输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

提示：

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i（即不存在自环）
graph[i] 中的所有元素 互不相同
保证输入为 有向无环图（DAG）
 */
#include <bits/stdc++.h>

using namespace std;

// 2022-09-12复写 DFS
class Solution {
    vector<vector<int>> res; // 收集符合条件的路径
    vector<int> path; // 0节点到终点的路径

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0); // 从0节点出发
        dfs(graph, 0); // 开始遍历
        return res;
    }
    void dfs(vector<vector<int>>& graph, int x) {
        if (x == graph.size()-1) { // 到达终点，找到满足条件的一条路径
            res.push_back(path);
            return;
        }

        for (int i = 0; i < graph[x].size(); ++i) { // 遍历节点x连接的所有节点
            path.push_back(graph[x][i]); // 遍历到的点加入路径
            dfs(graph, graph[x][i]); // 深处递归
            path.pop_back(); // 回溯
        }
    }
};