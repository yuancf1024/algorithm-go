package leetcode

import "math"

/* 76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。


示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
*/

// 参考剑指offer 哈希表实现 改写的有问题
func minWindow(s string, t string) string {
	if len(s) < len(t) {
		return ""
	}
	charToCount := make(map[byte]int)
	for index, ch := range t {
		charToCount[byte(ch)] = index + 1
	}

	count := len(charToCount)
	start, end, minStart, minEnd := 0, 0, 0, 0
	minLength := math.MaxInt32
	for end < len(s) || (count == 0 && end == len(s)) {
		if count > 0 {
			endCh := s[end]
			if i, ok := charToCount[endCh]; ok {
				charToCount[endCh] = i - 1
				if charToCount[endCh] == 0 {
					count--
				}
			}
			end++
		} else {
			if end-start < minLength {
				minLength = end - start
				minStart = start
				minEnd = end
			}

			startCh := s[start]
			if i, ok := charToCount[startCh]; ok {
				charToCount[startCh] = i - 1
				if charToCount[startCh] == 0 {
					count++
				}
			}
			start++
		}
	}
	if minLength < math.MaxInt32 {
		return s[minStart:minEnd]
	} else {
		return ""
	}

}

/**************分割线****************/ 
/*
解题思路
这一题是滑动窗口的题目，在窗口滑动的过程中不断的包含字符串 T，
直到完全包含字符串 T 的字符以后，记下左右窗口的位置和窗口大小。
每次都不断更新这个符合条件的窗口和窗口大小的最小值。最后输出结果即可。
*/

// 参考 halfrost 滑动窗口
func minWindow_v1(s string, t string) string {
	// 考虑边界条件
	if s == "" || t == "" {
		return ""
	}

	var tFreq, sFreq [256]int
	res, left, right, finalLeft, finalRight, minW, count := "", 0, -1, -1, -1, len(s)+1, 0

	for i := 0; i < len(t); i++ { // 统计字符串t
		tFreq[t[i] - 'a']++
	}

	for left < len(s) {
		if right+1 < len(s) && count < len(t) { // right 没有超出s并且count计数没有超过字符串t的长度
			sFreq[s[right+1] - 'a']++
			if sFreq[s[right+1] - 'a'] <= tFreq[s[right+1] - 'a'] { // 窗口中的字符数量都小于字符串t里面的字符
				count++
			}
			right++ // 扩大右边界
		} else {
			if right-left+1 < minW && count == len(t) { // 当前窗口小于minW，窗口长度等于字符串t的长度
				minW = right-left+1 // 更新最小子串长度
				finalLeft = left
				finalRight = right
			}
			if sFreq[s[left] - 'a'] == tFreq[s[left] - 'a'] {
				count--
			}
			sFreq[s[left] - 'a']-- // 左边界右移
			left++
		}
	}
	if finalLeft != -1 {
		res = string(s[finalLeft : finalRight+1])
	}
	return res
}