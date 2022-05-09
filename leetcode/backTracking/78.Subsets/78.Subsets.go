package leetcode

/* 78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。
返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]

*/

// 参考算法模板
func subsets(nums []int) [][]int {
	result := make([][]int, 0) // 保存最终结果
	list := make([]int, 0) // 保存中间结果
	backtracking(nums, 0, list, &result)
	return result
}

func backtracking(nums []int, pos int, list []int, result *[][]int) {
	ans := make([]int, len(list)) // 把临时结果复制出来保存到最终结果
	copy(ans, list)
	*result = append(*result, ans)
	// 选择、处理结果、再撤销选择
	for i := pos; i < len(nums); i++ {
		list = append(list, nums[i])
		backtracking(nums, i+1, list, result)
		list = list[0: len(list)-1]
	}
}

// 参考halfrost 回溯+剪枝
func subsets_v1(nums []int) [][]int {
	c, res := []int{}, [][]int{}
	for k := 0; k <= len(nums); k++ {
		generateSubsets(nums, k, 0, c, &res)
	}
	return res
}

func generateSubsets(nums []int, k, start int, c []int, res *[][]int) {
	if len(c) == k {
		b := make([]int, len(c))
		copy(b, c)
		*res = append(*res, b)
		return
	}

	// i will at most be n - (k - c.size()) + 1
	for i := start; i < len(nums)-(k-len(c))+1; i++ {
		c = append(c, nums[i])
		generateSubsets(nums, k, i+1, c, res)
		c = c[:len(c)-1]
	}
	return
}

/*
解题思路
找出一个集合中的所有子集，空集也算是子集。
且数组中的数字不会出现重复。用 DFS 暴力枚举即可。
这一题和第 90 题，第 491 题类似，可以一起解答和复习。
*/