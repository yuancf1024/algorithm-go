/**
 * @file 695.Max-Area-of-Island.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * /* 695. 岛屿的最大面积
题目描述

给定一个二维的0-1 矩阵，其中0 表示海洋，1 表示陆地。
单独的或相邻的陆地可以形成岛屿，每个格子只与其上下左右四个格子相邻。
求最大的岛屿面积。

输入输出样例
输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
Input:
[[1,0,1,1,0,1,0,1],
[1,0,1,1,0,1,1,1],
[0,0,0,0,0,0,0,1]]
Output: 6
最大的岛屿面积为6，位于最右侧。
*/

/*
思路：
 方法一：深度优先搜索
算法
- 我们想知道网格中每个连通形状的面积，然后取最大值。
- 如果我们在一个土地上，以 4 个方向探索与之相连的每一个土地
（以及与这些土地相连的土地），那么探索过的土地总数将是该连通形状的面积。
- 为了确保每个土地访问不超过一次，我们每次经过一块土地时，
将这块土地的值置为 0。这样我们就不会多次访问同一土地。
*/

#include <bits/stdc++.h>

using namespace std;

// 2022-09-12复写 
class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int area = 0;
        int n = grid.size(), m = grid[0].size();
        // 扫描网格
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }

    // 辅函数dfs
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0) { // 结束dfs递归的返回条件
            return 0;
        }
        grid[x][y] = 0; // 将搜索过的点置为0，避免重复搜索
        int areaIslands = 1;

        for (int i = 0; i < 4; ++i) {
            int dx = x + dir[i];
            int dy = y + dir[i + 1];
            if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size()) {
                areaIslands += dfs(grid, dx, dy);
            }
        }
        return areaIslands;
    }
};