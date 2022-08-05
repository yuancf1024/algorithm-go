/**
 * @file 542.01-Matrix.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * leetcode-542. 01 矩阵
 * 
 * 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，
 * 其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1：
0 0 1
0 1 0
0 0 0

输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]

示例 2：
0 0 0
0 1 0
1 1 1

输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
mat 中至少有一个 0 
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) { // 考虑特殊的边界条件
            return {};
        }
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 1));
        for (int i = 0; i < n; ++i) { // 从左上到右下进行一次动态搜索
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0; // 搜索的位置如果本身为0，那么对dp置为0
                } else {
                    if (j > 0) { // 确保j-1没有越过上边界
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // 向上搜索
                    }
                    if (i > 0) { // 确保i-1没有越过左边界
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // 向左搜索
                    }
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) { // 从右下到左上进行一次动态搜索
            for (int j = m - 1; j >= 0; --j) {
                if (mat[i][j] != 0) { // 第一次动态搜索的过程已经处理了全部mat[i][j] == 0 的情况
                    if (j < m-1) { // 确保j+1没有越过右边界
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1); // 向右搜索
                    }
                    if (i < n-1) { // 确保i+1没有越过下边界
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1); // 向下搜索
                    }
                }
            }
        }
        return dp;
    }
};

/**
 * @brief 
 * 题解
一般来说，因为这道题涉及到四个方向上的最近搜索，所以很多人的第一反应
可能会是广度优先搜索。但是对于一个大小O(mn)的二维数组，对每个位置进行
四向搜索，最坏情况的时间复杂度（即全是1）会达到恐怖的O(m^2n^2)。

一种办法是使用一个dp 数组做memoization，使得广度优先搜索不会重复遍历
相同位置；另一种更简单的方法是，我们从左上到右下进行一次动态搜索，
再从右下到左上进行一次动态搜索。
两次动态搜索即可完成四个方向上的查找。
 */