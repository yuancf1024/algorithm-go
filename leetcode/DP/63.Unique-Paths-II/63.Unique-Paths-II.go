package leetcode

/* 63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。
*/

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	// f[i][j] = f[i-1][j] + f[i][j-1] 并检查障碍物
	if obstacleGrid[0][0] == 1 {
		return 0
	}
	m := len(obstacleGrid)
	n := len(obstacleGrid[0])
	f := make([][]int, m)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if f[i] == nil {
				f[i] = make([]int, n)
			}
			f[i][j] = 1
		}
	}
	for i := 1; i < m; i++ {
		if obstacleGrid[i][0] == 1 || f[i-1][0] == 0 {
			f[i][0] = 0
		}
	}
	for j := 1; j < n; j++ {
		if obstacleGrid[0][j] == 1 || f[0][j-1] == 0 {
			f[0][j] = 0
		}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 1 {
				f[i][j] = 0
			} else {
				f[i][j] = f[i-1][j] + f[i][j-1]
			}
		}
	}
	return f[m-1][n-1]
}

// 参考halfrost
func uniquePathsWithObstacles_v1(obstacleGrid [][]int) int {
	if len(obstacleGrid) == 0 || obstacleGrid[0][0] == 1 { // 边界条件判断: 输入的障碍网格为空 || 起点就遇到了障碍物
		return 0
	}
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	dp := make([][]int, m) // 初始化二维dp数组
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}
	dp[0][0] = 1 // 出发网格赋值
	for i := 1; i < n; i++ {
		if dp[0][i-1] != 0 && obstacleGrid[0][i] != 1 { // 首行初始化,遍历点的前一个位置不能为0 && 遍历点没有障碍物
			dp[0][i] = 1
		}
	}
	for i := 1; i < m; i++ {
		if dp[i-1][0] != 0 && obstacleGrid[i][0] != 1 { // 首列初始化
			dp[i][0] = 1
		}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] != 1 { // 如果没有遇到障碍物,直接使用dp公式,如果遇到障碍物,直接跳过,dp[i][j]默认为0
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}


/*
解题思路
这一题是第 62 题的加强版。也是一道考察 DP 的简单题。
这一题比第 62 题增加的条件是地图中会出现障碍物，
障碍物的处理方法是 dp[i][j]=0。
需要注意的一种情况是，起点就是障碍物，那么这种情况直接输出 0 。
*/