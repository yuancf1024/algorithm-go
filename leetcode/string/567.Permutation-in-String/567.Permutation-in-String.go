package leetcode

/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。
*/

// 不太好理解的滑动窗口
func checkInclusion(s1 string, s2 string) bool {
	var freq [256]int
	s1Len, s2Len := len(s1), len(s2)
	if s2Len == 0 || s2Len < s1Len {
		return false
	}

	for i := 0; i < s1Len; i++ {
		freq[s1[i] - 'a']++
	}

	left, right, count := 0, 0, len(s1)

	for right < s2Len {
		if freq[s2[right] - 'a'] >= 1 {
			count--
		}
		freq[s2[right] - 'a']--
		right++
		if count == 0 {
			return true
		}
		if right - left == s1Len {
			if freq[s2[left] - 'a'] >= 0 {
				count++
			}
			freq[s2[left] - 'a']++
			left++
		}
	}
	return false
}

// 字符串s1的排列，需要for遍历
// 需要一个滑动窗口在s2中，然后逐一比对s1的排列

/* 解题思路
这一题和第 438 题，第 3 题，第 76 题，第 567 题类似，
用的思想都是"滑动窗口"。

这道题只需要判断是否存在，而不需要输出子串所在的下标起始位置。
所以这道题是第 438 题的缩水版。具体解题思路见第 438 题。
*/

// leetcode解法1：滑动窗口
func checkInclusion_v1(s1 string, s2 string) bool {
	n, m := len(s1), len(s2)
	if n > m {
		return false
	}

	var cnt1, cnt2 [26]int
	for i, ch := range s1 {
		cnt1[ch - 'a']++
		cnt2[s2[i] - 'a']++
	}

	if cnt1 == cnt2 {
		return true
	}

	for i := n; i < m; i++ {
		cnt2[s2[i] - 'a']++
		cnt2[s2[i-n] - 'a']--
		if cnt1 == cnt2 {
			return true
		}
	}
	return false
}

/*
由于排列不会改变字符串中每个字符的个数，所以只有当两个字符串每个字符的个数均相等时，
一个字符串才是另一个字符串的排列。根据这一性质，记 s1的长度为 n，
我们可以遍历 s2中的每个长度为 n 的子串，判断子串和 s1中每个字符的个数
是否相等，若相等则说明该子串是 s1的一个排列。
使用两个数组 cnt1和cnt2，cnt1统计 s1中各个字符的个数，cnt2统计当前遍历的子串中各个字符的个数。
由于需要遍历的子串长度均为 n，我们可以使用一个固定长度为 n 的滑动窗口来维护
cnt2：滑动窗口每向右滑动一次，就多统计一次进入窗口的字符，
少统计一次离开窗口的字符。然后，判断 cnt1是否与 cnt2相等，
若相等则意味着 s1的排列之一是 s2的子串。
*/

// leetcode解法1：滑动窗口
func checkInclusion_v2(s1, s2 string) bool {
    n, m := len(s1), len(s2)
    if n > m {
        return false
    }
    cnt := [26]int{}
    for _, ch := range s1 {
        cnt[ch-'a']--
    }
    left := 0
    for right, ch := range s2 {
        x := ch - 'a'
        cnt[x]++
        for cnt[x] > 0 {
            cnt[s2[left]-'a']--
            left++
        }
        if right-left+1 == n {
            return true
        }
    }
    return false
}