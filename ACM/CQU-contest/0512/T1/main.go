package main

import (
	"fmt"
	// "io"
	// "strconv"
)

/*
input
70 3
71 100
69 1
1 2

output
3
*/

// 可同时输入多组示例的实现
func main() {
	var T, M int
	fmt.Scanf("%d%d", &T, &M)
	time := make([]int, M+1)
	value := make([]int, M+1)
	for i := 0; i < M; i++ {
		fmt.Scanf("%d %d", &time[i], &value[i])
	}
	// 核心代码
	// for i := 0; i < M; i++ {
	// 	fmt.Println(time[i])
	// }
	N := M
	W := T
	wt := time
	val := value
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, W+1)
	}

	for i := 0; i <= N; i++ {
		dp[0][i] = 0
	}
	for i := 0; i <= N; i++ {
		dp[i][0] = 0
	}

	for i := 1; i <= N; i++ {
		for w := 1; w <= W; w++ {
			if w-wt[i-1] < 0 {
				dp[i][w] = dp[i-1][w]
			} else {
				dp[i][w] = max(dp[i-1][w-wt[i-1]]+val[i-1], dp[i-1][w])
			}
		}
	}
	fmt.Println(dp[N][W])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}



	// for { // 循环获取输入
	// 	if _, err := fmt.Scanf("%d"&a); err != io.EOF {
	// 		// 核心代码
	// 		var res bool
	// 		// res = isPalindrome(a)
	// 		fmt.Println(res)
	// 		// fmt.Println(a)
	// 	} else {
	// 		break
	// 	}
	// }