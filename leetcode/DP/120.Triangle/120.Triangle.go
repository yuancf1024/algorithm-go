package leetcode

import "math"

/* 120. 三角形最小路径和
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于
上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，
那么下一步可以移动到下一行的下标 i 或 i + 1 。

测试用例：
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
*/

// DP 自底向上
func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 || len(triangle[0]) == 0 {
		return 0
	}
	// 1、状态定义：f[i][j]表示从i、j出发，到达最后一层的最短路径
	l := len(triangle)
	f := make([][]int, l)
	// 2、初始化
	for i := 0; i < l; i++ {
		for j := 0; j < len(triangle[i]); j++ {
			if f[i] == nil {
				f[i] = make([]int, len(triangle[i]))
			}
			f[i][j] = triangle[i][j]
		}
	}
	// 3、递推求解
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j < len(triangle[i]); j++ {
			f[i][j] = min(f[i+1][j], f[i+1][j+1]) + triangle[i][j]
		}
	}
	// 4、答案
	return f[0][0]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// DP 自顶向下
func minimumTotal_v1(triangle [][]int) int {
	if len(triangle) == 0 || len(triangle[0]) == 0 {
		return 0
	}
	// 1、状态定义：f[i][j]表示从0、0出发，到达i,j的最短路径
	l := len(triangle)
	f := make([][]int, l)
	// 2、初始化
	for i := 0; i < l; i++ {
		for j := 0; j < len(triangle[i]); j++ {
			if f[i] == nil {
				f[i] = make([]int, len(triangle[i]))
			}
			f[i][j] = triangle[i][j]
		}
	}
	// 3、递推求解
	for i := 1; i < l; i++ {
		for j := 0; j < len(triangle[i]); j++ {
			// 这里分为两种情况：
			// 1、上一层没有左边值
			// 2、上一层没有右边值
			if j-1 < 0 {
				f[i][j] = f[i-1][j] + triangle[i][j]
			} else if j >= len(f[i-1]) {
				f[i][j] = f[i-1][j-1] + triangle[i][j]
			} else {
				f[i][j] = min(f[i-1][j], f[i-1][j-1]) + triangle[i][j]
			}
		}
	}
	res := f[l-1][0]
	for i := 1; i < len(f[l-1]); i++ {
		res = min(res, f[l-1][i])
	}
	// 4、答案
	return res
}

// func min(a, b int) int {
// 	if a > b {
// 		return b
// 	}
// 	return a
// }

/*
解题思路
求出从三角形顶端到底端的最小和。要求最好用 O(n) 的时间复杂度。
这一题最优解是不用辅助空间，**直接从下层往上层推。**
普通解法是用二维数组 DP，稍微优化的解法是一维数组 DP。解法如下：
*/

// 解法一 倒序DP，无辅助空间
func minimumTotal_v2(triangle [][]int) int {
	if triangle == nil {
		return 0
	}
	for row := len(triangle) - 2; row >= 0; row-- {
		for col := 0; col < len(triangle[row]); col++ {
			triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1])
		}
	}
	return triangle[0][0]
}

// 解法二 正常DP，空间复杂度 O(n)
func minimumTotal_v3(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	dp, minNum, index := make([]int, len(triangle[len(triangle)-1])), math.MaxInt64, 0
	for ; index < len(triangle[0]); index++ {
		dp[index] = triangle[0][index]
	}
	for i := 1; i < len(triangle); i++ {
		for j := len(triangle[i]) - 1; j >= 0; j-- {
			if j == 0 {
				// 最左边
				dp[j] += triangle[i][0]
			} else if j == len(triangle[i])-1 {
				// 最右边
				dp[j] += dp[j-1] + triangle[i][j]
			} else {
				// 中间
				dp[j] = min(dp[j-1]+triangle[i][j], dp[j]+triangle[i][j])
			}
		}
	}
	for i := 0; i < len(dp); i++ {
		if dp[i] < minNum {
			minNum = dp[i]
		}
	}
	return minNum
}