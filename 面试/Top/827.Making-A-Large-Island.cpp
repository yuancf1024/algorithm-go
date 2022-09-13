/**
 * @file 827.Making-A-Large-Island.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * leetcode-827.最大人工岛
 * 
 * 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
返回执行此操作后，grid 中最大的岛屿面积是多少？
岛屿 由一组上、下、左、右四个方向相连的 1 形成。

示例 1:
输入: grid = [[1, 0], [0, 1]]
输出: 3
解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。

示例 2:
输入: grid = [[1, 1], [1, 0]]
输出: 4
解释: 将一格0变成1，岛屿的面积扩大为 4。

示例 3:
输入: grid = [[1, 1], [1, 1]]
输出: 4
解释: 没有0可以让我们变成1，面积依然为 4。

提示：
n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] 为 0 或 1

*/

/*
思路：
其实每次深搜遍历计算最大岛屿面积，我们都做了很多重复的工作。

只要把深搜就可以，并每个岛屿的面积记录下来就好。

第一步：一次遍历地图，得出各个岛屿的面积，并做编号记录。
可以使用map记录，key为岛屿编号，value为岛屿面积

第二步：在遍历地图，遍历0的方格（因为要将0变成1），
并统计该1（由0变成的1）周边岛屿面积，将其相邻面积相加在一起，
遍历所有 0 之后，就可以得出 选一个0变成1 之后的最大面积。
*/

#include <bits/stdc++.h>

using namespace std;

// 2022-09-12复写
class Solution {
    int count;
    vector<int> dir = {-1, 0, 1, 0, -1}; // 搜索的四个方向
    // 辅函数dfs
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int mark) {
        if (vis[x][y] || grid[x][y] == 0) { // 终止条件：访问过的节点或遇到海水
            return;
        }
        vis[x][y] = true; // 标记已访问
        grid[x][y] = mark; // 给陆地标记新标签 ！！！这里非常重要 为后面作铺垫
        count++;
        for (int i = 0; i < 4; ++i) {
            int dx = x + dir[i];
            int dy = y + dir[i + 1];
            if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) {
                // 超出地图 跳过
                continue;
            }
            dfs(grid, vis, dx, dy, mark);
        }
    }

public:
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        unordered_map<int, int> gridNum;
        int mark = 2; // 记录每个岛屿的编号
        bool isAllGrid = true; // 标记是否整个地图都是陆地
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    isAllGrid = false;
                }
                if (!vis[i][j] && grid[i][j] == 1) { // (i,j)未访问过并且是陆地
                    count = 0; // 初始化为0
                    dfs(grid, vis, i, j, mark); // 将与其连接的陆地都标记上true
                    gridNum[mark] = count; // 记录每一个岛屿的面积(根据mark映射)
                    mark++; // 记录下一个岛屿编号
                }
            } 
        }

        // 如果都是陆地，返回全面积
        if (isAllGrid) {
            return n * m;
        }
        
        // 以下逻辑是根据添加陆地的位置，计算周边岛屿面积之和
        int res = 0;
        unordered_set<int> visGrid; // 标记已访问过的岛屿
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 1; // 记录连接之后的岛屿数量
                visGrid.clear(); // 每次使用时，清空
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int neari = i + dir[k]; // 计算相邻坐标
                        int nearj = j + dir[k + 1];
                        // 越界就跳过
                        if (neari < 0 || neari >= grid.size() || nearj < 0 || nearj >= grid[0].size()) {
                            continue;
                        }
                        // 添加过的岛屿不要重复添加
                        if (visGrid.count(grid[neari][nearj])) {
                            continue;
                        }
                        // 把相邻四面的岛屿数量加起来
                        count += gridNum[grid[neari][nearj]];
                        visGrid.insert(grid[neari][nearj]); // 标记该岛屿已经添加过
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};