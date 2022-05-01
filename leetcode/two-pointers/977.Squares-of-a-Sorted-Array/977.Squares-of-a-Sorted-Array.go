package leetcode

/* 977.有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，
返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/

// 双指针 自己写的
func sortedSquares(nums []int) []int {
	n := len(nums)
	res := make([]int, n)
	
	p1, p2 := 0, n-1
	for k := n; p1 <= p2; k-- {
		if square(nums[p1]) < square(nums[p2]) { 
			// 这里从后往前比较更好，利用了nums升序的特点
			// res = append(res, square(nums[p1]))
			res[k-1] = square(nums[p2])
			p2--
		} else {
			res[k-1] = square(nums[p1])
			p1++
		}
	}
	return res
}

func square(x int) int {
	return x * x
}

/*
时间复杂度：O(n)，其中 nn 是数组 nums 的长度。

空间复杂度：O(1)。除了存储答案的数组以外，我们只需要维护常量空间。
*/

// halfrost 大佬写的双指针
func sortedSquares1(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	i, j := 0, n-1
	for k := n-1; i <= j; k-- {
		if nums[i] * nums[i] > nums[j] * nums[j] {
			ans[k] = nums[i] * nums[i]
			i++
		} else {
			ans[k] = nums[j] * nums[j]
			j--
		}
	}
	return ans
}

/*
这一题由于原数组是有序的，所以要尽量利用这一特点来减少时间复杂度。

最终返回的数组，最后一位，是最大值，这个值应该是由原数组最大值，
或者最小值得来的，所以可以从数组的最后一位开始排列最终数组。
用 2 个指针分别指向原数组的首尾，分别计算平方值，
然后比较两者大小，大的放在最终数组的后面。
然后大的一个指针移动。直至两个指针相撞，最终数组就排列完成了。

**这种方法无需处理某一指针移动至边界的情况**
*/