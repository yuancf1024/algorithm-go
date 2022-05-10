package leetcode

/* 70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 

示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶

*/

// 参考算法模板
func climbStairs(n int) int {
	// f[i] = f[i-1] + f[i-2]
	if n == 1 || n == 0 {
		return n
	}
	f := make([]int, n+1)
	f[1] = 1
	f[2] = 2
	for i := 3; i <= n; i++ {
		f[i] = f[i-1] + f[i-2]
	}
	return f[n]
}

// 参考halfrost
func climbStairs_v1(n int) int {
	dp := make([]int, n+1)
	dp[0], dp[1] = 1, 1
	for i := 2; i <= n; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return dp[n]
}
/*
解题思路
简单的 DP，经典的爬楼梯问题。一个楼梯可以由 n-1 和 n-2 的楼梯爬上来。
这一题求解的值就是斐波那契数列。
*/