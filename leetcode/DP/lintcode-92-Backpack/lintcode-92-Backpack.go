package leetcode

/* 92 · 背包问题
描述
在 n 个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，
每个物品的大小为A_i（每个物品只能选择一次且物品大小均为正整数）

你不可以将物品进行切割
n<1000
m<1e9

样例 1：

输入：
数组 = [3,4,8,5]
backpack size = 10
输出：
9

解释：
装4和5.

样例 2：

输入：
数组 = [2,3,5,7]
backpack size = 12
输出：
12

解释：
装5和7.
*/

/**
 * @param m: An integer m denotes the size of a backpack
 * @param a: Given n items with size A[i]
 * @return: The maximum size
 */

// 算法模板，非常经典的0-1背包问题
 func BackPack(m int, a []int) int {
    // write your code here
	// f[i][j] 前i个物品，是否能装j
	// f[i][j] = f[i-1][j] f[i-1][j-a[i]] j > a[i]
	// f[0][0] = true f[...][0]=true
	// f[n][x]
	f := make([][]bool, len(a)+1)
	for i := 0; i <= len(a); i++ {
		f[i] = make([]bool, m+1)
	}
	f[0][0] = true
	for i := 1; i <= len(a); i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = f[i-1][j] // 和i-1个物品装j的状态一致
			if j - a[i-1] >= 0 && f[i-1][j-a[i-1]] { // 第i个物品装进来后，考虑剩下的容量能否装前i-1个物品
				f[i][j] = true
			}
		}
	}
	for i := m; i >= 0; i-- {
		if f[len(a)][i] {
			return i
		}
	}
	return 0
}