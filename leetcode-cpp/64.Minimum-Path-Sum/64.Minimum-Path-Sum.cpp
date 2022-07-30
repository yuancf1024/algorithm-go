/* 64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，
请找出一条从左上角到右下角的路径，
使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12

提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

*/

// 复写 2022-07-30 辅助空间 O(n^2)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.at(0).size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
1. 确定dp[i][j]及下标的含义
dp[i][j] 代表从坐标[0][0] 到 坐标[i][j] 路径上数字总和最小的值
i、j代表坐标位置

2. 确定递推公式

dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);

3. 确定dp初始化

dp[0][0] = grid[0][0]
dp[i][0] = dp[i-1][0] + grid[i][0]
dp[0][j] = dp[0][j-1] + grid[0][j]

4. 确定遍历顺序

从左到右，从上到下

5. 举例推到dp数组
*/


// 原地辅助空间
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.at(0).size();
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

/*
借助原始grid数组直接继续宁累加求解
无辅助空间
*/