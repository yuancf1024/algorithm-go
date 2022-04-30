package leetcode

/* 304. 二维区域和检索 - 矩阵不可变
给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的 左上角 为
 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 
返回 左上角 (row1, col1) 、右下角 (row2, col2) 
所描述的子矩阵的元素 总和 。
*/

type NumMatrix struct {
	cumsum [][]int
}


func Constructor(matrix [][]int) NumMatrix {
	if len(matrix) == 0 {
		return NumMatrix{nil}
	}
	cumsum := make([][]int, len(matrix)+1)
	cumsum[0] = make([]int, len(matrix[0])+1)
	for i := range matrix {
		cumsum[i+1] = make([]int, len(matrix[i])+1)
		for j := range matrix[i] {
			cumsum[i+1][j+1] = matrix[i][j] + cumsum[i][j+1] + cumsum[i+1][j] - cumsum[i][j]
		}
	}
	return NumMatrix{cumsum}
}


func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	cumsum := this.cumsum
	return cumsum[row2+1][col2+1] - cumsum[row1][col2+1] - cumsum[row2+1][col1] + cumsum[row1][col1]
}


/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */

/*
解题思路 #
这一题是一维数组前缀和的进阶版本。
定义 f(x,y) 代表矩形左上角 (0,0)，右下角 (x,y) 内的元素和。

于是得到递推的关系式：
f(i, j) = f(i-1, j) + f(i, j-1) - f(i-1, j-1) + matrix[i][j]，
写代码为了方便，新建一个 m+1 * n+1 的矩阵，
这样就不需要对 row = 0 和 col = 0 做单独处理了。


时间复杂度：初始化 O(mn)，查询 O(1)。空间复杂度 O(mn)
*/