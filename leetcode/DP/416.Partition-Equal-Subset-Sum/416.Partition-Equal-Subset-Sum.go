package leetcode

/* 416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200
*/

// A+ DP 子集背包问题
func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	// 和为奇数时，不可能划分成两个和相等的集合
	if sum % 2 != 0 {
		return false
	}
	// C = half sum
	n, C, dp := len(nums), sum/2, make([]bool, sum/2+1)
	// base case
	for i := 0; i <= C; i++ {
		dp[i] = (nums[0] == i) // dp[i] = true (nums[0] == i)
	}
	for i := 1; i < n; i++ {
		for j := C; j >= nums[i]; j-- {
			dp[j] = dp[j] || dp[j - nums[i]]
		}
	}
	return dp[C]
}

/*
解题思路
给定一个非空的数组，其中所有的数字都是正整数。问是否可以将这个数组的元素
分为两部分，使得每部分的数字和相等。

这一题是典型的完全背包的题型。在 n 个物品中选出一定物品，
完全填满 sum/2 的背包。
F(n,C) 代表将 n 个物品填满容量为 C 的背包，
状态转移方程为 F(i,C) = F(i - 1,C) || F(i - 1, C - w[i])。
当 i - 1 个物品就可以填满 C ，这种情况满足题意。
同时如果 i - 1 个物品不能填满背包，加上第 i 个物品以后恰好
可以填满这个背包，也可以满足题意。
时间复杂度 O( n * sum/2 ) = O( n * sum)。
*/

// DP 子集问题 二维DP
func canPartition_v1(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	// 和为奇数时，不可能划分成两个和相等的集合
	if sum % 2 != 0 {
		return false
	}

	n, sum := len(nums), sum/2
	dp := make([][]bool, n+1) // 二维切片的初始化
	for i := range dp {
		dp[i] = make([]bool, sum+1)
	}

	// base case
	for i := 0; i <= n; i++ {
		dp[i][0] = true
	}

	// 状态转移,i代表前 i 个物品，j代表容量
	for i := 1; i <= n; i++ {
		for j := 1; j <= sum; j++ {
			if j - nums[i-1] < 0 {
				// 背包容量不足，不能装入第 i 个物品
				dp[i][j] = dp[i-1][j]
			} else {
				// 装入或不装入背包
				dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]]
			}
		}
	}
	return dp[n][sum]
}

// 优化后的DP 一维 ：时间复杂度 O(n*sum)，空间复杂度 O(sum)。
func canPartition_v2(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	// 和为奇数时，不可能划分成两个和相等的集合
	if sum % 2 != 0 {
		return false
	}

	n, sum := len(nums), sum/2
	dp := make([]bool, sum+1) // 切片的初始化
	
	// base case
	dp[0] = true // 背包没有空间的时候，就相当于装满了

	// 状态转移,i代表前 i 个物品，j代表容量
	for i := 0; i < n; i++ {
		for j := sum; j >= 0; j-- {
			if j - nums[i] >= 0 {
				// 装入或不装入背包
				dp[j] = dp[j] || dp[j - nums[i]]
			}
		}
	}
	return dp[sum]
}