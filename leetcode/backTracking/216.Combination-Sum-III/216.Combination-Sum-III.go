package leetcode

/* 216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，
组合可以以任何顺序返回。

示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
示例 3:

输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，
因为10 > 1，没有有效的组合。
*/


// 参考代码回想录 回溯+剪枝优化
func combinationSum3(k int, n int) [][]int {
	var track []int // 遍历路径
	var result [][]int // 存放结果集
	backtracking(n, k, 1, &track, &result)
	return result
}

func backtracking(n, k, startIndex int, track *[]int, result *[][]int) {
	if len(*track) == k {
		var sum int
		tmp := make([]int, k)
		for k, v := range *track {
			sum += v
			tmp[k] = v
		}
		if sum == n {
			*result = append(*result, tmp)
		}
		return
	}
	for i := startIndex; i <= 9-(k-len(*track))+1; i++ { //减枝（k-len(*track)表示还剩多少个可填充的元素）
		*track = append(*track, i) // 记录路径
		backtracking(n, k, i+1, track, result) // 递归
		*track = (*track)[:len(*track)-1] // 回溯
	}
}

// 参考halfrost
func combinationSum3_v1(k int, n int) [][]int {
	if k == 0 {
		return [][]int{}
	}
	c, res := []int{}, [][]int{}
	findcombinationSum3(k, n, 1, c, &res)
	return res
}

func findcombinationSum3(k, target, index int, c []int, res *[][]int) {
	if target == 0 {
		if len(c) == k {
			b := make([]int, len(c))
			copy(b, c)
			*res = append(*res, b)
		}
		return
	}
	for i := index; i < 10; i++ {
		if target >= i {
			c = append(c, i)
			findcombinationSum3(k, target-i, i+1, c, res)
			c = c[:len(c)-1]
		}
	}
}

/*
解题思路
这一题比第 39 题还要简单一些，
在第 39 题上稍加改动就可以解出这一道题。
第 39 题是给出数组，这一道题数组是固定死的 [1,2,3,4,5,6,7,8,9]，
并且数字不能重复使用。
*/