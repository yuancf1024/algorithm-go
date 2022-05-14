package leetcode

/* 125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，
可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
示例 2:

输入: "race a car"
输出: false
解释："raceacar" 不是回文串
*/

import "strings"

// // 这种实现无法处理字符串里面含右非字符的情况
// func isPalindrome(s string) bool {
// 	res := true
// 	nums := []byte{}
// 	// n := 0
// 	for i := 0; i < len(s); i++ {
// 		if (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') {
// 			nums = append(nums, s[i])
// 			// n++
// 		}
// 	}

// 	slow, fast := 0, len(nums)
// 	for slow <= fast {
// 		if nums[slow] == nums[fast] {
// 			fast--
// 			slow++
// 		} else {
// 			res = false
// 			break
// 		}
// 	}
// 	return res
// }

func isPalindrome(s string) bool {
	s = strings.ToLower(s) // 字符串全部转为小写
	i, j := 0, len(s)-1 // 指向首尾字符
	for i < j {
		for i < j && !isChar(s[i]) { // s[i]不是字符，i++
			i++
		}
		for i < j && !isChar(s[j]) { // s[j]不是字符，j--
			j--
		}
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

// 判断c是否是字符或者数字
func isChar(c byte) bool {
	if ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') {
		return true
	}
	return false
}