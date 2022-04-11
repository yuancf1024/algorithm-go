package leetcode

import "strconv"

/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，
验证已经填入的数字是否有效即可。

1. 数字 1-9 在每一行只能出现一次。
2. 数字 1-9 在每一列只能出现一次。
3. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

注意：

	一个有效的数独（部分已被填充）不一定是可解的。
	只需要根据以上规则，验证已经填入的数字是否有效即可。
	空白格用 '.' 表示。
*/

// 解法1 暴力遍历，时间复杂度O(n^3)
func isValidSudoku1(board [][]byte) bool {
	// 判断行 row
	for i := 0; i < 9; i++ {
		tmp := [10]int{}
		for j := 0; j < 9; j++ {
			cellVal := board[i][j : j+1]
			if string(cellVal) != "." {
				index, _ := strconv.Atoi(string(cellVal))
				if index > 9 || index < 1 {
					return false
				}
				if tmp[index] == 1 {
					return false
				}
				tmp[index] = 1
			}
		}
	}

	// 判断 column
	for i := 0; i < 9; i++ {
		tmp := [10]int{}
		for j := 0; j < 9; j++ {
			cellVal := board[j][i]
			if string(cellVal) != "." {
				index, _ := strconv.Atoi(string(cellVal))
				if index > 9 || index < 1 {
					return false
				}
				if tmp[index] == 1 { // 判断tmp数组中index是否出现过
					return false
				}
				tmp[index] = 1 // 标记数组中index出现1次
			}
		}
	}

	// 判断9宫格 3*3 cell
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			tmp := [10]int{}
			for ii := i * 3; ii < i*3+3; ii++ {
				for jj := j * 3; jj < j*3+3; jj++ {
					cellVal := board[ii][jj]
					if string(cellVal) != "." {
						index, _ := strconv.Atoi(string(cellVal))
						if tmp[index] == 1 {
							return false
						}
						tmp[index] = 1
					}
				}
			}
		}
	}
	return true
}

// 解法2 添加缓存，时间复杂度O(n^2)
func isValidSudoku(board [][]byte) bool {
	rowbuf, colbuf, boxbuf := make([][]bool, 9), make([][]bool, 9), make([][]bool, 9)
	for i := 0; i < 9; i++ {
		rowbuf[i] = make([]bool, 9)
		colbuf[i] = make([]bool, 9)
		boxbuf[i] = make([]bool, 9)
	}

	// 遍历一次，添加缓存
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			if board[r][c] != '.' {
				num := board[r][c] - '0' - byte(1)
				if rowbuf[r][num] || colbuf[c][num] || boxbuf[r/3*3+c/3][num] {
					// board中的元素在缓存中是否出现过？如果出现，不满足规则，返回false
					return false
				}
				rowbuf[r][num] = true // 将遍历到的元素添加进相应缓存中
				colbuf[c][num] = true
				boxbuf[r/3*3+c/3][num] = true // r,c 转换到box方格中
			}
		}
	}
	return true
}


/*Solution:
给出一个数独的棋盘，要求判断这个棋盘当前是否满足数独的要求：
即行列是否都只包含 1-9，每个九宫格里面是否也只包含 1-9 。
注意这题和第 37 题是不同的，这一题是判断当前棋盘状态是否满足数独的要求，
而第 37 题是要求求解数独。本题中的棋盘有些是无解的，
但是棋盘状态是满足题意的。
*/