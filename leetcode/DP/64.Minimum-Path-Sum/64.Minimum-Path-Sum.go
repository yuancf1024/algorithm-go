package leetcode

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

*/

// 参考算法模板
func minPathSum(grid [][]int) int {
	// 思路:动态规划
	// f[i][j] 表示i,j到0,0的和最小
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	
	// 复用原来的矩阵列表
	// 初始化: f[i][0] f[0][j]
	for i := 1; i < len(grid); i++ {
		grid[i][0] = grid[i][0] + grid[i-1][0]
	}
	for j := 1; j < len(grid[0]); j++ {
		grid[0][j] = grid[0][j] + grid[0][j-1]
	}
	for i := 1; i < len(grid); i++ {
		for j := 1; j < len(grid[i]); j++ {
			grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j]
		}
	}
	return grid[len(grid)-1][len(grid[0])-1]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

/*
动态规划 
1、state: f[x][y]从起点走到 x,y 的最短路径 
2、function: f[x][y] = min(f[x-1][y], f[x][y-1]) + A[x][y] 
3、intialize: f[0][0] = A[0][0]、f[i][0] = sum(0,0 -> i,0)、 f[0][i] = sum(0,0 -> 0,i) 
4、answer: f[n-1][m-1]
*/

// 解法1 原地DP,无辅助空间
func minPathSum_v1(grid [][]int) int {
	m, n := len(grid), len(grid[0]) // 网格宽度,长度
	for i := 1; i < m; i++ {
		grid[i][0] += grid[i-1][0]
	}
	for j := 1; j < n; j++ {
		grid[0][j] += grid[0][j-1]
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			grid[i][j] += min(grid[i-1][j], grid[i][j-1])
		}
	}
	return grid[m-1][n-1]
}

// 解法二 最原始的方法,辅助空间 O(n^2)
func minPathSum_v2(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	m, n := len(grid), len(grid[0])
	if m == 0 || n == 0 {
		return 0
	}

	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}

	// initFirstCol
	for i := 0; i < len(dp); i++ {
		if i == 0 {
			dp[i][0] = grid[i][0]
		} else {
			dp[i][0] = grid[i][0] + dp[i-1][0]
		}
	}

	// initFirstRow
	for i := 0; i < len(dp[0]); i++ {
		if i == 0 {
			dp[0][i] = grid[0][i]
		} else {
			dp[0][i] = grid[0][i] + dp[0][i-1]
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[i][j] = min1(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		}
	}
	return dp[m-1][n-1]
}

func min1(a, b int) int {
	if a > b {
		return b
	}
	return a
}

/*
解题思路
在地图上求出从左上角到右下角的路径中，
数字之和最小的一个，输出数字和。
这一题最简单的想法就是用一个二维数组来 DP，
当然这是最原始的做法。由于只能往下和往右走，
只需要维护 2 列信息就可以了，
从左边推到最右边即可得到最小的解。
更近一步，可以直接在原来的数组中做原地 DP，空间复杂度为 0 。
*/