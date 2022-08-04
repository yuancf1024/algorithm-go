/* 695. 岛屿的最大面积
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
题解
此题是十分标准的搜索题，我们可以拿来练手深度优先搜索。一般来说，深度优先搜索类型
的题可以分为主函数和辅函数，
- 主函数用于遍历所有的搜索位置，判断是否可以开始搜索，如果可以即在辅函数进行搜索。
- 辅函数则负责深度优先搜索的递归调用。
当然，我们也可以使用栈（stack）实现深度优先搜索，但因为栈与递归的调用原理相同，
而递归相对便于实现，因此刷题时笔者推荐使用递归式写法，
同时也方便进行回溯（见下节）。不过在实际工程上，直接使用栈可能才是最好的选择，
一是因为便于理解，二是更不易出现递归栈满的情况。我们先展示使用栈的写法。
*/

// 使用栈的写法 可读性太差了
vector<int> direction{-1, 0, 1, 0, -1};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m? grid[0].size(): 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty()) {
                        auto [r, c] = island.top();
                        island.pop();
                        for (int k = 0; k < 4; ++k) {
                            x = r + direction[k], y = c + direction[k+1];
                            if (x >= 0 && x < m &&
                            y >= 0 && y < n && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
};

/*
这里我们使用了一个小技巧，对于四个方向的遍历，
可以创造一个数组[-1, 0, 1, 0, -1]，每相邻两位即为上下左右四个方向之一。
在辅函数里，一个一定要注意的点是辅函数内递归搜索时，边界条件的判定。
边界判定一般有两种写法，
    - 一种是先判定是否越界，只有在合法的情况下才进行下一步搜索
    （即判断放在调用递归函数前）；
    - 另一种是不管三七二十一先进行下一步搜索，待下一步搜索开始时
    再判断是否合法（即判断放在辅函数第一行）。
我们这里分别展示这两种写法
*/

class Solution {
public:
    // 边界条件的判断放在递归搜索函数之前
    vector<int> direction{-1, 0, 1, 0, -1};

    // 主函数
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    // 辅函数
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + direction[i], y = c + direction[i+1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};

// 边界条件的判断放在辅函数第一行
class Solution {
public:
    // 边界条件的判断放在递归搜索函数之前
    // 主函数
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }

    // 辅函数
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() ||
        c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs(grid, r+1, c) + dfs(grid, r-1, c) + 
                    dfs(grid, r, c+1) + dfs(grid, r, c-1);
    }
};

// 复写 2022-08-04 照着抄 建议用该模板
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    // 主函数
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) { // 考虑特殊边界条件case
            return 0;
        }
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) { // 遍历grid
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) { // 更新max_area
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    // 辅函数
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) { // 递归结束的返回函数
            return 0;
        }
        grid[r][c] = 0; // 为了避免重复计算该位置的面积
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) { // 判断新坐标是否还在grid内
                area += dfs(grid, x, y); // 递归搜索
            }
        }
        return area;
    }
};

// 参考leetcode官方题解 DFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) { 
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size()
        || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
};

/**
 * @brief 参考leetcode官方题解
 * 方法一：深度优先搜索
算法

- 我们想知道网格中每个连通形状的面积，然后取最大值。

- 如果我们在一个土地上，以 4 个方向探索与之相连的每一个土地
（以及与这些土地相连的土地），那么探索过的土地总数将是该连通形状的面积。

- 为了确保每个土地访问不超过一次，我们每次经过一块土地时，
将这块土地的值置为 0。这样我们就不会多次访问同一土地。
 */