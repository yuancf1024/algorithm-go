package leetcode

/* 215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，
而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

提示：
1 <= k <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
*/

import (
	"sort"
	"math/rand"
)

// 解法1 排序，排序的方法反而速度是最快的
func findKthLargest(nums []int, k int) int {
	sort.Ints(nums)
	return nums[len(nums)-k]
}

// 解法二 这个方法的理论依据是 partition 得到的点的下标就是最终排序之后的下标，
// 根据这个下标，我们可以判断第 K 大的数在哪里
// 时间复杂度 O(n)，空间复杂度 O(log n)，
// 最坏时间复杂度为 O(n^2)，空间复杂度 O(n)
func findKthLargest1(nums []int, k int) int {
	m := len(nums) - k + 1 // mth smallest, from 1..len(nums)
	return selectSmallest(nums, 0, len(nums)-1, m)
}

func selectSmallest(nums []int, l, r, i int) int {
	if l >= r {
		return nums[l]
	}
	q := partition(nums, l, r)
	k := q - l + 1 // 转化一下
	if k == i {
		return nums[q]
	}
	if i < k { // k是partition后的元素，i是原题中的k
		// 执行一次 partition 操作以后，元素下标比 K 大，在左边的区间继续执行 partition 操作
		return selectSmallest(nums, l, q-1, i)
	} else {
		// 执行一次 partition 操作以后，元素下标比 K 小，在后边的区间继续执行 partition 操作
		return selectSmallest(nums, q+1, r, i-k)
	}
}

func partition( nums []int, l, r int) int {
	k := l + rand.Intn(r-l+1) // 此处为优化，使得时间复杂度期望降为 O(n)，最坏时间复杂度为 O(n^2)
	nums[k], nums[r] = nums[r], nums[k]
	i := l - 1
	// nums[l..i] <= nums[r]
	// nums[i+1..j-1] > nums[r]
	for j := l; j < r; j++ {
		if nums[j] <= nums[r] {
			i++
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	nums[i+1], nums[r] = nums[r], nums[i+1]
	return i + 1
}


/*
题目大意
找出数组中第 K 大的元素。这一题非常经典。
可以用 O(n) 的时间复杂度实现。

解题思路
在快排的 partition 操作中，每次 partition 操作结束都会返回一个点，
这个标定点的下标和最终排序之后有序数组中这个元素所在的下标是一致的。
利用这个特性，我们可以不断的划分数组区间，最终找到第 K 大的元素。
执行一次 partition 操作以后，如果这个元素的下标比 K 小，
那么接着就在后边的区间继续执行 partition 操作；
如果这个元素的下标比 K 大，那么就在左边的区间继续执行 partition 操作；
如果相等就直接输出这个下标对应的数组元素即可。
*/

/* 面试题40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，
则最小的4个数字是1、2、3、4。
 
示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]
 
限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

*/
// 扩展题 剑指 Offer 40. 最小的 k 个数
func getLeastNumbers(arr []int, k int) []int {
	return selectSmallest1(arr, 0, len(arr)-1, k)[:k]
}

// 和 selectSmallest 实现完全一致，只是返回值不用再截取了，直接返回 nums 即可
func selectSmallest1(nums []int, l, r, i int) []int {
	if l >= r {
		return nums
	}
	q := partition(nums, l, r)
	k := q - l + 1 // 转化一下
	if k == i {
		return nums
	}
	if i < k { // k是partition后的元素，i是原题中的k
		// 执行一次 partition 操作以后，元素下标比 K 大，在左边的区间继续执行 partition 操作
		return selectSmallest1(nums, l, q-1, i)
	} else {
		// 执行一次 partition 操作以后，元素下标比 K 小，在后边的区间继续执行 partition 操作
		return selectSmallest1(nums, q+1, r, i-k)
	}
}

// partition 函数同上