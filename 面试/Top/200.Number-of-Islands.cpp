/**
 * @file 200.Number-of-Islands.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 200.Number-of-Islands.cpp 岛屿数量 DFS
 */


/*
思路：
我们可以将二维网格看成一个无向图，竖直或水平相邻的 1 之间有边相连。

为了求出岛屿的数量，我们可以扫描整个二维网格。
如果一个位置为 1，则以其为起始节点开始进行深度优先搜索。
在深度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。

最终岛屿的数量就是我们进行深度优先搜索的次数。

复杂度分析
- 时间复杂度：O(MN)，其中 M 和 N 分别为行数和列数。
- 空间复杂度：O(MN)，在最坏情况下，整个网格均为陆地，
深度优先搜索的深度达到MN。
*/

// 2022-09-12复写 不改变原始数组，使用vis标记已访问数组
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dir{-1, 0, 1, 0, -1};
    // 主函数
    int numIslands(vector<vector<char>>& grid) {
        // 考虑边界条件
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int num_islands = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // 标记已访问
        // 扫描二维网格
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ++num_islands;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return num_islands;
    }

    // 辅函数dfs
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int x, int y) {
        vis[x][y] = 1; // 标记该店已访问
        int dx, dy;
        for (int i = 0; i < 4; ++i) {
            dx = x + dir[i];
            dy = y + dir[i + 1];
            if (isInBoard(grid, dx, dy) && grid[dx][dy] == '1' && !vis[dx][dy]) {
                dfs(grid, vis, dx, dy);
            }
        }
    }

    // 检查是否还在网格内
    bool isInBoard(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
};