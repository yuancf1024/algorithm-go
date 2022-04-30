package leetcode

/* 209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 
[numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/

func minSubArrayLen(target int, nums []int) int {
	left, sum, res := 0, 0, len(nums)+1
	for right, v := range nums {
		sum += v
		for sum >= target {
			res = min(res, right-left+1)
			sum -= nums[left]
			left++
		}
	}
	if res == len(nums) + 1 {
		return 0
	}
	return res
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
/*
题目大意
给定一个整型数组和一个数字 s，找到数组中最短的一个连续子数组，
使得连续子数组的数字之和 sum>=s，
返回最短的连续子数组的返回值。

解题思路
这一题的解题思路是用滑动窗口。
在滑动窗口 [i,j]之间不断往后移动，
如果总和小于 s，就扩大右边界 j，不断加入右边的值，
直到 sum > s，之和再缩小 i 的左边界，
不断缩小直到 sum < s，这时候右边界又可以往右移动。
以此类推。
*/