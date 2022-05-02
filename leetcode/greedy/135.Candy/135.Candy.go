package leetcode

/* 135. 分发糖果
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

- 每个孩子至少分配到 1 个糖果。
- 相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/

// 参考leetcode101
func candy(ratings []int) int {
	size := len(ratings)
	if size < 2 {
		return size
	}
	nums := make([]int, size)
	// 数组初始化全部置为1
    for i := 0; i < size; i++ {
        nums[i] = 1
    }
	for i := 1; i < size; i++ {
		if ratings[i] > ratings[i-1] {
			nums[i] = nums[i-1] + 1
		}
	}
	for i := size-1; i > 0; i-- {
		if ratings[i] < ratings[i-1] {
			nums[i-1] = max(nums[i-1], nums[i] + 1)
		}
	}
	// 计算 nums里面最少糖果数量
	sum := 0
	for i := 0; i < size; i++ {
		sum += nums[i]
	}
	return sum
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/* 解题思路：
做完了题目455，你会不会认为存在比较关系的贪心策略一定需要排序或是选择？虽然这一
道题也是运用贪心策略，但我们只需要简单的两次遍历即可：把所有孩子的糖果数初始化为1；
先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的
糖果数加1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，**且左边孩子当前的糖果数
不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加1**。通过这两次遍历，
分配的糖果就可以满足题目要求了。这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一
侧的大小关系
*/