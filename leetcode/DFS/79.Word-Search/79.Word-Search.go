package leetcode

/* 79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

 

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true

示例 3：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false

*/

var dir = [][]int {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func exist(board [][]byte, word string) bool {
	visited := make([][]bool, len(board)) // 记录已经访问过的字符，二维切片visited
	for i := 0; i < len(visited); i++ {
		visited[i] = make([]bool, len(board[0]))
	}
	for i, v := range board { // 遍历字符板board上的每一个字符
		for j := range v {
			if searchWord(board, visited, word, 0, i, j) { // DFS搜索目标单词word
				return true
			}
		}
	}
	return false
}

// 判断x、y是否还在board内
func isInboard(board [][]byte, x, y int) bool {
	return x >= 0 && x < len(board) && y >= 0 && y < len(board[0])
}

// 搜索单词
func searchWord(board [][]byte, visited [][]bool, word string, index, x, y int) bool {
	if index == len(word) - 1 { // 如果递归到查找的字符是单词的最后一个字符，直接返回判断结果
		return board[x][y] == word[index]
	}
	if board[x][y] == word[index] {
		visited[x][y] = true // 将x、y标记为已经遍历过
		for i := 0; i < 4; i++ {
			nx := x + dir[i][0]
			ny := y + dir[i][1]
			// 如果x、y四周的点还在字符网格board内，且没有遍历过，并且搜索对应的index的字符返回ture，那么也返回true
			if isInboard(board, nx, ny) && !visited[nx][ny] && searchWord(board, visited, word, index+1, nx, ny) {
				return true
			}
		}
		visited[x][y] = false // 遍历了x、y四周之后，将x、y标记为false，方便后面遍历其他点的时候再遍历到x、y
	}
	return false
}
/*
解题思路
在地图上的任意一个起点开始，向 4 个方向分别 DFS 搜索，
直到所有的单词字母都找到了就输出 true，否则输出 false。

进阶：你可以使用搜索剪枝的技术来优化解决方案，
使其在 board 更大的情况下可以更快解决问题？
*/

