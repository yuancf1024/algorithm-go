package main

import (
	"fmt"
	"io"
)

/*
input:
3 4 1 2

output:
4

input:
1 1 5 6

output:
0
*/

func main() {
	n, m := 0, 0 // 苹果 桃子数量
	a := 0 // 1号 2 号 大礼包的价值
	b := 0
//     var int64 a
//     var int64 b

    
	for {
		// var int n
		// var int m
		// var int a
		// var int b
		_, err := fmt.Scanf("%d %d %d %d", &n, &m, &a, &b)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			// fmt.Printf("%d %d\n", n, m)
			// fmt.Printf("%d %d\n", a, b)

			// 条件判断
			res := 0
			if n < 2 && m < 2 {
				fmt.Printf("%d\n", res)
			} else if n < 2 || m < 2 {
				fmt.Printf("%d\n", max(a, b))
			} else {
				// 核心代码
				res = maxValue(n, m, a, b)
				fmt.Printf("%d\n", res)
			}
		}
	}
}

func maxValue(n, m, a, b int) int {
	// ans := 0
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, m+1)
	}
	// 初始化第一行
	dp[0][0] = 0
	dp[0][1], dp[1][0] = 0, 0
	dp[1][1] = 0
	for i := 2; i < m+1; i++ {
		dp[0][i] = 0
		dp[1][i] = b
	}
	// 第一列
	for j := 2; j < n+1; j++ {
		dp[j][0] = 0
		dp[j][1] = a
	}

	if a > b {
		dp[2][2] = a
	} else {
		dp[2][2] = b
	}

	for i := 3; i < n+1; i++ {
		for j := 3; j < m+1; j++ {
			// c2 := j / 2
			// for k := 0; k <= c1; k++ {
			// 	ans = max(dp[])
			// }
			dp[i][j] = max(dp[i-2][j-1]*(i/2), dp[i-1][j-2]*(j/2))
		}
	}
	// fmt.Println(dp[n+1][m+1])
	return dp[n][m]
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
