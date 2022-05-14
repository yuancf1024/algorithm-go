package leetcode

/* 680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: s = "aba"
输出: true

示例 2:
输入: s = "abca"
输出: true
解释: 你可以删除c字符。

示例 3:
输入: s = "abc"
输出: false
*/

func validPalindrome(s string) bool {
	start, end := 0, len(s)-1
	for ; start < len(s) / 2; {
		if s[start] != s[end] {
			break
		}
		start++
		end--
	}
	return start == len(s) / 2 || isPalindrome(s, start, end - 1) || isPalindrome(s, start + 1, end)
}

func isPalindrome(s string, start, end int) bool {
	for start < end {
		if s[start] != s[end] {
			break
		}
		start++
		end--
	}
	return start >= end
}

/*
剑指offer
本题还是从字符串的两端开始向里逐步比较两个字符是不是相同。
如果相同，则继续向里移动指针比较里面的两个字符。
如果不相同，按照题目的要求，在删除一个字符之后再比较其他的字符就能够
形成一个回文。由于事先不知道应该删除两个不同字符中的哪一个，
因此两个字符都可以进行尝试。
*/