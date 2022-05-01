package leetcode

/* 26.删除排序数组中的重复项
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，
使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
*/

// 双指针 + 覆盖原数组
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

这道题和第 27 题很像。这道题和第 283 题，第 27 题基本一致，
283 题是删除 0，27 题是删除指定元素，这一题是删除重复元素，
实质是一样的。

这里数组的删除并不是真的删除，只是将删除的元素移动到数组后面的空间内，
然后返回数组实际剩余的元素个数，OJ 最终判断题目的时候会读取数组剩余个数的元素进行输出。
*/

// 该解法不是很好理解，直接采用上面的实现理解即可
func removeDuplicates1(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	last, finder := 0, 0
	for last < n - 1 {
		for nums[finder] == nums[last] {
			finder++
			if finder == n {
				return last + 1
			}
		}
		nums[last+1] = nums[finder]
		last++
	}
	return last + 1
}
