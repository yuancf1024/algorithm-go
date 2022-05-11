package leetcode

/* 1143. 最长公共子序列
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。
如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：
它是由原字符串在不改变字符的相对顺序的情况下删除某些字符
（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

示例 1：
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。

示例 2：
输入：text1 = "abc", text2 = "abc"

输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。

示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
*/

// 参考算法模板
func longestCommonSubsequence(text1 string, text2 string) int {
	// dp[i][j] a前i个和b前j个字符最长公共子序列
	// dp[m+1][n+1]
	//   ' a d c e
	// ' 0 0 0 0 0
	// a 0 1 1 1 1
	// c 0 1 1 2 1
	a, b := text1, text2
	dp := make([][]int, len(a)+1) // 构建二维数组
	for i := 0; i <= len(a); i++ {
		dp[i] = make([]int, len(b)+1)
	}
	for i := 1; i <= len(a); i++ {
		for j := 1; j <= len(b); j++ {
			// 相等取左上元素+1，否则取左或上的较大值
			if a[i-1] == b[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return dp[len(a)][len(b)]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 参考halfrost
func longestCommonSubsequence_v1(text1 string, text2 string) int {
	if len(text1) == 0 || len(text2) == 0 {
		return 0
	}
	dp := make([][]int, len(text1)+1)
	for i := range dp {
		dp[i] = make([]int, len(text2)+1)
	}
	for i := 1; i < len(text1)+1; i++ {
		for j := 1; j < len(text2)+1; j++ {
			if text1[i-1] == text2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
			}
		}
	}
	return dp[len(text1)][len(text2)]
}

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }
/*
解题思路

这一题是经典的最长公共子序列的问题。解题思路是二维动态规划。
假设字符串 text1 和 text2 的长度分别为 m 和 n，创建 m+1 行 n+1 列的
二维数组 dp，定义 dp[i][j] 表示长度为 i 的 text1[0:i-1] 和长度为 j 的
text2[0:j-1] 的最长公共子序列的长度。
先考虑边界条件。当 i = 0 时，text1[] 为空字符串，它与任何字符串的最长公共子序列
的长度都是 0，所以 dp[0][j] = 0。
同理当 j = 0 时，text2[] 为空字符串，它与任何字符串的最长公共子序列的长度都是 0，
所以 dp[i][0] = 0。由于二维数组的大小特意增加了 1，即 m+1 和 n+1，
并且默认值是 0，所以不需要再初始化赋值了。

当 text1[i−1] = text2[j−1] 时，将这两个相同的字符称为公共字符，
考虑 text1[0:i−1] 和 text2[0:j−1] 的最长公共子序列，再增加一个字符
（即公共字符）即可得到 text1[0:i] 和 text2[0:j] 的最长公共子序列，
所以 dp[i][j]=dp[i−1][j−1]+1。当 text1[i−1] != text2[j−1] 时，
最长公共子序列一定在 text[0:i-1], text2[0:j] 和 text[0:i], text2[0:j-1] 中取得。
即 dp[i][j] = max(dp[i-1][j], dp[i][j-1])。所以状态转移方程如下：

dp[i][j]=
dp[i−1][j−1]+1, text1[i−1] == text2[j−1]
max(dp[i−1][j],dp[i][j−1]), text1[i−1] != text2[j−1]
​
最终结果存储在 dp[len(text1)][len(text2)] 中。
时间复杂度 O(mn)，空间复杂度 O(mn)，
其中 m 和 n 分别是 text1 和 text2 的长度。
*/