// 本题为考试多行输入输出规范示例，无需提交，不计分。
package main

import (
	"fmt"
)

func main() {
	n, m := 0, 0
	// ans := 0

	fmt.Scan(&n)
	fmt.Scan(&m)
	nums := make([][]int, n)
	for i := 0; i < n; i++ {
		nums[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			x := 0
			fmt.Scan(&x)
			nums[i][j] = x
			// ans = ans + x
		}
	}
	// 0 1 互换
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if nums[i][j] == 0 {
				nums[i][j] = 1
			} else {
				nums[i][j] = 0
			}
			// nums[i][j] = x
			// ans = ans + x
		}
	}
	// 核心逻辑区
	// 深度优先

	res := 0
	for i, row := range nums {
		for j, col := range row {
			if col == 0 {
				continue
			}
			area := numOfCinema(nums, i, j)
			if area > res {
				res = area
			}
		}
	}
	fmt.Println(res)
	// fmt.Printf("%d\n",ans)
	// for i := 0; i < n; i++ {
	//     for j := 0; j < m; j++ {
	//         fmt.Println(nums[i][j])
	//         // ans = ans + x
	//     }
	// }
}

// 寻找最大影院数量 函数定义区域
var dir = [][]int{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func isInCinema(grid [][]int, x, y int) bool {
	return x >= 0 && x < len(grid) && y >= 0 && y < len(grid[0])
}

func numOfCinema(grid [][]int, x, y int) int {
	if !isInCinema(grid, x, y) || grid[x][y] == 0 {
		return 0
	}
	grid[x][y] = 0
	total := 1
	for i := 0; i < 4; i++ {
		nx := x + dir[i][0]
		ny := y + dir[i][1]
		total += numOfCinema(grid, nx, ny)
	}
	return total
}
