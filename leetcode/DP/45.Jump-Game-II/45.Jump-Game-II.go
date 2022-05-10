package leetcode

/* 45. 跳跃游戏 II
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。

示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

示例 2:
输入: nums = [2,3,0,1,4]
输出: 2
*/

// 参考算法模板 v1动态规划（其他语言超时参考v2）
func jump(nums []int) int {
	// 状态：f[i] 表示从起点到当前位置最小次数
	// 推导：f[i] = f[j],a[j]+j >= i,min(f[j]+1)
	// 初始化：f[0] = 0
	// 结果：f[n-1]
	f := make([]int, len(nums))
	f[0] = 0
	for i := 1; i < len(nums); i++ {
		// f[i]最大值为i
		f[i] = i
		// 遍历之前结果取一个最小值+1
		for j := 0; j < i; j++ {
			if nums[j]+j >= i {
				f[i] = min(f[j]+1, f[i])
			}
		}
	}
	return f[len(nums)-1]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// v2 动态规划+贪心优化
func jump_v1(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	f[0] = 0
	for i := 1; i < n; i++ {
		// 取第一个能跳到当前位置的点即可
		// 因为跳跃次数的结果集是单调递增的，所以贪心思路是正确的
		idx := 0
		for idx < n && idx+nums[idx] < i {
			idx++
		}
		f[i]=f[idx]+1
	}
	return f[n-1]
}

// 参考halfrost 贪心
func jump_v2(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	needChoose, canReach, step := 0, 0, 0
	for i, x := range nums {
		if i+x > canReach { // 扫描步数数组
			canReach = i + x // 维护当前能够到达最大下标的位置，记为能到达的最远边界
			if canReach >= len(nums)-1 { // 遍历到最后一个元素，说明边界正好为最后一个位置，最终跳跃次数直接 + 1
				return step+1
			}
		}
		if i == needChoose { // 如果扫描过程中到达了最远边界，更新边界并将跳跃次数 + 1。
			needChoose = canReach
			step++
		}
	}
	return step
}

/*
解题思路

要求找到最少跳跃次数，顺理成章的会想到用*贪心算法*解题。
扫描步数数组，维护当前能够到达最大下标的位置，记为能到达的最远边界，
如果扫描过程中到达了最远边界，更新边界并将跳跃次数 + 1。

扫描数组的时候，其实不需要扫描最后一个元素，因为在跳到最后一个元素之前，
能到达的最远边界一定大于等于最后一个元素的位置，
不然就跳不到最后一个元素，到达不了终点了；
如果遍历到最后一个元素，说明边界正好为最后一个位置，最终跳跃次数直接 + 1 
即可，也不需要访问最后一个元素。
*/