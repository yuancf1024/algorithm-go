package leetcode

/* 373. 查找和最小的 K 对数字
给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

示例 1:
输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]

解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

示例 2:
输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]

解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

示例 3:
输入: nums1 = [1,2], nums2 = [3], k = 3 
输出: [1,3],[2,3]

解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]
 

提示:
1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 和 nums2 均为升序排列
1 <= k <= 1000
*/

import (
	"sort"
	"container/heap"
)

// 解法1 暴力解法
// leetcode -> runtime: out of memory 运行错误，超出内存限制
func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	size1, size2, res := len(nums1), len(nums2), [][]int{}
	if size1 == 0 || size2 == 0 || k < 0 {
		return nil
	}
	for i := 0; i < size1; i++ {
		for j := 0; j < size2; j++ {
			res = append(res, []int{nums1[i], nums2[j]})
		}
	}
	sort.Slice(res, func(i, j int) bool {
		return res[i][0] + res[i][1] < res[j][0] + res[j][1]
	})
	if len(res) >= k {
		return res[:k]
	}
	return res
}

// 解法2 优先队列
func kSmallestPairs1(nums1 []int, nums2 []int, k int) [][]int {
	result, h := [][]int{}, &minHeap{}
	if len(nums1) == 0 || len(nums2) == 0 || k == 0 {
		return result
	}
	if len(nums1) * len(nums2) < k { // 边界条件
		k = len(nums1) * len(nums2)
	}
	heap.Init(h)
	for _, num := range nums1 {
		heap.Push(h, []int{num, nums2[0], 0})
	}
	for len(result) < k {
		min := heap.Pop(h).([]int)
		result = append(result, min[:2])
		if min[2] < len(nums2)-1 {
			heap.Push(h, []int{min[0], nums2[min[2]+1], min[2] + 1})
		}
	}
	return result
}

type minHeap [][]int

func (h minHeap) Len() int { return len(h)}

func (h minHeap) Less(i, j int) bool { return h[i][0]+h[i][1] < h[j][0]+h[j][1] }

func (h minHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i]}

func (h *minHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *minHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

/*
解题思路
- 给出 2 个数组，和数字 k，要求找到 k 个数值对，数值对两个数的和最小。
- 这一题咋一看可以用二分搜索，两个数组两个组合有 m * n 个数值对。
然后找到最小的和，最大的和，在这个范围内进行二分搜索，每分出一个 mid，
再去找比 mid 小的数值对有多少个，如果个数小于 k 个，
那么在右区间上继续二分，如果个数大于 k 个，那么在左区间上继续二分。
到目前为止，这个思路看似可行。但是每次搜索的数值对是无序的。
这会导致最终出现错误的结果。例如 mid = 10 的时候，小于 10 的和有 22 个，
而 k = 25 。这说明 mid 偏小，mid 增大，mid = 11 的时候，
小于 11 的和有 30 个，而 k = 25 。这时候应该从这 30 个和中取前 25 个。
但是我们遍历数值对的时候，和并不是从小到大排序的。
这时候还需要额外对这 30 个候选值进行排序。这样时间复杂度又增大了。
- 可以先用暴力解法解答。将所有的和都遍历出来，排序以后，取前 k 个。
这个暴力方法可以 AC。
- 本题最优解应该是优先队列。维护一个最小堆。把数值对的和放在这个最小堆中，
不断的 pop 出 k 个最小值到数组中，即为答案。
- 在已排序的矩阵中寻找最 K 小的元素这一系列的题目有：
第 373 题，第 378 题，第 668 题，第 719 题，第 786 题。
*/