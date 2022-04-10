package leetcode

/*
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵
重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，
分别表示想要的重构的矩阵的行数和列数。
重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；
否则，输出原始矩阵。
*/

// 官方题解：二维数组的一维表示
func matrixReshape(mat [][]int, r int, c int) [][]int {
	n, m := len(mat), len(mat[0])
	if n * m != r * c {
		return mat
	}

	res := make([][]int, r)
	for i := range res {
		res[i] = make([]int, c)
	}
	for j := 0; j < n * m; j++ {
		res[j/c][j%c] = mat[j/m][j%m] // 本题的巧妙点
	}
	return res
}

/*
题目需要我们做的事情相当于：
- 将二维数组 nums 映射成一个一维数组；
- 将这个一维数组映射回 r 行 c 列的二维数组。

复杂度分析：
- 时间复杂度：O(rc)。这里的时间复杂度是在重塑矩阵成功的前提下的时间复杂度，
否则当mn != rc 时，C++ 语言中返回的是原数组的一份拷贝，
本质上需要的时间复杂度为 O(mn)，而其余语言可以直接返回原数组的对象，
需要的时间复杂度仅为 O(1)。
- 空间复杂度:O(1)。这里的空间复杂度不包含返回的重塑矩阵需要的空间。（返回值不计入空间消耗）
*/

// 模拟
func matrixReshape1(mat [][]int, r int, c int) [][]int {
	if canReshape(mat, r, c) {
		return reshape(mat, r, c)
	}
	return mat
}

func canReshape(nums [][]int, r, c int) bool {
	row := len(nums)
	column := len(nums[0])
	if row * column == r * c {
		return true
	}
	return false
}

func reshape(nums [][]int, r, c int) [][]int {
	newShape := make([][]int, r)
	for index := range newShape {
		newShape[index] = make([]int, c)
	}

	rowIndex, colIndex := 0, 0
	for _, row := range nums { // row 代表行数组
		for _, col := range row { // col 代表行数组中的元素
			if colIndex == c { // 列索引归零，行索引+1
				colIndex = 0
				rowIndex++
			}
			newShape[rowIndex][colIndex] = col
			colIndex++
		}
	}
	return newShape
}

/*
给一个二维数组和 r，c，将这个二维数组“重塑”成行为 r，列为 c。
如果可以“重塑”，输出“重塑”以后的数组，如果不能“重塑”，输出原有数组。
这题也是水题，按照题意模拟即可。
*/