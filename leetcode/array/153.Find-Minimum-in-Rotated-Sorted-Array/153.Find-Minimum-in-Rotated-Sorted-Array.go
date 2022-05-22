package leetcode

/* 153. 寻找旋转排序数组中的最小值
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，
得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，
并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。

示例 2：
输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。

示例 3：
输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
*/

// 解法1 二分 不太好理解
func findMin(nums []int) int {
	low, high := 0, len(nums)-1
	for low < high {
		if nums[low] < nums[high] { // 此时数组为升序，输出第一个元素即可
			return nums[low]
		}
		mid := low + ((high - low) >> 1)
		if nums[mid] >= nums[low] { // 说明mid处的值还没有达到最大，mid在最小值的左边，向右缩小左边界
			low = mid + 1
		} else { // 说明mid在最小值的右边，此刻向左收缩右边界
			high = mid
		}
	}
	return nums[low]
}

// 解法2 暴力 时间复杂度 O(n)
func findMin2(nums []int) int {
	min := nums[0]
	for _, num := range nums[1:] {
		if min > num {
			min = num
		}
	}
	return min
}

// 解法3 便于理解的二分法
func findMin1(nums []int) int {
	if len(nums) == 0 { // 边界条件：nums无元素
		return 0
	}
	if len(nums) == 1 { // 边界条件：nums仅有一个元素
		return nums[0]
	}
	if nums[len(nums)-1] > nums[0] { // 由于事先排序了，如果最后一个元素大于第一个元素，说明没有发生旋转
		return nums[0]
	}

	low, high := 0, len(nums)-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[low] < nums[high] {
			return nums[low]
		}
		if (mid == len(nums)-1 && nums[mid-1] > nums[mid] || (mid < len(nums)-1) && mid > 0 && nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]) {
			return nums[mid]
		}
		if nums[mid] > nums[low] && nums[low] > nums[high] { // mid 在数值大的一部分区间里
			low = mid + 1
		} else if nums[mid] < nums[low] && nums[low] > nums[high] { // mid 在数值小的一部分区间里
			high = mid - 1
		} else {
			if nums[low] == nums[mid] {
				low++
			}
			if nums[high] == nums[mid] {
				high--
			}
		}
	}
	return -1
}

/*
解题思路

数组旋转1次，相当于将数组最后一个元素挪到第一个位置

给出一个原本从小到大排序过的数组，但是在某一个分割点上，
把数组切分后的两部分对调位置，数值偏大的放到了数组的前部。
求这个数组中最小的元素。
求数组最小的元素其实就是找分割点，前一个数比当前数大，后一个数比当前数也要大。
可以用二分搜索查找，需要查找的两个有序区间。时间复杂度 O(log n)。
这一题也可以用暴力解法，从头开始遍历，动态维护一个最小值即可，时间复杂度 O(n)。
*/