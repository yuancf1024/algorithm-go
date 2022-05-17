package leetcode

import (
	"math"
	"sort"
)

/* 539. 最小时间差
给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，
找出列表中任意两个时间的最小时间差并以分钟数表示。
示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0
*/

// 方法1：排序
func findMinDifference(timePoints []string) int {
	sort.Strings(timePoints)
	ans := math.MaxInt32
	t0Minutes := getMinutes(timePoints[0])
	preMinutes := t0Minutes
	for _, t := range timePoints[1:] {
		minutes := getMinutes(t)
		ans = min(ans, minutes - preMinutes) // 相邻时间的时间差
		preMinutes = minutes
	}
	ans = min(ans, t0Minutes+24*60-preMinutes) // 首尾时间的时间差
	return ans
}

func getMinutes(t string) int {
	return (int(t[0]-'0')*10 + int(t[1]-'0'))*60 + int(t[3]-'0')*10 + int(t[4]-'0')
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

/*
将 timePoints 排序后，最小时间差必然出现在 timePoints 的两个相邻时间，
或者 timePoints 的两个首尾时间中。
因此排序后遍历一遍 timePoints 即可得到最小时间差。

复杂度分析

时间复杂度：O(nlogn)，其中 n 是数组 timePoints 的长度。排序需要 O(nlogn) 的时间。

空间复杂度：O(n) 或 O(logn)。为排序需要的空间，取决于具体语言的实现。
*/

// 方法二：鸽巢原理 适当的优化
func findMinDifference1(timePoints []string) int {
	if len(timePoints) > 1440 {
		return 0
	}

	sort.Strings(timePoints)
	ans := math.MaxInt32
	t0Minutes := getMinutes(timePoints[0])
	preMinutes := t0Minutes
	for _, t := range timePoints[1:] {
		minutes := getMinutes(t)
		ans = min(ans, minutes - preMinutes) // 相邻时间的时间差
		preMinutes = minutes
	}
	ans = min(ans, t0Minutes+24*60-preMinutes) // 首尾时间的时间差
	return ans
}

/*
根据题意，一共有 24×60=1440 种不同的时间。由鸽巢原理可知，
如果 timePoints 的长度超过 1440，那么必然会有两个相同的时间，
此时可以直接返回 00。

复杂度分析
时间复杂度：O(min(n,C)log min(n,C))，其中 n 是数组 timePoints 的长度，
C=24×60=1440。由于当 n>C 时直接返回 0，排序时的 n 不会超过 C，
因此排序需要 O(min(n,C)log min(n,C)) 的时间。

空间复杂度：O(min(n,C)) 或 O(logmin(n,C))。为排序需要的空间，
取决于具体语言的实现。
*/