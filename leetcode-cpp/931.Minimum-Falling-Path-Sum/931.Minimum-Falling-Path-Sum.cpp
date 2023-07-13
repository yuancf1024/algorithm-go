/**
 * @file 931.Minimum-Falling-Path-Sum.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-931.下降路径最小和
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个n x n的方形整数数组 matrix ，
请你找出并返回通过 matrix 的下降路径的最小和 。

下降路径 可以从第一行中的任何元素开始，
并从每一行中选择一个元素。
在下一行选择的元素和当前行所选元素最多相隔一列
（即位于正下方或者沿对角线向左或者向右的第一个元素）。
具体来说，位置 (row, col) 的下一个元素应当是
 (row + 1, col - 1)、(row + 1, col) 或者 
 (row + 1, col + 1) 。

示例 1：

输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
输出：13
解释：如图所示，为和最小的两条下降路径

示例 2：
输入：matrix = [[-19,57],[-40,-5]]
输出：-59
解释：如图所示，为和最小的下降路径

提示：

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
 */

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = dp[i-1][j];
                if (j > 0) {
                    mn = min(mn, dp[i-1][j-1]);
                }
                if (j < n - 1) {
                    mn = min(mn, dp[i-1][j+1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main() {
    vector<vector<int>> nums = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    int res = Solution().minFallingPathSum(nums);
    cout << res << endl;

    return 0;
}

/**
 * @brief 
 * leetcode官方题解
方法一：动态规划
思路

题目需要求出矩阵的和最小下降路径，可以求出末行
每个元素的和最小下降路径，然后找到其中和最小的
那一条路径即可。

而根据题意，每个坐标仅可以通过它的上一排紧邻的
三个坐标到达（左上，正上，右上），根据贪心思想，
每个坐标的和最小下降路径长度即为它的上一排紧邻
的三个坐标的和最小下降路径长度的最小值，
再加上当前坐标的和。
用dp表示和最小下降路径长度的话，
即为 dp[i][j]=matrix[i][j]+min⁡(dp[i−1][j−1],
dp[i−1][j],dp[i−1][j+1])，
第一列和最后一列有边界情况，需要特殊处理。

而第一行每个元素的和最小下降路径长度为它们本身的值。
最后返回最后一行的和最小下降路径长度的最小值即可。
 */