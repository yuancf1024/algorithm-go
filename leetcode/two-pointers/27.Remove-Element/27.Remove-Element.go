package leetcode

/* 27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

// 参考代码随想录
func removeElement_v1(nums []int, val int) int {
	// 边界条件
	if len(nums) == 0 {
		return 0
	}
	slow, fast := 0, 0
	for ; fast < len(nums); fast++ {
		if nums[fast] != val {
			nums[slow] = nums[fast]
			slow++
		}
	}
	return slow
}

/**
* 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/

// 参考halfrost
func removeElement(nums []int, val int) int {
	n := len(nums)
	if n == 0 {
		return n
	}

	left, right := 0, 0
	for ; right < n; right++ {
		if nums[right] != val { // left 指针左侧肯定没有val
			nums[left], nums[right] = nums[right], nums[left]
			left++
		}
	}
	return left
}

/*Solution:
思路可参考lc-283

题目大意
给定一个数组 nums 和一个数值 val，
将数组中所有等于 val 的元素删除，并返回剩余的元素个数。

解题思路
这道题和第 283 题很像。这道题和第 283 题基本一致，
283 题是删除 0，这一题是给定的一个 val，实质是一样的。

这里数组的删除并不是真的删除，只是将删除的元素移动到数组后面的空间内，
然后返回数组实际剩余的元素个数，OJ 最终判断题目的时候会读取数组剩余个数的元素进行输出。
*/

func removeElement1(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			if i != j {
				nums[i], nums[j] = nums[j], nums[i]
			}
			j++
		}
	}
	return j
}
