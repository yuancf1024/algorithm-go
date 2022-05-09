package leetcode

/* 46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。
你可以 按任意顺序 返回答案。

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
*/

// 参考算法模板
func permute(nums []int) [][]int {
	result := make([][]int, 0)
	list := make([]int, 0)
	// 标记这个元素是否已经添加到结果集
	visited := make([]bool, len(nums))
	backtracking(nums, visited, list, &result)
	return result
}

// nums 输入集合
// visited 当前递归标记过的元素
// list 临时结果集(路径)
// result 最终结果
func backtracking(nums []int, visited []bool, list []int, result *[][]int) {
	// 返回条件：临时结果和输入集合长度一致 才是全排列
	if len(list) == len(nums) {
		ans := make([]int, len(list))
		copy(ans, list)
		*result = append(*result, ans)
		return
	}

	for i := 0; i < len(nums); i++ {
		// 已经添加过的元素,直接跳过
		if visited[i] {
			continue
		}
		// 添加元素
		list = append(list, nums[i])
		visited[i] = true
		backtracking(nums, visited, list, result)
		// 移除元素
		visited[i] = false
		list = list[:len(list)-1]
	}
}

/*
思路：需要记录已经选择过的元素，满足条件的结果才进行返回
*/

// DFS + 参考halfrsot
func permute_v1(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	used, p, res := make([]bool, len(nums)), []int{}, [][]int{}
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
			(*used)[i] = true
			p = append(p, nums[i])
			generatePermutation(nums, index+1, p, res, used)
			p = p[:len(p)-1]
			(*used)[i] = false
		}
	}
	return
}