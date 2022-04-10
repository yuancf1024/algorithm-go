package leetcode

/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

func generate(numRows int) [][]int {
	res := [][]int{}
	for i := 0; i < numRows; i++ {
		row := []int{}
		for j := 0; j < i+1; j++ {
			if j == 0 || j == i {
				row = append(row, 1)
			} else if i > 1 {
				row = append(row, res[i-1][j-1] + res[i-1][j])
			}
		}
		res = append(res, row)
	}
	return res
}

/*
给定一个 n，要求打印杨辉三角的前 n 行。
简单题。按照杨辉三角的生成规则循环打印即可。
*/

// 官方题解
func generate1(numRows int) [][]int {
	res := make([][]int, numRows)
	for i := range res {
		res[i] = make([]int, i+1)
		res[i][0] = 1
		res[i][i] = 1
		for j := 1; j < i; j++ {
			res[i][j] = res[i-1][j] + res[i-1][j-1]
		}
	}
	return res
}
