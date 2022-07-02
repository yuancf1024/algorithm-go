package leetcode

/* 540. 有序数组中的单一元素
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，
唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

示例 1:
输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:
输入: nums =  [3,3,7,7,10,11,11]
输出: 10

提示:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

// 参考halfrost
func singleNonDuplicate(nums []int) int {
	left, right := 0, len(nums)-1
	// 考虑边界条件
	if len(nums) == 1 {
		return nums[left]
	}
	for left < right {
		mid := left + ((right - left) >> 1)
		if mid%2 == 0 { // mid为偶数的情况
			if nums[mid] == nums[mid+1] { // idx左边的偶数下标x有 nums[x] == nums[x + 1]
				left = mid + 1 // 此时位于目标值的左边界，需要收缩左边界
			} else {
				right = mid
			}
		} else { // mid为奇数的情况
			if nums[mid] == nums[mid-1] { // idx左边的奇数下标x有 nums[x] == nums[x - 1]
				left = mid + 1 // 此时位于目标值的左边界，需要收缩左边界
			} else {
				right = mid
			}
		}
	}
	return nums[left]
}

/*
解题思路
假设下标idx是单独的数字,
- idx左边的偶数下标x有 nums[x] == nums[x + 1],
- idx右边的奇数下标y有 nums[y] == nums[y + 1],
可以根据此特性用二分查找idx对应的值

本题的二分，如果采用left <= right 的形式，无法求解边界case[1, 1, 2]
因此采用 left < right 的形式
*/
