package leetcode

// 自己写的
func getRow(rowIndex int) []int {
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

// 更优雅的解法
// TODO
