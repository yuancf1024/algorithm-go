package leetcode

/* 322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，
表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。
如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。

示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

示例 2：
输入：coins = [2], amount = 3
输出：-1

示例 3：
输入：coins = [1], amount = 0
输出：0

*/


// 参考算法模板 和其他 DP 不太一样，i 表示钱或者容量
func coinChange(coins []int, amount int) int {
	// 状态 dp[i] 表示金额为i时,组成的最小硬币个数
	// 推导 dp[i] = min(dp[i-1], dp[i-2], dp[i-5])+1, 前提i-coins[j] > 0
	// 初始化为最大值 dp[i]=amount+1
	// 返回值 dp[n] or dp[n] > amount => -1
	dp := make([]int, amount+1)
	for i := 0; i <= amount; i++ {
		dp[i] = amount+1
	}
	dp[0] = 0
	for i := 1; i <= amount; i++ {
		for j := 0; j < len(coins); j++ {
			if i - coins[j] >= 0 {
				dp[i] = min(dp[i], dp[i-coins[j]]+1)
			}
		}
	}
	if dp[amount] > amount {
		return -1
	}
	return dp[amount]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// 参考 halfrost
func coinChange_v1(coins []int, amount int) int {
	dp := make([]int, amount+1)
	dp[0] = 0 // base case
	for i := 1; i < len(dp); i++ { // 初始化dp数组为最大值 dp[i]=amount+1
		dp[i] = amount + 1
	}
	for i := 1; i <= amount; i++ { // 外层 for 循环在遍历所有状态的所有取值
		for j := 0; j < len(coins); j++ { // 内层for循环再求所有选择的最小值
			if coins[j] <= i { // 前提i-coins[j] > 0, 不满足的情况直接跳过
				dp[i] = min(dp[i], dp[i-coins[j]]+1) // 状态方程 选择最优子结构
			}
		}
	}
	if dp[amount] > amount { // 没有任何一种硬币组合能组成总金额
		return -1
	}
	return dp[amount] 
}

/* 
解题思路
给出一些硬币和一个总数，问组成这个总数的硬币数最少是多少个？
这一题是经典的硬币问题，利用 DP 求解。不过这一题的测试用例有一个很大的值，
这样开 DP 数组会比较浪费空间。例如 [1,1000000000,500000] 有这样的硬币种类，
要求组成 2389412493027523 这样的总数。
那么按照下面的解题方法，数组会开的很大，
非常浪费空间。这个时候用 DFS 解题会节约一点空间。
*/