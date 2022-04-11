package leetcode

import "strings"

/*
给定一个字符串 s ，
你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
*/

func reverseWords(s string) string {
    ss := strings.Split(s, " ") // 返回 []string
	for i, s := range ss {
		ss[i] = reverse(s)
	}
	return strings.Join(ss, " ") // 返回 string
}

func reverse(s string) string {
	bytes := []byte(s)
	i, j := 0, len(bytes) - 1
	for i < j {
		bytes[i], bytes[j] = bytes[j], bytes[i]
		i++
		j--
	}
	return string(bytes)
}

// 如何逐个读取单词?
// 调用标准库 "strings" 中的 Split 函数 把字符串按照" " 分开
// 调用标准库 "strings" 中的 Join 函数 把字符串按照" " 连接

/*反转字符串，要求按照空格隔开的小字符串为单位反转。
这是一道简单题。按照题意反转每个空格隔开的单词即可。
*/