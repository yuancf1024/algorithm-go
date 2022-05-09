package leetcode

import "sort"
/* 39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。
如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []
*/

// 参考halfrost
func combinationSum(candidates []int, target int) [][]int {
	if len(candidates) == 0 {
		return [][]int{}
	}
	c, res := []int{}, [][]int{}
	sort.Ints(candidates)
	findcombinationSum(candidates, target, 0, c, &res)
	return res
}

func findcombinationSum(nums []int, target, index int, c []int, res *[][]int) {
	if target <= 0 {
		if target == 0 {
			b := make([]int, len(c))
			copy(b, c)
			*res = append(*res, b)
		}
		return
	}
	for i := index; i < len(nums); i++ {
		if nums[i] > target { // 这里可以剪枝优化
			break
		}
		c = append(c, nums[i])
		findcombinationSum(nums, target-nums[i], i, c, res) // 注意这里迭代的时候 index 依旧不变，因为一个元素可以取多次
		c = c[:len(c)-1]
	}
}

// 参考代码随想录
// 主要在于递归中传递下一个数字
func combinationSum_v1(candidates []int, target int) [][]int {
	var track []int
	var res [][]int
	backtracking(0, 0, target, candidates, track, &res)
	return res
}

func backtracking(startIndex, sum, target int, candiates, track []int, res *[][]int) {
	// 终止条件
	if sum == target {
		tmp := make([]int, len(track))
		copy(tmp, track) // 拷贝
		*res = append(*res, tmp) // 放入结果集
		return
	}
	if sum > target {
		return
	}
	// 回溯
	for i := startIndex; i < len(candiates); i++ {
		// 更新路径集合和sum
		track = append(track, candiates[i])
		sum += candiates[i]
		// 递归
		backtracking(i, sum, target, candiates, track, res)
		// 回溯
		track = track[:len(track)-1]
		sum -= candiates[i]
	}
}

/*
解题思路
题目要求出总和为 sum 的所有组合，组合需要去重。
这一题和第 47 题类似，只不过元素可以反复使用。
*/