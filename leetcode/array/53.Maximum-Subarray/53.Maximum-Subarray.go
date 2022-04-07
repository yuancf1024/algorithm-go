package leetcode

/*
给你一个整数数组 nums ，
请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

*/

// 复杂度为O(N)的解法 模拟
func maxSubArray1(nums []int) int {
	
	n := len(nums)

	if n == 1 {
		return nums[0]
	}

	maxSum, res, p := nums[0], 0, 0
	for p < len(nums) {
		res += nums[p]
		if res > maxSum { // 更新最大子数组
			maxSum = res
		}
		if res < 0 { 
			// 这一步很关键，nums[p]可能为负，所以要及时将子数组和为负的清除掉
			res = 0
		}
		p++
	}
	return maxSum
}

// 更为精妙的分治法求解 DP
func maxSubArray(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}

	dp, res := make([]int, n), nums[0]
	dp[0] = nums[0]
	for i := 1; i < n; i++ {
		if dp[i-1] > 0 {
			dp[i] = nums[i] + dp[i-1]
		} else {
			dp[i] = nums[i]
		}
		res = max(res, dp[i])
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

/*
// 复杂度为O(N)的解法
数组中最少一个元素，所以先处理边界条件：数组中只有一个元素的情况，直接返回nums[0];
把nums[0]作为最大子数组，将数组元素从index = 0开始逐一累加。
如果累加值大于初始最大子数组，那么把累加值res赋给maxSum；
如果累加值小于0，把res归零，p继续遍历下一个元素。


// 更为精妙的分治法求解

DP 动态规划
这一题可以用 DP 求解也可以不用 DP。
题目要求输出数组中某个区间内数字之和最大的那个值。
dp[i] 表示 [0,i] 区间内各个子区间和的最大值，
状态转移方程是 dp[i] = nums[i] + dp[i-1] (dp[i-1] > 0)，
dp[i] = nums[i] (dp[i-1] ≤ 0)。
*/