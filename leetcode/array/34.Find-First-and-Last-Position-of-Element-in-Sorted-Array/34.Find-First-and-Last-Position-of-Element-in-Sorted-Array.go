package leetcode

/* 34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。
找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
*/

// 2022-04-25自己实现
// func searchRange(nums []int, target int) []int {
// 	left, right := 0, len(nums) - 1
// 	res := make([]int, 0)
// 	for left <= right {
// 		mid := left + ((right - left) >> 1)
// 		if nums[mid] > target {
// 			right = mid - 1
// 		} else if nums[mid] < target {
// 			left = mid + 1
// 		} else {

// 		}
// 	}
// 	return []int{-1, -1}
// }

/*
解题思路
给出一个有序数组 nums 和一个数 target，要求在数组中找到第一个和
这个元素相等的元素下标，最后一个和这个元素相等的元素下标。

这一题是经典的二分搜索变种题。二分搜索有 4 大基础变种题：
- 查找第一个值等于给定值的元素
- 查找最后一个值等于给定值的元素
- 查找第一个大于等于给定值的元素
- 查找最后一个小于等于给定值的元素
这一题的解题思路可以分别利用变种 1 和变种 2 的解法就可以做出此题。
或者用一次变种 1 的方法，然后循环往后找到最后一个与给定值相等的元素。
不过后者这种方法可能会使时间复杂度下降到 O(n)，
因为有可能数组中 n 个元素都和给定元素相同。
(4 大基础变种的实现见代码)
*/

func searchRange(nums []int, target int) []int {
	return []int{searchFirstEqualElement(nums, target), searchLastEqualElement(nums, target)}
}

// 二分查找第一个与target相等的元素，时间复杂度O(logn)
func searchFirstEqualElement(nums []int, target int) int {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] > target {
			high = mid - 1
		} else if nums[mid] < target {
			low = mid + 1
		} else { // mid == target时的边界条件判断
			if (mid == 0) || (nums[mid-1] != target) { // 找到第一个与 target 相等的元素
				// mid为第一个元素直接返回 or mid左边邻近元素不等于target也直接返回
				return mid
			}
			high = mid - 1 // 向左侧收缩
		}
	}
	return -1
}

// 二分查找最后一个与target相等的元素，时间复杂度O(logn)
func searchLastEqualElement(nums []int, target int) int {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] > target {
			high = mid - 1
		} else if nums[mid] < target {
			low = mid + 1
		} else { // mid == target时的边界条件判断
			if (mid == len(nums)-1) || (nums[mid+1] != target) { // 找到最后一个与 target 相等的元素
				// mid为最后一个元素直接返回 or mid右边邻近元素不等于target也直接返回
				return mid
			}
			low = mid + 1 // 向右侧收缩
		}
	}
	return -1
}

// 二分查找第一个大于等于 target 的元素，时间复杂度 O(logn)
func searchFirstGreaterElement(nums []int, target int) int {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] >= target { // 找到第一个大于等于 target 的元素
			if (mid == 0) || (nums[mid-1] < target) { // 处理边界条件
				// mid 为第一个元素 or mid左边相邻元素小于target
				return mid
			}
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return -1
}


// 二分查找最后一个小于等于 target 的元素，时间复杂度 O(logn)
func searchFirstSmallerElement(nums []int, target int) int {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] <= target { // 找到最后一个小于等于 target 的元素
			if (mid == len(nums)-1) || (nums[mid+1] > target) { // 处理边界条件
				// mid 为最后一个元素 or mid左=右边相邻元素大于target
				return mid
			}
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return -1
}