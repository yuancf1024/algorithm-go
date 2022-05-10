package leetcode

/* 132. 分割回文串 II
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。
示例 1：

输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
示例 2：

输入：s = "a"
输出：0
示例 3：

输入：s = "ab"
输出：1

*/

// 参考算法模板
func minCut(s string) int {
	// state: f[i] "前i"个字符组成的子字符串需要最少几次cut(个数-1为索引)
	// function: f[i] = MIN{f[j]+1}, j < i && [j+1 ~ i] 这一段是一个回文串
	// initialize: f[i] = i - 1 (f[0] = -1)
	// answer: f[s.length()]
	if len(s) == 0 || len(s) == 1 {
		return 0
	}
	f := make([]int, len(s)+1)
	f[0] = -1
	f[1] = 0
	for i := 1; i <= len(s); i++ {
		f[i] = i-1
		for j := 0; j < i; j++ {
			if isPalindrome(s, j, i-1) {
				f[i] = min(f[i], f[j]+1)
			}
		}
	}
	return f[len(s)]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func isPalindrome(s string, i, j int) bool {
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}



