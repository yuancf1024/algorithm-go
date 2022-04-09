package leetcode

/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票
第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子
卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

Example1:
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，
在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；
	 同时，你不能在买入前卖出股票。

Example2:
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

// 解法1：模拟 DP
func maxProfit(prices []int) int {
	if len(prices) < 1 {
		return 0
	}

	n := len(prices)
	min, maxProfit := prices[0], 0
	for i := 1; i < n; i++ {
		if prices[i]-min > maxProfit {
			maxProfit = prices[i] - min
		}

		if prices[i] < min {
			min = prices[i]
		}
	}
	return maxProfit
}

/* Solution:
- 题目要求找出股票中能赚的钱最多的差价
- 这一题也有多个解法，可以用 DP，也可以用单调栈
*/

// 解法2：单调栈
