package leetcode

// 2023-07-13 记得编写测试文件

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

func minFallingPathSum(matrix [][]int) int {
	n := len(matrix)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}

	copy(dp[0], matrix[0])

	for i := 1; i < n; i++ {
		for j := 0; j < n; j++ {
			mn := dp[i-1][j]
			if j > 0 {
				mn = min(mn, dp[i-1][j-1])
			}

			if j < n-1 {
				mn = min(mn, dp[i-1][j+1])
			}
			dp[i][j] = mn + matrix[i][j]
		}
	}
	minVal := dp[n-1][0]
	for _, val := range dp[n-1] {
		if val < minVal {
			minVal = val
		}
	}
	return minVal
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// func main() {
// 	nums := [][]int{
// 		{2, 1, 3},
// 		{6, 5, 4},
// 		{7, 8, 9}}

// 	res := minFallingPathSum(nums)
// 	fmt.Println(res)
// }
