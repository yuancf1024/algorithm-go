package leetcode

/* 875. 爱吃香蕉的珂珂
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。
警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。
每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，
她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。


示例 1：

输入：piles = [3,6,7,11], h = 8
输出：4

示例 2：
输入：piles = [30,11,23,4,20], h = 5
输出：30

示例 3：
输入：piles = [30,11,23,4,20], h = 6
输出：23
 

提示：
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9
*/

import (
	"math"
)

func minEatingSpeed(piles []int, h int) int {
	low, high := 1, maxInArr(piles)
	for low < high {
		mid := low + ((high - low) >> 1)
		if !isPossible(piles, mid, h) { // 在h小时内，以速度mid不能吃完全部香蕉
			low = mid + 1 // 因此需要加速
		} else {
			high = mid
		}
	}
	return low
}

// 在H小时内，以速度h，能否吃完全部香蕉
func isPossible(piles []int, h, H int) bool {
	res := 0
	for _, p := range piles { // 遍历每堆香蕉，累加吃香蕉的时间
		res += int(math.Ceil(float64(p) / float64(h))) 
		/*
		如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
		考虑上述条件，因此对吃香蕉的速度向上取整
		*/
	}
	return res <= H
}

// 求数组中的最大数字
func maxInArr(xs []int) int {
	res := 0
	for _, x := range xs {
		if res < x {
			res = x
		}
	}
	return res
}

/*
解题思路
- 给出一个数组，数组里面每个元素代表的是每个香蕉🍌串上香蕉的个数。
koko 以 k 个香蕉/小时的速度吃这些香蕉。守卫会在 H 小时以后回来。
问 k 至少为多少，能在守卫回来之前吃完所有的香蕉。
当香蕉的个数小于 k 的时候，这个小时只能吃完这些香蕉，
不能再吃其他串上的香蕉了。
- 这一题可以用二分搜索来解答。在 [0 , max(piles)] 的范围内搜索，
二分的过程都是常规思路。判断是否左右边界
如果划分的时候需要注意题目中给的限定条件。
当香蕉个数小于 k 的时候，那个小时不能再吃其他香蕉了。
*/

