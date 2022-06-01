package leetcode

/* 84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

// 参考halfrost 
func largestRectangleArea(heights []int) int {
	maxArea := 0
	n := len(heights) + 2
	// Add a sentry at the beginning and the end 增加2个哨兵，更容易处理边界条件
	getHeight := func(i int) int {
		if i == 0 || n-1 == i {
			return 0
		}
		return heights[i-1]
	}
	st := make([]int, 0, n/2)
	for i := 0; i < n; i++ {
		for len(st) > 0 && getHeight(st[len(st)-1]) > getHeight(i) { // 一旦出现高度比栈顶元素小的情况就取出栈顶元素
			// pop stack
			idx := st[len(st)-1]
			st = st[:len(st)-1]
			maxArea = max(maxArea, getHeight(idx)*(i-st[len(st)-1]-1))
		}
		// push stack
		st = append(st, i) // 用单调栈依次保存直方图的高度下标
	}
	return maxArea
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/*

leetcode 题解讲得有点复杂，不利于理解。。。说白了，这题考的基础模型其实就是：
在一维数组中对每一个数找到第一个比自己小的元素。
这类“在一维数组中找第一个满足某种条件的数”的场景就是典型的单调栈应用场景。

用单调栈依次保存直方图的高度下标，
一旦出现高度比栈顶元素小的情况就取出栈顶元素，
单独计算一下这个栈顶元素的矩形的高度。
然后停在这里(外层循环中的 i--，再 ++，就相当于停在这里了)，
继续取出当前最大栈顶的前一个元素，即连续弹出 2 个最大的，
以稍小的一个作为矩形的边，宽就是 2 计算面积…………
如果停在这里的下标代表的高度一直比栈里面的元素小，
就一直弹出，取出最后一个比当前下标大的高度作为矩形的边。
宽就是最后一个比当前下标大的高度和当前下标 i 的差值。
计算出面积以后不断的更新 maxArea 即可。

比较容易理解的一种方法：

	其实不需要那两个数组，只需要一个单调递增栈就行了。
	用i遍历一遍数组，在遍历过程中如果需要弹栈，就可以以被弹出来的那个位置cur高度作为高，

	以i作为右边界，因为i是cur右边第一个比它低的。

   同时，弹完栈后的栈顶pre（如果弹完栈后，栈为空，则pre设为哨兵-1）作为它的左边界，
因为pre是cur左边第一个比它低的，然后就可以计算面积了。

   然后在遍历完之后，因为栈中可能还存在元素，所以我们需要把栈中的元素都弹完，
这时因为栈中的元素的右边都不存在比它低的位置，所以右边界全部设为哨兵n。
*/