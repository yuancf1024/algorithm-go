package leetcode

/* 746. 使用最小花费爬楼梯
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬
需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。

示例 1：

输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。

示例 2：

输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
*/

// 参考halfrost
// 解法1 DP
func minCostClimbingStairs(cost []int) int {
	dp := make([]int, len(cost))
	dp[0], dp[1] = cost[0], cost[1]

	for i := 2; i < len(cost); i++ {
		dp[i] = cost[i] + min(dp[i-2], dp[i-1])
	}
	return min(dp[len(cost)-2], dp[len(cost)-1])
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// 解法二 DP 优化辅助空间
func minCostClimbingStairs1(cost []int) int {
	var cur, last int
	for i := 2; i < len(cost)+1; i++ {
		if last+cost[i-1] > cur+cost[i-2] {
			cur, last = last, cur+cost[i-2]
		} else {
			cur, last = last, last+cost[i-1]
		}
	}
	return last
}

/*
解题思路
这一题算是第 70 题的加强版。依旧是爬楼梯的问题，解题思路也是 DP。
在爬楼梯的基础上增加了一个新的条件，每层楼梯都有一个 cost 花费，
问上到最终楼层，花费最小值是多少。
dp[i] 代表上到第 n 层的最小花费，
状态转移方程是 dp[i] = cost[i] + min(dp[i-2], dp[i-1])，
最终第 n 层的最小花费是 min(dp[n-2], dp[n-1]) 。
由于每层的花费只和前两层有关系，所以每次 DP 迭代的时候
只需要 2 个临时变量即可。可以用这种方式来优化辅助空间。
*/