package leetcode

import "sort"

/* 435. 无重叠区间
给定一个区间的集合 intervals ，
其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。

Input: [[1,2], [2,4], [1,3]]
Output: 1
*/

// 2022-05-02 bug：cannot convert intervals (variable of type [][]int) to Intervals

// 贪心 O(n) 这里用go语言实现就很麻烦
// 关键在于对二维切片内的区间进行排序，以每个区间最后一个元素为标准排序
func eraseOverlapIntervals(intervals [][]int) int {
	if len(intervals) == 0 {
		return 0
	}

	n := len(intervals)
	// 排序
	// sort.Sort(Intervals(intervals))
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][1] < intervals[j][1] })
	removed := 0
	prev := intervals[0][1]
	for i := 1; i < n; i++ {
		if intervals[i][0] < prev {
			removed++
		} else {
			prev = intervals[i][1]
		}
	}
	return removed
}

// // Intervals define
// type Intervals [][]Intervals

// func (a Intervals) Len() int {
// 	return len(a)
// }

// func (a Intervals) Swap(i, j int) {
// 	a[i], a[j] = a[j], a[i]
// }

// func (a Intervals) Less(i, j int) bool {
// 	for k := 0; k < len(a[i]); k++ {
// 		if a[i][k] < a[j][k] {
// 			return true
// 		} else if a[i][k] == a[j][k] {
// 			continue
// 		} else {
// 			return false
// 		}
// 	}
// 	return true
// }

/* 435. 无重叠区间
给定一个区间的集合 intervals ，
其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。

Input: [[1,2], [2,4], [1,3]]
Output: 1
*/

// Intervals define
// type Intervals [][]int

// 贪心 O(n)
// func eraseOverlapIntervals(intervals [][]int) int {
// 	if len(intervals) == 0 {
// 		return 0
// 	}
// 	sort.Sort(intervals)
// 	pre, res := 0, 1
	
// 	for i := 1; i < len(intervals); i++ {
// 		if intervals[i][0] >= intervals[pre][1] {
// 			res++
// 			pre = i
// 		} else if intervals[i][1] < intervals[pre][1] {
// 			pre = i
// 		}
// 	}
// 	return len(intervals) - res
// }

/* halfrost 题解
解题思路
给定一组区间，问最少删除多少个区间，可以让这些区间之间互相不重叠。
注意，给定区间的起始点永远小于终止点。[1,2] 和 [2,3] 不叫重叠。

这一题可以反过来考虑，给定一组区间，问最多保留多少区间，
可以让这些区间之间相互不重叠。先排序，判断区间是否重叠。

这一题一种做法是利用动态规划，模仿最长上升子序列的思想，来解题。

这道题另外一种做法是按照区间的结尾进行排序，每次选择结尾最早的，
且和前一个区间不重叠的区间。选取结尾最早的，就可以给后面留出更大的空间，
供后面的区间选择。这样可以保留更多的区间。这种做法是贪心算法的思想。
*/