package leetcode

/* 494. 目标和
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 
表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，
然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/

// 解法1：DP
func findTargetSumWays(nums []int, target int) int {
	total := 0
	for _, n := range nums {
		total += n
	}
	if target > total || (target + total)%2 == 1 || (target + total) < 0 {
		return 0
	}
	C := (target + total) / 2
	dp := make([]int, C+1)
	dp[0] = 1 // base case
	for _, n := range nums {
		for i := C; i >= n; i-- {
			dp[i] += dp[i-n]
		}
	}
	return dp[C]
}

/*
解题思路
给出一个数组，要求在这个数组里面的每个元素前面加上 + 或者 - 号，
最终总和等于 S。问有多少种不同的方法。

这一题可以用 DP 和 DFS 解答。DFS 方法就比较暴力简单了。见代码。
这里分析一下 DP 的做法。题目要求在数组元素前加上 + 或者 - 号，
其实相当于把数组分成了 2 组，一组全部都加 + 号，一组都加 - 号。
记 + 号的一组 P ，记 - 号的一组 N，那么可以推出以下的关系。

sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
等号两边都加上 sum(N) + sum(P)，于是可以得到结果 
2 * sum(P) = target + sum(nums)，
那么这道题就转换成了，能否在数组中找到这样一个集合，
和等于 (target + sum(nums)) / 2。
那么这题就转化为了第 416 题了。dp[i] 中存储的是能使和为 i 的方法个数。

如果和不是偶数，即不能被 2 整除，或者和是负数，
那说明找不到满足题目要求的解了，直接输出 0 。
*/

// 参考别人的DP
func findTargetSumWays_v1(nums []int, target int) int {
	// 动态规划解法
	/*
	sum(P) - sum(N) = target
	sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
    2 * sum(P) = target + sum(nums)
	sum(P) = (target+sum(nums))/2
	*/
	sum := 0
	for _, n := range nums {
		sum += n
	}
	if target > sum || (target + sum)%2 == 1 || (target + sum) < 0 {
		return 0
	}

	// 寻找 sum(P) = (target+sum(nums))/2
	maxnum := (target + sum) / 2
	dp := make([]int, maxnum+1)
	dp[0] = 1 // base case 在0的情况下有多少组合 就是都不操作 1种
	for _, n := range nums {
		for i := maxnum; i >= n; i-- {
			dp[i] += dp[i-n]
		}
	}
	return dp[maxnum]
}