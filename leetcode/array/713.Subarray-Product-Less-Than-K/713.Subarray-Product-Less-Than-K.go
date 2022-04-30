package leetcode

/* 713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，
请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 

示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
*/

func numSubarrayProductLessThanK(nums []int, k int) int {

	res, left, right, prod := 0, 0, 0, 1
	for left < len(nums) {
		if right < len(nums) && prod*nums[right] < k { // 开始是右窗口右移
			prod = prod * nums[right]
			right++
		} else if left == right { // 左右窗口相等时，同时右移
			left++
			right++
		} else { // 左窗口右移
			res += right - left
			prod = prod / nums[left]
			left++
		}
	}
	return res
}

/*
题目大意
给出一个数组，要求在输出符合条件的窗口数，条件是，
窗口中所有数字乘积小于 K 。

解题思路
这道题也是滑动窗口的题目，在窗口滑动的过程中不断累乘，
直到乘积大于 k，大于 k 的时候就缩小左窗口。
有一种情况还需要单独处理一下，
即类似 [100] 这种情况。这种情况窗口内乘积等于 k，
不小于 k，左边窗口等于右窗口，
这个时候需要左窗口和右窗口同时右移。
*/