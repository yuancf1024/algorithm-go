package leetcode

/* 77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// 参考代码随想录
func combine_v1(n int, k int) [][]int {
	res := [][]int{} // // 存放符合条件结果的集合
	track := []int{} // 存放符合条件的结果
	if n <= 0 || k <= 0 || k > n { // 处理特殊边界
		return res
	}
	backtracking(n, k, 1, track, &res) // res 没有全局声明就需要传址
	return res
}

func backtracking(n, k, start int, track []int, res *[][]int) {
	if len(track) == k { // 满足要求的结果添加进res
		tmp := make([]int, len(track))
		copy(tmp, track)
		*res = append(*res, tmp)
		return
	}

	for i := start; i <= n-(k-len(track))+1; i++ {
		track = append(track, i) // 处理节点
		backtracking(n, k, i+1, track, res) // 递归
		track = track[:len(track)-1] // // 回溯，撤销处理的节点
	}
}

// 参考halfrost DFS+剪枝
func combine(n int, k int) [][]int {
	if n <= 0 || k <= 0 || k > n {
		return [][]int{}
	}
	c, res := []int{}, [][]int{} // res 存放符合条件结果的集合
	// c 存放符合条件的结果
	generateCombinations(n, k, 1, c, &res) // 
	return res
}

func generateCombinations(n, k, start int, c []int, res *[][]int) {
	if len(c) == k {
		b := make([]int, len(c))
		copy(b, c)
		*res = append(*res, b)
		return
	}

	// i will at most be n - (k - c.size()) + 1 剪枝
	// 初始时，n=4,k=2,c=0,4-(2-0)+1=3, 从3开始搜索是合理的
	for i := start; i <= n-(k-len(c))+1; i++ {
		c = append(c, i)
		generateCombinations(n, k, i+1, c, res)
		c = c[:len(c)-1]
	}
	// return
}

/*
题目大意
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

解题思路
计算排列组合中的组合，用 DFS 深搜即可，注意剪枝
*/