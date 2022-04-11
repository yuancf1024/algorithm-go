package leetcode

/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，
使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
*/

func removeDuplicates(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}

	left, right := 1, 1
	for ; right < n; right++ {
		if nums[right] != nums[right-1] {
			nums[left] = nums[right]
			left++
		}
	}
	return left
}

/*Solution:
本题和lc-283移动0元素的区别：
- lc-283 把0元素移动到末尾，交换元素即可
- 本题移除重复元素，需要对原数组的元素进行覆盖
*/