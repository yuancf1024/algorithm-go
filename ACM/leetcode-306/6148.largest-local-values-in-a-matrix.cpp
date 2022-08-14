/**
 * @file 6148.largest-local-values-in-a-matrix.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * leetcode6148.矩阵中的局部最大值
给你一个大小为 n x n 的整数矩阵 grid 。

生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：

maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。
返回生成的矩阵。

示例 1：
输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
输出：[[9,9],[8,6]]

解释：原矩阵和生成的矩阵如上图所示。
注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。

示例 2：
输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
输出：[[2,2,2],[2,2,2],[2,2,2]]
解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。

提示：

n == grid.length == grid[i].length
3 <= n <= 100
1 <= grid[i][j] <= 100

*/

// 参考@灵茶山艾府
// 把最大值直接保存在3×3 矩阵的左上角，这样可以无需创建返回矩阵
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int mx = 0;
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        mx = max(mx, grid[x][y]);
                    }
                }
                grid[i][j] = mx;
            }
        }
        // return grid [0:n - 2] [0:n - 2];
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                ans[i][j] = grid[i][j];
            }
        }
        return ans;
    }
};

// 参考大佬@TsReaper 模拟
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < n; j++) {
                int mx = grid[i][j];
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        mx = max(mx, grid[i + x][j + y]);
                    }
                }
                ans[i - 1][j - 1] = mx;
            }
        }
        return ans;
    }
};

/**
 * @brief 
 * 参考大佬@TsReaper
 * 解法:模拟
按题意模拟即可。复杂度O(n^2)。
 */