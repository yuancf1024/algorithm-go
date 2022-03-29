package leetcode

/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，
如果目标值存在返回下标，否则返回 -1。

提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
*/

/*
自己实现的二分法，还可以提高的地方：
	1. 先考虑特殊情况；
	2. 简化条件判断（利用对立性）
*/

// 自己写的
func search704_v1(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		middle := left + ((right - left) >> 1)
		if nums[middle] > target {
			right = middle - 1
		} else if nums[middle] < target {
			left = middle + 1
		} else {
			return middle
		}
	}
	return -1
}

// halfrost大佬写的
func search704(nums []int, target int) int {
	low, high := 0, len(nums) - 1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return -1
}