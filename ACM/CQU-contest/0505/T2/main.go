package main

import (
	"fmt"
	"io"
	// "strconv"
)

/*
input:
10 5 5 5

9

3 0 0 2

0
*/

func main() {
	var n, a, b, c int
	res := 0
	for {
		_, err := fmt.Scanf("%d%d%d%d", &n, &a, &b, &c)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			// fmt.Printf("%d\n", a+b)
			res = solutions(n, a, b, c)
			fmt.Println(res)
		}
	}
}

func solutions(n, a, b, c int) int {
	var ans = 0
	// 枚举

	// 边界条件无解的情况
	if a/2+1*b+2*c < n {
		return ans
	}

	// 核心代码
	// 暴力枚举
	for i := 0; i <= a; i = i+2 {
		for j := 0; j <= b; j++ {
			for k := 0; k <= c; k++ {
				if i/2+j+k*2 == n {
					ans++
					fmt.Println(i, j, k)
				}
			}
		}
		
	}

	return ans
}