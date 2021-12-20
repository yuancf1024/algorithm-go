// Fibonacci的尾递归实现
package main

import "fmt"

func F(n int, a1, a2 int) int {
	if n == 0 {
		return a1
	}

	return F(n-1, a2, a1+a2)
}

func main() {
	fmt.Println(F(1, 1, 1))
	fmt.Println(F(2, 1, 1))
	fmt.Println(F(3, 1, 1))
	fmt.Println(F(4, 1, 1))
	fmt.Println(F(5, 1, 1))
}

// 当 n=5 的递归过程如下:
// F(5,1,1)
// F(4,1,1+1)=F(4,1,2)
// F(3,2,1+2)=F(3,2,3)
// F(2,3,2+3)=F(2,3,5)
// F(1,5,3+5)=F(1,5,8)
// F(0,8,5+8)=F(0,8,13)
// 8