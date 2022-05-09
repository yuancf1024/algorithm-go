package leetcode

import "sort"

/* 90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，
请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。


示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/

// 参考算法模板
func subsetsWithDup(nums []int) [][]int {
	result := make([][]int, 0) // 保存最终结果
	list := make([]int, 0) // 保存中间结果
	// 先排序
	sort.Ints(nums)
	backtracking(nums, 0, list, &result)
	return result
}
// nums 给定的集合
// pos 下次添加到集合中的元素位置索引
// list 临时结果集合(每次需要复制保存)
// result 最终结果
func backtracking(nums []int, pos int, list []int, result *[][]int) {
	ans := make([]int, len(list))
	copy(ans, list)
	*result = append(*result, ans)
	// 选择时需要剪枝,处理,撤销选择
	for i := pos; i < len(nums); i++ {
		// 排序之后,如果再遇到重复元素,则不选择此元素
		if i != pos && nums[i] == nums[i-1] {
			continue
		}
		list = append(list, nums[i])
		backtracking(nums, i+1, list, result)
		list = list[: len(list)-1]
	}
}

// 参考halfrost
func subsetsWithDup_v1(nums []int) [][]int {
	c, res := []int{}, [][]int{}
	sort.Ints(nums) // 这里是去重的关键逻辑
	for k := 0; k <= len(nums); k++ {
		generateSubsetWithDup(nums, k, 0, c, &res)
	}
	return res
}

func generateSubsetWithDup(nums []int, k, start int, c []int, res *[][]int) {
	if len(c) == k {
		b := make([]int, len(c))
		copy(b, c)
		*res = append(*res, b)
		return
	}

	// i will at most be n - (k - c.size()) + 1
	for i := start; i < len(nums)-(k-len(c))+1; i++ {
		if i > start && nums[i] == nums[i-1] { // 这里是去重的关键逻辑,本次不取重复数字，下次循环可能会取重复数字
			continue
		}
		c = append(c, nums[i])
		generateSubsetWithDup(nums, k, i+1, c, res)
		c = c[:len(c)-1]
	}
	return
}

/*
这一题是第 78 题的加强版，比第 78 题多了一个条件，
数组中的数字会出现重复。
解题方法依旧是 DFS，需要在回溯的过程中加上一些判断。
这一题和第 78 题，第 491 题类似，可以一起解答和复习。
*/