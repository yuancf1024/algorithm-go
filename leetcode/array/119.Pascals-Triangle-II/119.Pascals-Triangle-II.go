package leetcode

/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

// 自己写的
func getRow1(rowIndex int) []int {
    res := [][]int{}
    for i := 0; i <= rowIndex; i++ { // 和leetcode118的差异
        row := []int{}
        for j := 0; j < i+1; j++ {
            if j == 0 || j == i {
                row = append(row, 1)
            }else if i > 1 {
                row = append(row, res[i-1][j] + res[i-1][j-1])
            }
            
        }
        res = append(res, row)
    }
    return res[rowIndex]
}

// 更优雅的解法 优化到 O(rowIndex) 空间复杂度
// TODO
func getRow(rowIndex int) []int {
    row := make([]int, rowIndex+1)
    row[0] = 1
    for i := 1; i <= rowIndex; i++ {
        row[i] = row[i-1] * (rowIndex - i + 1) / i
    }
    return row
}

/* 解题思路
题目中的三角是杨辉三角，每个数字是 (a+b)^n 二项式展开的系数。
题目要求我们只能使用 O(k) 的空间。那么需要找到两两项直接的递推关系。
由组合知识得知：
C_{n}^{m} = \frac{n!} {m!*(n-m)!}

C_{n}^{m-1} = \frac{n!} {(m-1)!*(n-m+1)!}
于是得到递推公式：

C_{n}^{m} = C_{n}^{m-1} * \frac{n-m+1} {m}
利用这个递推公式即可以把空间复杂度优化到 O(k)
*/