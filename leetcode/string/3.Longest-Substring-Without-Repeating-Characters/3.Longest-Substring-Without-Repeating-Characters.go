package leetcode

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

// 解法1：滑动窗口
func lengthOfLongestSubstring(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	var freq [127]int // s 由英文字母、数字、符号和空格组成
	result, left, right := 0, 0, -1

	for left < n {
		if right + 1 < n && freq[s[right + 1]] == 0 { // 判断是否出现重复字符，同时确保 指针right+1 在字符s范围内
			// right最多指向倒数第2个字符，但是right+1可以指向最后一个字符
			freq[s[right + 1]]++ // 滑动窗口的右边界不断的右移
			right++
		} else { // 一旦出现了重复字符，就需要缩小左边界，
			freq[s[left]]--
			left++
		}
		result = max(result, right - left + 1) // 更新当前窗口长度，right指向的字符串数组的下标，对应到元素数量，需要+1
	}
	return result
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
/* 建议采用解法1 滑动窗口
这一题和第 438 题，第 3 题，第 76 题，第 567 题类似，
用的思想都是"滑动窗口"。

滑动窗口的右边界不断的右移，只要没有重复的字符，
就持续向右扩大窗口边界。一旦出现了重复字符，就需要缩小左边界，
直到重复的字符移出了左边界，然后继续移动滑动窗口的右边界。
以此类推，每次移动需要计算当前长度，并判断是否需要更新最大长度，
最终最大的值就是题目中的所求。
*/


// 解法2：滑动窗口-哈希桶
// 没有解法1 好理解
func lengthOfLongestSubstring_v2(s string) int {
	n := len(s)
	right, left, res := 0, 0, 0
	indexes := make(map[byte]int, len(s))
	for left < n {
		if idx, ok := indexes[s[left]]; ok && idx >= right {
			right = idx + 1
		}
		indexes[s[left]] = left
		left++
		res = max(res, left - right)
	}
	return res
}

// 解法3：位图
func lengthOfLongestSubstring_v3(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	var bitSet [256]bool // 初始化默认为 false
	result, left, right := 0, 0, 0
	for left < n {
		// 右侧字符对应的 bitSet 被标记为 true
		// 说明此字符在 X 位置重复，需要左侧向前移动，直到将 X 标记为 false
		if  bitSet[s[right]] {
			bitSet[s[left]] = false
			left++
		} else {
			bitSet[s[right]] = true
			right++
		}
		if result < right - left {
			result = right - left
		}
		if left + result >= n || right >= n {
			break
		}
	}
	return result
}