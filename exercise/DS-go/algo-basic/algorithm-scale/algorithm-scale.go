package main

import "fmt"

// 循环遍历累加
func sum(n int) int {
	total := 0
	// 从1加到N, 1+2+3+4+...+N
	for i := 1;i <= n; i++ {
		total += i
	}
	return total
}

// 高斯算法
func sum2(n int) int {
	total := ((1 + n) * n) / 2
	return total
}

func main() {
	fmt.Println(sum(100))
	fmt.Println(sum2(100))
}