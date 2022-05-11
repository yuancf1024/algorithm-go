package leetcode

/* 72. 编辑距离
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 
所使用的最少操作数  。
你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 
示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 
提示：
0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
*/

// 参考算法模板
func minDistance(word1 string, word2 string) int {
	// dp[i][j] 表示a字符串的前i个字符编辑为b字符串的前j个字符最少需要多少次操作
	// dp[i][j] = OR(dp[i-1][j-1], a[i]==b[j], min(dp[i-1][j], dp[i-1][j-1])+1)
	dp := make([][]int, len(word1)+1) // 新建二维数组，维度分别为两个字符串长度+1
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, len(word2)+1)
	}
	for i := 0; i < len(dp); i++ { // 初始化第一列 值为行索引
		dp[i][0] = i
	}
	for j := 0; j < len(dp[0]); j++ { // 初始化第一行 值为列索引
		dp[0][j] = j
	}
	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			// 相等则不需要操作
			if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else { // 否则删除、插入、替换最小操作次数+1
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1
			}
		}
	}
	return dp[len(word1)][len(word2)]
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}