/**
 * @file 1289.Minimum-Falling-Path-Sum-II.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1289.下降路径最小和II
 * @version 0.1
 * @date 2023-08-11
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个 n x n 整数矩阵 grid ，
请你返回 非零偏移下降路径 数字和的最小值。

非零偏移下降路径 定义为：从 grid 数组中的
每一行选择一个数字，且按顺序选出来的数字中，
相邻数字不在原数组的同一列。

示例 1：
输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
输出：13
解释：
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是 [1,5,7] ，
所以答案是 13 。

示例 2：
输入：grid = [[7]]
输出：7
 
提示：

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99

 */

#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            d[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j == k) {
                        continue;
                    }
                    d[i][j] = min(d[i][j], d[i-1][k] + grid[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, d[n-1][j]);
        }
        return ans;
    }
};

int main() {
    vector<vector<int> > grid = {{1,2,3},{4,5,6},{7,8,9}};
    int res = Solution().minFallingPathSum(grid);

    cout << res << endl;
    return 0;
}

/**
 * @brief leetcode官方题解
 * 方法一：动态规划
思路与算法

我们可以使用动态规划来解决这个问题。

令状态 f[i][j] 表示从数组 grid的前 i 行中的
每一行选择一个数字，并且第 i 行选择的数字为 
grid[i][j]时，可以得到的路径和最小值。
f[i][j]可以从第 i−1 行除了 f[i−1][j]
之外的任意状态转移而来，因此有如下状态转移方程：

f[i][j]={grid[0][j] if i=0
        min⁡(f[i−1][k])+grid[i][j] if i≠0,j≠k 
​
最终，我们取第 n−1行中的最小值，
即最小的 min⁡(f[n][j]) 作为答案。

复杂度分析

时间复杂度：O(n^3)，其中 n 是 grid的行数
和列数。我们使用三重循环来求解答案，
每一层循环的复杂度为 O(n)，第 0 层单独求解
和最终答案遍历的时间复杂度均为 O(n)，
因此总的时间复杂度为O(n^3)。

空间复杂度：O(n^2)。我们使用二维数组 
d[i][j] 来存储过程中的答案，实际上可以
使用滚动数组优化至 O(n)。



 */