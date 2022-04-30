package leetcode

// import (
// 	"github.com/yuancf1024/algorithm-go/template"
// )

/* 303. 区域和检索 - 数组不可变
给定一个整数数组  nums，求出数组从索引 i 到 j  
(i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：
给定 nums = [-2, 0, 3, -5, 2, -1]，
求和函数为 sumRange()
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。
*/

// //解法一 线段树，sumRange 时间复杂度 O(1)
// // NumArray define
// type NumArray struct {
// 	st *template.SegmentTree
// }

// // Constructor303 define
// func Constructor303(nums []int) NumArray {
// 	st := template.SegmentTree{}
// 	st.Init(nums, func(i, j int) int {
// 		return i + j
// 	})
// 	return NumArray{st: &st}
// }

// // SumRange define
// func (ma *NumArray) SumRange(left int, right int) int {
// 	return ma.st.Query(left, right)
// }

//解法二 prefixSum，sumRange 时间复杂度 O(1)
type NumArray struct {
	prefixSum []int
}

// // Constructor303 define
func Constructor303(nums []int) NumArray {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	return NumArray{prefixSum: nums}
}

// SumRange define
func (this *NumArray) SumRange(left int, right int) int {
	if left > 0 {
		return this.prefixSum[right] - this.prefixSum[left-1]
	}
	return this.prefixSum[right]
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */

/*
解题思路
给出一个数组，数组里面的数都是**不可变**的，
设计一个数据结构能够满足查询数组任意区间内元素的和。
这一题由于数组里面的元素都是**不可变**的，
所以可以用 2 种方式来解答，第一种解法是用 prefixSum，
通过累计和相减的办法来计算区间内的元素和，
初始化的时间复杂度是 O(n)，但是查询区间元素和的时间复杂度是 O(1)。
第二种解法是利用线段树，构建一颗线段树，
父结点内存的是两个子结点的和，初始化建树的时间复杂度是 O(log n)，查询区间元素和的时间复杂度是 O(log n)。
*/