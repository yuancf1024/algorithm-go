package leetcode

/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/

// 这种实现有缺陷：无法处理特殊案例：[-1] 2
// 方法1：achieve 时间复杂度 O(n)，空间复杂度 O(n)
// func rotate(nums []int, k int)  {
// 	n := len(nums)
// 	res := make([]int, n)

// 	for i := 0; i < k; i++ {
// 		res[i] = nums[n-k+i] // 无法处理特殊案例：[-1] 2
// 	}
// 	for j := 0; j < n - k; j++ {
// 		res[k+j] = nums[j]
// 	}
// 	copy(nums, res)
// }
/*
时间复杂度：遍历了一遍数组nums,时间复杂度为O(n)
空间复杂度：新建了一个数组，空间复杂度为O(n)
*/

// 方法1更优雅的实现
func rotate1(nums []int, k int) {
	n := len(nums)
	newNums := make([]int, n)
	for i, v := range nums {
		newNums[(i + k) % n] = v // 非常巧妙实现了把元素向后移动k步，末尾移动到前面
	}
	copy(nums, newNums)
}
/*
使用一个额外的数组，先将原数组下标为 i 的元素移动到 (i+k) mod n 
的位置，再将剩下的元素拷贝回来即可。
*/

// 更优解：方法二 时间复杂度 O(n)，空间复杂度 O(1)
func rotate2(nums []int, k int) {
	k %= len(nums)
	reverse(nums)
	reverse(nums[:k])
	reverse(nums[k:])
	
}

func reverse(a []int) {
	for i, n := 0, len(a); i < n / 2; i++ {
		a[i], a[n-1-i] = a[n-1-i], a[i]
	}
}

/* 方法非常巧妙

由于题目要求不能使用额外的空间，所以本题最佳解法不是上面的方法。
翻转最终态是，末尾 k mod n 个元素移动至了数组头部，
剩下的元素右移 k mod n 个位置至最尾部。确定了最终态以后再变换就很容易。
先将数组中所有元素从头到尾翻转一次，尾部的所有元素都到了头部，
然后再将 [0,(k mod n) − 1] 区间内的元素翻转一次，
最后再将 [k mod n, n − 1] 区间内的元素翻转一次，即可满足题目要求。
*/