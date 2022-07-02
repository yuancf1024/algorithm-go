package leetcode

/* 56. 合并区间
以数组 intervals 表示若干个区间的集合，
其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，
该数组需恰好覆盖输入中的所有区间 。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 
提示：

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
*/

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// Interval define
type Interval = structures.Interval

/**
 * Definition for an interval.
 * type Interval struct {
 *	   Start int
 *	   End   int
 * }
 */

// 参考halfrost 采用快速排序
func merge56(intervals []Interval) []Interval {
	if len(intervals) == 0 {
		return intervals
	}
	quickSort(intervals, 0, len(intervals)-1) // 按照区间起点进行排序。
	res := make([]Interval, 0)
	res = append(res, intervals[0])
	curIndex := 0
	for i := 1; i < len(intervals); i++ { // 从第二个区间开始遍历
		if intervals[i].Start > res[curIndex].End { // 没有重叠部分
			curIndex++
			res = append(res, intervals[i])
		} else { // 存在重叠部分
			res[curIndex].End = max(intervals[i].End, res[curIndex].End) // 合并重叠的区间
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// 快速排序
func quickSort(a []Interval, lo, hi int) {
	if lo >= hi {
		return
	}
	p := partitionSort(a, lo, hi)
	quickSort(a, lo, p-1)
	quickSort(a, p+1, hi)
}

func partitionSort(a []Interval, lo, hi int) int {
	pivot := a[hi]
	i := lo - 1
	for j := lo; j < hi; j++ {
		if (a[j].Start < pivot.Start) || (a[j].Start == pivot.Start && a[j].End < pivot.End) {
			i++
			a[j], a[i] = a[i], a[j]
		}
	}
	a[i+1], a[hi] = a[hi], a[i+1]
	return i + 1
}



/*
解题思路
先按照区间起点进行排序。
然后从区间起点小的开始扫描，依次合并每个有重叠的区间。
*/