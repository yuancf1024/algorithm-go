package leetcode

/* 125 · 背包问题（二）
描述
有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和
数组 V 表示每个物品的价值.
问最多能装入背包的总价值是多大?

1. A[i], V[i], n, m 均为整数
2. 你不能将物品进行切分
3. 你所挑选的要装入背包的物品的总大小不能超过 m
4. 每个物品只能取一次
5. m<=1000 len(A),len(V)<=100

样例 1：
输入：
m = 10
A = [2, 3, 5, 7]
V = [1, 5, 2, 4]

输出：
9

解释：
装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9

样例 2：
输入：
m = 10
A = [2, 3, 8]
V = [2, 5, 8]

输出：
10

解释：
装入 A[0] 和 A[2] 可以得到最大价值, V[0] + V[2] = 10
*/

// 参考算法模板 
func BackPackII(m int, a []int, v []int) int {
    // write your code here
	// f[i][j] 前i个物品，装入j背包 最大价值
	// f[i][j] = max(f[i-1][j], f[i-1][j-A[i]] + V[i]) 是否加入A[i]物品
	// f[0][0] = 0 f[0][...] = 0 f[...][0] = 0
	f := make([][]int, len(a)+1)
	for i := 0; i < len(a)+1; i++ {
		f[i] = make([]int, m+1)
	}

	for i := 1; i <= len(a); i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = f[i-1][j]
			if j - a[i-1] >= 0 {
				f[i][j] = max(f[i-1][j], f[i-1][j - a[i-1]] + v[i-1])
			}
		}
	}
	return f[len(a)][m]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
