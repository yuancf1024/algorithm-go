package leetcode

/* 844. 比较含退格的字符串
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，
如果两者相等，返回 true 。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。
*/

// 参考halfrost 
func backspaceCompare(s string, t string) bool {
	if len(s) == 0 && len(t) == 0 {
		return true
	}

	str := make([]rune, 0)
	for _, c := range s {
		if c == '#' {
			if len(str) > 0 {
				str = str[:len(str)-1]
			}
		} else {
			str = append(str, c)
		}
	}
	str2 := make([]rune, 0)
	for _, c := range t {
		if c == '#' {
			if len(str2) > 0 {
				str2 = str2[:len(str2)-1]
			}
		} else {
			str2 = append(str2, c)
		}
	}
	return string(str) == string(str2)
}

/*
题目大意
给 2 个字符串，如果遇到 # 号字符，
就回退一个字符。问最终的 2 个字符串是否完全一致。

解题思路
这一题可以用栈的思想来模拟，遇到 # 字符就回退一个字符。
不是 # 号就入栈一个字符。比较最终 2 个字符串即可。
*/