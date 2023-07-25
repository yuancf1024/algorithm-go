/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 

示例1：
5 5
1 5 3 2 5
1 0 4 7 2
3 4 2 3 3
1 3 2 4 8
4 3 1 5 7
1 5 3 2 5
2 3 4 6 2
3 3 3 4 1
1 3 4 5 8
4 2 7 3 8

7

示例2：
7 7
1 1 1 0 1 1 0
1 0 1 1 1 1 1
1 1 0 0 0 1 1
1 1 1 0 1 0 1
1 0 1 1 1 1 0
1 0 1 0 0 1 0
1 0 0 0 0 0 1
1 0 0 1 1 0 0
1 0 0 0 0 0 1
1 0 1 0 0 1 0
0 1 1 1 1 0 1
1 0 0 0 1 1 0
0 1 0 1 1 0 0
1 0 0 0 0 0 1

17
 */

/*
AC
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dir{-1, 0, 1, 0, -1};

    int maxNotChange(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] != 0) {
            return 0;
        }
        grid[r][c] = 1;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + dir[i];
            y = c + dir[i + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> A1(M, vector<int>(N));
    vector<vector<int>> A2(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A1[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A2[i][j];
        }
    }

    vector<vector<int>> p(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            p[i][j] = int(A2[i][j]) - int(A1[i][j]);
        }
    }

    // 核心代码 求相邻的0最大数量
    Solution s;
    int res = s.maxNotChange(p);
    cout << res << endl;

    return 0;
}