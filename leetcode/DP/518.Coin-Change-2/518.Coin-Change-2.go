package leetcode

/* 518. 零钱兑换 II
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 
表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。 题目数据保证结果符合 32 位带符号整数。
*/

// DP 完全背包 二维DP数组
func change(amount int, coins []int) int {
    // 初始化DP数组
    n := len(coins)
    dp := make([][]int, n+1)
    for i := 0; i <= n; i++ {
        dp[i] = make([]int, amount+1)
    }
    // base case
    for i := 0; i <= n; i++ {
        dp[i][0] = 1
    }

    // 状态转移：i代表硬币数，j代表总金额
    for i := 1; i <= n; i++ {
        for j := 1; j <= amount; j++ {
            if j - coins[i-1] >= 0 { // 第i个物品放入背包
            dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
            } else { // 第i个物品不放入背包，那么使用前i-1个硬币凑成总金额
                dp[i][j] = dp[i-1][j]
            }
        }
    }
    return dp[n][amount]
}

// DP 完全背包 优化结果 1维DP数组
func change_v1(amount int, coins []int) int {
    // 初始化DP数组
    n := len(coins)
    dp := make([]int, amount+1)
    // base case
    dp[0] = 1

    // 状态转移：i代表硬币数，j代表总金额
    for i := 0; i < n; i++ {
        for j := 1; j <= amount; j++ {
            if j - coins[i] >= 0 {
            dp[j] = dp[j] + dp[j-coins[i]]
            }
        }
    }
    return dp[amount]
}

// 简洁版
func change_v2(amount int, coins []int) int {
	dp := make([]int, amount+1)
	dp[0] = 1
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
			dp[i] += dp[i-coin]
		}
	}
	return dp[amount]
}
/*
解题思路
此题虽然名字叫 Coin Change，但是不是经典的背包九讲问题。
题目中 coins 的每个元素可以选取多次，且不考虑选取元素的顺序，
因此这道题实际需要计算的是选取硬币的组合数。
定义 dp[i] 表示金额之和等于 i 的硬币组合数，目标求 dp[amount]。
初始边界条件为 dp[0] = 1，即不取任何硬币，就这一种取法，金额为 0 。
状态转移方程 dp[i] += dp[i-coin]，coin 为当前枚举的 coin。
可能有读者会有疑惑，上述做法会不会出现重复计算。答案是不会。
外层循环是遍历数组 coins 的值，内层循环是遍历不同的金额之和，
在计算 dp[i] 的值时，可以确保金额之和等于 i 的硬币面额的顺序，
由于顺序确定，因此不会重复计算不同的排列。
和此题完全一致的解题思路的题有，第 377 题和第 494 题。
*/