package main

import (
    "fmt"
	// "io"
	// "strconv"
)

/*
6 2
2 3 1 1 1 2

6

3 2
1 1 4

8
*/

func main() {
    n, m := 0, 0 // n是数组长度，m为初始资金
	fmt.Scanf("%d%d", &n, &m)
	nums := make([]int, 0)
	x := 0
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &x)
		nums = append(nums, x)
	}

	// 核心代码区

	// 股票一直跌的情况
	t := 1
	for i := 1; i < n; i++ {
		if nums[i-1] > nums[i] {
			t++
		}
	}
	if t == n {
		fmt.Println(m)
	}

	// 

	// for i := 0; i < n; i++ {
	// 	fmt.Printf("%d ", nums[i])
	// }

}