package leetcode

/* 131. 分割回文串
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。
返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]
*/

// 参考halfrost DFS
func partition131(s string) [][]string {
	result := [][]string{}
	size := len(s)
	if size == 0 {
		return result
	}
	current := make([]string, 0, size)
	dfs131(s, 0, current, &result)
	return result
}

func dfs131(s string, idx int, cur []string, result *[][]string) {
	start, end := idx, len(s)
	if start == end {
		temp := make([]string, len(cur))
		copy(temp, cur)
		*result = append(*result, temp)
		return
	}
	for i := start; i < end; i++ {
		if isPal(s, start, i) {
			dfs131(s, i+1, append(cur, s[start:i+1]), result)
		}
	}
}

func isPal(str string, s, e int) bool {
	for s < e {
		if str[s] != str[e] {
			return false
		}
		s++
		e--
	}
	return true
}
/*
解题思路
要求输出一个字符串可以被拆成回文串的所有解，DFS 递归求解即可。
*/