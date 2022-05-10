package leetcode

import "sort"

/* 300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变
其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
*/

// 参考halfrost O(n^2) DP
func lengthOfLIS(nums []int) int {
	dp, res := make([]int, len(nums)+1), 0
	dp[0] = 0
	for i := 1; i <= len(nums); i++ {
		for j := 1; j < i; j++ {
			if nums[j-1] < nums[i-1] {
				dp[i] = max(dp[i], dp[j])
			}
		}
		dp[i] = dp[i] + 1
		res = max(res, dp[i])
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 解法二 O(n log n) DP
func lengthOfLIS_v1(nums []int) int {
	dp := []int{}
	for _, num := range nums {
		i := sort.SearchInts(dp, num)
		if i == len(dp) {
			dp = append(dp, num)
		} else {
			dp[i] = num
		}
	}
	return len(dp)
}

/*
解题思路

给定一个整数序列，求其中的最长上升子序列的长度。
这一题就是经典的最长上升子序列的问题。

dp[i] 代表为第 i 个数字为结尾的最长上升子序列的长度。

换种表述，dp[i] 代表 [0,i] 范围内，选择数字 nums[i] 可以获得的最长上升子序列的长度。
状态转移方程为 dp[i] = max( 1 + dp[j]) ，其中 j < i && nums[j] > nums[i]，
取所有满足条件的最大值。时间复杂度 O(n^2)

这道题还有一种更快的解法。考虑这样一个问题，我们是否能用一个数组，
记录上升子序列的最末尾的一个数字呢？如果这个数字越小，那么这个子序列往后面添加数字的几率就越大，
那么就越可能成为最长的上升子序列。

举个例子：nums = [4,5,6,3]，它的所有的上升子序列为
    len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
    len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
    len = 3   :      [4, 5, 6]            => tails[2] = 6
其中 tails[i] 中存储的是所有长度为 i + 1 的上升子序列中末尾最小的值。
也很容易证明 tails 数组里面的值一定是递增的(因为我们用末尾的数字描述最长递增子序列)。
既然 tails 是有序的，我们就可以用二分查找的方法去更新这个 tail 数组里面的值。
更新策略如下：(1). 如果 x 比所有的 tails 元素都要大，那么就直接放在末尾，并且 tails 数组长度加一；
(2). 如果 tails[i-1] < x <= tails[i]，则更新 tails[i]，因为 x 更小，更能获得最长上升子序列。
最终 tails 数组的长度即为最长的上升子序列。
这种做法的时间复杂度 O(n log n)。
*/