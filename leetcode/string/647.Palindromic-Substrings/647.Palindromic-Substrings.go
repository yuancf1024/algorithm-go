package leetcode

/* 647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"

示例 2：
输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
*/

// 参考剑指offer
func countSubstrings(s string) int {
	if len(s) == 0{
		return 0
	}

	count := 0
	for i := 0; i < len(s); i++ {
		count += countPalindrome(s, i, i)
		count += countPalindrome(s, i, i+1) // 这个地方很巧妙，考虑了奇偶数的差异同时也不会重复计算
	}
	return count
}

func countPalindrome( s string, start, end int) int {
	count := 0
	for (start >= 0 && end < len(s)) && s[start] == s[end] {
		count++
		start--
		end++
	}

	return count
}

/*
分析：前面都是从字符串的两端开始向里移动指针来判断字符串是否是一个回文，
其实也可以换一个方向从字符串的中心开始向两端延伸。
如果存在一个长度为m的回文子字符串，则分别再向该回文的两端延伸一个字符，
并判断回文前后的字符是否相同。如果相同，就找到了一个长度为m+2的回文子字符串。
例如，在字符串"abcba"中，从中间的"c"出发向两端延伸一个字符，
由于"c"前后都是字符'b'，因此找到了一个长度为3的回文子字符串"bcb"。
然后向两端延伸一个字符，由于"bcb"的前后都是字符'a'，因此又找到一个长度为5
的回文子字符串"abcba"。

值得注意的是，回文的长度既可以是奇数，也可以是偶数。
长度为奇数的回文的对称中心只有一个字符，
而长度为偶数的回文的对称中心有两个字符。

上述解法仍然需要两个嵌套的循环，因此时间复杂度是O（n2）。
该解法只用到了若干变量，其空间复杂度是O（1）
*/

// 参考halfrost
func countSubstrings_v1(s string) int {
	res := 0
	for i := 0; i < len(s); i++ {
		res += countPalindrome1(s, i, i)
		res += countPalindrome1(s, i, i+1)
	}
	return res
}

func countPalindrome1(s string, left, right int) int {
	res := 0
	for left >= 0 && right < len(s) {
		if s[left] != s[right] {
			break
		}
		left--
		right++
		res++
	}
	return res
}

/*
暴力解法，从左往右扫一遍字符串，以每个字符做轴，
用中心扩散法，依次遍历计数回文子串。

和剑指offer的思想一致
*/