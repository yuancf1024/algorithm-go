/**
 * @file 329.Longest-Increasing-Path-in-a-Matrix.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-329. 矩阵中的最长递增路径
 * 
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 
你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

示例 1：
输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。

示例 2：
输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

示例 3：
输入：matrix = [[1]]
输出：1

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1
 */

// 方法一：记忆化深度优先搜索
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, columns;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) { // 考虑边界条件
            return 0;
        }
        rows = matrix.size();
        columns = matrix[0].size();
        // 用矩阵 \textit{memo}memo 作为缓存矩阵，已经计算过的单元格的结果存储到缓存矩阵中
        auto memo = vector<vector<int>>(rows, vector<int>(columns));
        int ans = 0;
        for (int i = 0; i < rows; ++i) { // 遍历网格点
            for (int j = 0; j < columns; ++j) {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int row, int column, vector<vector<int>>& memo) {
        if (memo[row][column] != 0) { // 递归结束条件
            return memo[row][column]; // 如果 memo[i][j]!=0，说明该单元格的结果已经计算过，则直接从缓存中读取结果
        }
        ++memo[row][column]; // 如果 memo[i][j]=0，说明该单元格的结果尚未被计算过，则进行搜索，并将计算得到的结果存入缓存中
        for (int i = 0; i < 4; ++i) {
            int x = row + dirs[i][0], y = column + dirs[i][1];
            if (x >= 0 && x < rows && y >= 0 && y < columns 
            && matrix[x][y] > matrix[row][column]) { // 递增条件 + 新的搜索点在网格内
                memo[row][column] =
                    max(memo[row][column],
                        dfs(matrix, x, y, memo) + 1); // 递归搜索
            }
        }
        return memo[row][column];
    }
};

/**
 * @brief 
 * 方法一：记忆化深度优先搜索
 * 将矩阵看成一个有向图，每个单元格对应图中的一个节点，
 * 如果相邻的两个单元格的值不相等，则在相邻的两个单元格之间存在一条
 * 从较小值指向较大值的有向边。问题转化成在有向图中寻找最长路径。

深度优先搜索是非常直观的方法。从一个单元格开始进行深度优先搜索，
即可找到从该单元格开始的最长递增路径。对每个单元格分别进行深度优先搜索
之后，即可得到矩阵中的最长递增路径的长度。

但是如果使用朴素深度优先搜索，时间复杂度是指数级，会超出时间限制，
因此必须加以优化。

朴素深度优先搜索的时间复杂度过高的原因是进行了大量的重复计算，
同一个单元格会被访问多次，每次访问都要重新计算。由于同一个单元格对应的
最长递增路径的长度是固定不变的，因此可以使用记忆化的方法进行优化。
用矩阵 memo 作为缓存矩阵，已经计算过的单元格的结果存储到缓存矩阵中。

使用记忆化深度优先搜索，当访问到一个单元格 (i,j) 时，
- 如果 memo[i][j]!=0，说明该单元格的结果已经计算过，则直接从缓存中读取结果，
- 如果 memo[i][j]=0，说明该单元格的结果尚未被计算过，则进行搜索，
并将计算得到的结果存入缓存中。

遍历完矩阵中的所有单元格之后，即可得到矩阵中的最长递增路径的长度。

复杂度分析
时间复杂度：O(mn)，其中 m 和 n 分别是矩阵的行数和列数。
深度优先搜索的时间复杂度是 O(V+E)，其中 V 是节点数，E 是边数。
在矩阵中，O(V)=O(mn)，O(E)≈O(4mn)=O(mn)。

空间复杂度：O(mn)，其中 m 和 n 分别是矩阵的行数和列数。
空间复杂度主要取决于缓存和递归调用深度，
缓存的空间复杂度是 O(mn)，递归调用深度不会超过 mn。
 */