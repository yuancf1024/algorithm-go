package leetcode

import "sort"

/* 452. 用最少数量的箭引爆气球
有一些球形气球贴在一堵用 XY 平面表示的墙面上。
墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend]
表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。
在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。
可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
*/

// 参考lauladong
func findMinArrowShots(points [][]int) int {
	if len(points) == 0 {
		return 0
	}
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1]})
	maxRight := points[0][1] // // 排序后，第一个区间就是 x
	ans := 1 // 至少有一个区间不相交
	for _, p := range points {
		if p[0] > maxRight { // 不重叠，找到下一个选择的区间了
			maxRight = p[1]
			ans++
		}
	}
	return ans
}

/* 解题思路：
考虑任意一种最优的方法，对于其中的任意一支箭，我们都通过上面描述的方法，
将这支箭的位置移动到它对应的「原本引爆的气球中最靠左的右边界位置」，
那么这些原本引爆的气球仍然被引爆。这样一来，所有的气球仍然都会被引爆，
并且每一支箭的射出位置都恰好位于某一个气球的右边界了。

有了这样一个有用的断定，我们就可以快速得到一种最优的方法了。
考虑所有气球中右边界位置最靠左的那一个，
那么一定有一支箭的射出位置就是它的右边界（否则就没有箭可以将其引爆了）。
当我们确定了一支箭之后，我们就可以将这支箭引爆的所有气球移除，
并从剩下未被引爆的气球中，再选择右边界位置最靠左的那一个，
确定下一支箭，直到所有的气球都被引爆。

伪代码
```
let points := [[x(0), y(0)], [x(1), y(1)], ... [x(n-1), y(n-1)]]，表示 n 个气球
let pos := y(0)，表示当前箭的射出位置
let ans := 0，表示射出的箭数

将 points 按照 y 值（右边界）进行升序排序

for i := 1 to n-1 do
    if x(i) > pos then
        ans := ans + 1
        pos := y(i)
    end if
end for

return ans
```
*/

// 参考区间调度的实现1
// 如果最多有 n 个不重叠的区间，那么就至少需要 n 个箭头穿透所有区间：
func findMinArrowShots1(points [][]int) int {
	if len(points) == 0 {
		return 0
	}

	n := len(points)
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1]})
	ans := 0
	prev := points[0][1]
	for i := 1; i < n ; i++ {
		if points[i][0] <= prev { // 有重叠，相等也算重叠
			ans++
		} else { // 不重叠，更新prev，继续比较
			prev = points[i][1]
		}
	}
	return n - ans
}

/*
要求最少引爆气球的箭，实际上就是求最多不重叠子区间。因为重叠，就可以一次性引爆，
如果不重叠，就需要分开引爆。
*/