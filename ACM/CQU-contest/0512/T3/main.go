package main

import (
	"fmt"
	// "sort"
	// "io"
	// "strconv"
)

/*
input
2 3

output
6
*/

func main() {
	var n, m int
	fmt.Scanf("%d%d", &m, &n) // m 信仰
	// 核心代码
	// fmt.Println(m, n)
	var res int
	num := 1
	for i := 0; i < n; i++ {
		num *= m
	}

	var num1 int
	
	

	res = num - num1

	fmt.Println(res % 100003)
}


