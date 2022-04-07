package leetcode


// Source : https://leetcode-cn.com/problems/search-insert-position/
// Author : @yuancf1024
// Date   : 2022-04-07

// 二分法的变种
func searchInsert1(nums []int, target int) int {
	n := len(nums)

	var position int
	low, high := 0, n - 1

    if nums[0] > target {
        return 0
    }

	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] > target {
			high = mid - 1
		} else if nums[mid] < target {
			low = mid + 1
		} else if nums[mid] == target {
			return mid
		}
		position = mid + 1
	}
	return position	
}
// 通过测试用例：55 / 64 刚好把测试用例给调过

// 在有序数组中找到最后一个比 target 小的元素
func searchInsert(nums []int, target int) int {
	low, high := 0, len(nums) - 1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] >= target {
			high = mid - 1
		} else {
			if (mid == len(nums) - 1 || nums[mid+1] >= target) {
				// 增加了新的边界条件处理
				return mid + 1
			}
			low = mid + 1
		}
	}
	return 0
}

/* 参考@halfrost
解题思路
- 给出一个已经从小到大排序后的数组，要求在数组中找到插入 target 元素的位置。
- 这一题是经典的二分搜索的变种题，**在有序数组中找到最后一个比 target 小的元素。**
*/
