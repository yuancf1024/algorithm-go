package leetcode

/* 528. 按权重随机选择
给你一个 下标从 0 开始 的正整数数组 w ，
其中 w[i] 代表第 i 个下标的权重。

请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 
内（含 0 和 w.length - 1）选出并返回一个下标。
选取下标 i 的 概率 为 w[i] / sum(w) 。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 
（即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

示例 1：
输入：
["Solution","pickIndex"]
[[[1]],[]]

输出：
[null,0]

解释：
Solution solution = new Solution([1]);
solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。

示例 2：
输入：
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]

输出：
[null,1,1,1,1,0]

解释：
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。

由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
诸若此类。
 
提示：

1 <= w.length <= 10^4
1 <= w[i] <= 10^5
pickIndex 将被调用不超过 10^4 次
*/

import (
	"math/rand"
)

// Solution528 define
type Solution528 struct {
	prefixSum []int
}

// Constructor528 define
func Constructor528(w []int) Solution528 {
	prefixSum := make([]int, len(w))
	for i, e := range w {
		if i == 0 { // 先处理前缀和的第一个元素
			prefixSum[i] = e
			continue
		}
		prefixSum[i] = prefixSum[i-1] + e // 用前缀和处理权重
	}
	return Solution528{prefixSum: prefixSum}
}

// PickIndex define
func (this *Solution528) PickIndex() int {
	n := rand.Intn(this.prefixSum[len(this.prefixSum)-1]) + 1 // 在 [0,prefixSum) 区间内随机选一个整数 x
	low, high := 0, len(this.prefixSum)-1
	for low < high {
		mid := low + ((high - low) >> 1)
		if this.prefixSum[mid] == n {
			return mid
		} else if this.prefixSum[mid] < n {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */

/*
解题思路
- 给出一个数组，每个元素值代表该下标的权重值，pickIndex() 随机取一个位置 i，
这个位置出现的概率和该元素值成正比。
- 由于涉及到了权重的问题，这一题可以先考虑用前缀和处理权重。
在 [0,prefixSum) 区间内随机选一个整数 x，
下标 i 是满足 x< prefixSum[i] 条件的最小下标，求这个下标 i 即是最终解。
二分搜索查找下标 i 。对于某些下标 i，所有满足 
prefixSum[i] - w[i] ≤ v < prefixSum[i] 的整数 v 都映射到这个下标。
因此，所有的下标都与下标权重成比例。
时间复杂度：预处理的时间复杂度是 O(n)，pickIndex() 的时间复杂度是 
O(log n)。空间复杂度 O(n)。
*/