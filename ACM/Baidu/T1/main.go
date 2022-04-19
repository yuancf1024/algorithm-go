package main

import "fmt"

func main() {
	var m, n int
	var x int
	var nums []int
	// var time []int
	// timeSum := 0
	for {
		fmt.Scan(&m, &n)
		for i := 0; i < m; i++ {
			fmt.Scan(&x)
			nums = append(nums, x)
			// timeSum += x
		}

		// fmt.Println(nums)

		// 逻辑代码

	}
}

/*
6 5 
100 1 3 0 10 100

7

通过率：

动态规划

*/
