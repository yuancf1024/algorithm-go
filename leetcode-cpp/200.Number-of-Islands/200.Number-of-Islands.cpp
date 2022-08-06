/**
 * @file 200.Number-of-Islands.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * leetcode-200. 岛屿数量
 * 
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，
 * 请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地
连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300

grid[i][j] 的值为 '0' 或 '1'
 */

// 方法一：深度优先搜索
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) { 
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0'; // 遍历过的点置为0，避免重复搜索
        if (r-1 >= 0 && grid[r-1][c] == '1') { // 向左搜索
            dfs(grid, r - 1, c);
        }
        if (r+1 < nr && grid[r+1][c] == '1') { // 向右搜索
            dfs(grid, r + 1, c);
        }
        if (c-1 >= 0 && grid[r][c-1] == '1') { // 向上搜索
            dfs(grid, r, c - 1);
        }
        if (c+1 < nc && grid[r][c+1] == '1') { // 向下搜索
            dfs(grid, r, c + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) { 
        int nr = grid.size();
        if (!nr) { // 边界条件
            return 0;
        }
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) { // 扫描二维网格
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }
        return num_islands;
    }
};

/**
 * @brief 
 * 方法一：深度优先搜索
 * 
 * 我们可以将二维网格看成一个无向图，竖直或水平相邻的 1 之间有边相连。

为了求出岛屿的数量，我们可以扫描整个二维网格。
如果一个位置为 1，则以其为起始节点开始进行深度优先搜索。
在深度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。

最终岛屿的数量就是我们进行深度优先搜索的次数。

复杂度分析
- 时间复杂度：O(MN)，其中 M 和 N 分别为行数和列数。
- 空间复杂度：O(MN)，在最坏情况下，整个网格均为陆地，
深度优先搜索的深度达到MN。

 */


// 复写岛屿数量 DFS 不改变原始数组，使用visited标记已访问数组
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    // 主函数
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) { // 边界条件
            return 0;
        }
        int num_islands = 0;
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0)); // 建立visited数组，标记已访问过的点
        // 扫描二维网格
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) { // 遍历到的点为1且没有访问过
                    ++num_islands;
                    searchIslands(grid, visited, i, j); // DFS
                }
            }
        }
        return num_islands;
    }

    // 辅函数 DFS
    void searchIslands(vector<vector<char>>& grid, vector<vector<int>>& visited,
                       int r, int c) {
        visited[r][c] = 1; // 标记该点已被访问过
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = r + direction[i]; // 上下左右搜索
            y = c + direction[i + 1];
            if (isInBoard(grid, x, y) && grid[x][y] == '1' && !visited[x][y]) { // 搜索到的点还在网格内、为岛屿且没有访问过
                searchIslands(grid, visited, x, y); // 继续DFS
            }
        }
    }
    // 检查(x,y)是否还在网格内
    bool isInBoard(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
};

