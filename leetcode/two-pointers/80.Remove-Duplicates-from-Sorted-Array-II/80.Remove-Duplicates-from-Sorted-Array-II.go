package leetcode

/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，
使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 
并在使用 O(1) 额外空间的条件下完成。
*/

func removeDuplicates(nums []int) int {
	n := len(nums)
	if n == 1 {
		return n
	}

	left, right := 1, 1
	for ; right < n; right++ {
		if right < 2 || nums[left - 2] != nums[right] {
			// left-2，是因为left、right指针未分离前，它们指向的位置相同
			// 重复元素最多出现2次，后面从left开始覆盖，仅保留2个相同元素
			nums[left] = nums[right]
			left++
		}
	}
	return left
}

// 更简洁的实现
func removeDuplicates1(nums []int) int {
	slow := 0
	for fast, v := range nums {
		if fast < 2 || nums[slow-2] != v {
			nums[slow] = v
			slow++
		}
	}
	return slow
}