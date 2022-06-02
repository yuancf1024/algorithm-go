package leetcode

/* 346 剑指 Offer II 041. 滑动窗口的平均值
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，
计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口
增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，
即滑动窗口里所有数字的平均值。

示例：

输入：
inputs = ["MovingAverage", "next", "next", "next", "next"]
inputs = [[3], [1], [10], [3], [5]]
输出：
[null, 1.0, 5.5, 4.66667, 6.0]

解释：
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
 
提示：
1 <= size <= 1000
-105 <= val <= 105
最多调用 next 方法 104 次


*/

type MovingAverage struct {
	index int // 维护当前环形数组的位置，实现数组的复用
	count int
	sum int
	cache []int // 缓存最近的size个数
}


/** Initialize your data structure here. */
func Constructor(size int) MovingAverage {
	return MovingAverage{index: size-1, cache: make([]int, size)}
}

func (this *MovingAverage) Next(val int) float64 {
	this.sum += val
	this.index = (this.index+1) % len(this.cache)
	if this.count < len(this.cache) { // 如果数量未达到size
		this.count++ 
		this.cache[this.index] = val // 直接添加进数组，并且count++， sum+=val
	} else { // 如果数量已达到size
		this.sum -= this.cache[this.index] // 添加到尾部的时候（覆盖掉头部的值），sum-=头部，count不变
		this.cache[this.index] = val
	}
	return float64(this.sum) / float64(this.count)
}


/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */

/*
解题思路
由于需要统计最近size个值的平均值，所以需要使用一个数组来缓存最近的size个数。
由于我们只关心最近的size个，所以可以使用一个index来维护当前环形数组的位置，实现数组的复用。

当添加元素的时候：
如果数量未达到size，那么直接添加进数组，并且count++， sum+=val
如果数量已达到size，那么添加到尾部的时候（覆盖掉头部的值），sum-=头部，count不变
最后返回sum/count。

时间复杂度：O(1)
空间复杂度：O(n)
*/