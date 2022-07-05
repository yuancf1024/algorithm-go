package leetcode

/* 22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，
用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]

提示：
1 <= n <= 8
*/

func generateParenthesis(n int) []string {
	if n == 0 {
		return []string{}
	}
	res := []string{}
	findGenerateParenthesis(n, n, "", &res)
	return res
}

func findGenerateParenthesis(lindex, rindex int, str string, res *[]string) {
	if lindex == 0 && rindex == 0 {
		*res = append(*res, str)
		return
	}
	if lindex > 0 {
		findGenerateParenthesis(lindex-1, rindex, str+"(", res)
	}
	if rindex > 0 && lindex < rindex {
		findGenerateParenthesis(lindex, rindex-1, str+")", res)
	}
}

/*
解题思路
- 这道题乍一看需要判断括号是否匹配的问题，如果真的判断了，那时间复杂度就到 
O(n * 2^n)了，虽然也可以 AC，但是时间复杂度巨高。
- 这道题实际上不需要判断括号是否匹配的问题。因为在 DFS 回溯的过程中，
会让 ( 和 ) 成对的匹配上的。
*/