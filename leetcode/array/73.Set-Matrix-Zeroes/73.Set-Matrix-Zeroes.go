package leetcode

// 原地算法+常量空间 使用2个标记变量
func setZeroes(matrix [][]int)  {
	rowLen, colLen := len(matrix), len(matrix[0])
	if rowLen == 0 || colLen == 0 {
		return
	}

	isFirstRowExistZero, isFirstColExistZero := false, false
	for i := 0; i < rowLen; i++ {
		if matrix[i][0] == 0 {
			isFirstColExistZero = true
			break
		}
	}

	for j := 0; j < colLen; j++ {
		if matrix[0][j] == 0 {
			isFirstRowExistZero = true
			break
		}
	}

	for i := 1; i < rowLen; i++ {
		for j := 1; j < colLen; j++ {
			if matrix[i][j] == 0 {
				matrix[i][0] = 0
				matrix[0][j] = 0
			}
		}
	}

	// 处理[1:]行全部置为0
	for i := 1; i < rowLen; i++ {
		if matrix[i][0] == 0 {
			for j := 1; j < colLen; j++ {
				matrix[i][j] = 0
			}
		}
	}

	// 处理[1:]列全部置为0
	for j := 1; j < colLen; j++ {
		if matrix[0][j] == 0 {
			for i := 1; i < rowLen; i++ {
				matrix[i][j] = 0
			}
		}
	}

	if isFirstRowExistZero {
		for j := 0; j < colLen; j++ {
			matrix[0][j] = 0
		}
	}
	if isFirstColExistZero {
		for i := 0; i < rowLen; i++ {
			matrix[i][0] = 0
		}
	}
}

/*Solution:
此题考查对程序的控制能力，无算法思想。题目要求采用原地的算法，
所有修改即在原二维数组上进行。在二维数组中有 2 个特殊位置，
一个是第一行，一个是第一列。它们的特殊性在于，它们之间只要有一个 0，
它们都会变为全 0 。先用 2 个变量记录这一行和这一列中是否有 0，
防止之后的修改覆盖了这 2 个地方。然后除去这一行和这一列以外的部分
判断是否有 0，如果有 0，将它们所在的行第一个元素标记为 0，
所在列的第一个元素标记为 0 。最后通过标记，将对应的行列置 0 即可。
*/

/*
进阶：

1. 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
2. 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
3. 你能想出一个仅使用常量空间的解决方案吗？
*/

// 方法1：使用标记数组
func setZeroes1(matrix [][]int) {
	row := make([]bool, len(matrix))
	col := make([]bool, len(matrix[0]))

	for i, r := range matrix {
		for j, v := range r {
			if v == 0 {
				row[i] = true
				col[j] = true
			}
		}
	}

	for i, r := range matrix {
		for j := range r {
			if row[i] || col[j] {
				r[j] = 0
			}
		}
	}
}

/*
思路和算法
我们可以用两个标记数组分别记录每一行和每一列是否有零出现。

具体地，我们首先遍历该数组一次，如果某个元素为 0，
那么就将该元素所在的行和列所对应标记数组的位置置为 true。
最后我们再次遍历该数组，用标记数组更新原数组即可。

复杂度分析

时间复杂度：O(mn)，其中 m 是矩阵的行数，n 是矩阵的列数。
我们至多只需要遍历该矩阵两次。

空间复杂度：O(m+n)，其中 m 是矩阵的行数，n 是矩阵的列数。
我们需要分别记录每一行或每一列是否有零出现。
*/