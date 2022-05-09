package leetcode

import "sort"

/* 47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

// 参考算法模板
func permuteUnique(nums []int) [][]int {
	result := make([][]int, 0)
	list := make([]int, 0)
	// 标记这个元素是否已经添加到结果集
	visited := make([]bool, len(nums))
	sort.Ints(nums)
	backtracking(nums, visited, list, &result)
	return result
}

// nums 输入集合
// visited 当前递归标记过的元素
// list 临时结果集
// result 最终结果
func backtracking(nums []int, visited []bool, list []int, result *[][]int) {
	// 临时结果和输入集合长度一致 才是全排列
	if len(list) == len(nums) {
		subResult := make([]int, len(nums))
		copy(subResult, list)
		*result = append(*result, subResult)
	}

	for i := 0; i < len(nums); i++ {
		// 已经添加过的元素直接跳过
		if visited[i] {
			continue
		}
		// 上一个元素和当前相同，并且没有访问过就跳过
		if i != 0 && nums[i] == nums[i-1] && !visited[i-1]{
			continue
		}
		list = append(list, nums[i])
		visited[i] = true
		backtracking(nums, visited, list, result)
		visited[i] = false
		list = list[: len(list)-1]
	}
}

// DFS + 参考halfrsot
func permuteUnique_v1(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	used, p, res := make([]bool, len(nums)), []int{}, [][]int{}
	sort.Ints(nums) // 这里是去重的关键逻辑
	generatePermutation(nums, 0, p, &res, &used)
	return res
}

func generatePermutation(nums []int, index int, p []int, res *[][]int, used *[]bool) {
	if index == len(nums) {
		temp := make([]int, len(p))
		copy(temp, p)
		*res = append(*res, temp)
		return
	}
	for i := 0; i < len(nums); i++ {
		if !(*used)[i] {
			// // 这里是去重的关键逻辑
			if i > 0 && nums[i] == nums[i-1] && !(*used)[i-1] {
				continue
			}
			(*used)[i] = true
			p = append(p, nums[i])
			generatePermutation(nums, index+1, p, res, used)
			p = p[:len(p)-1]
			(*used)[i] = false
		}
	}
	return
}

/*
 解题思路
这一题是第 46 题的加强版，第 46 题中求数组的排列，数组中元素不重复，
但是这一题中，数组元素会重复，所以需要最终排列出来的结果需要去重。
去重的方法是经典逻辑，将数组排序以后，判断重复元素再做逻辑判断。
其他思路和第 46 题完全一致，DFS 深搜即可。

*/ 