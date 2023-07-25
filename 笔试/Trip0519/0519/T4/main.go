package main

import (
	"fmt"
	"io"
)

/*
input:
4
25 30 125 64

output:
2
*/

func main() {
	n := 0
	// b := 0
	for {
		_, err := fmt.Scanf("%d", &n)
		num := make([]int64, n)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &num[i])
		}
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			// for i := 0; i < n; i++ {
			// 	fmt.Printf("%d\n", num[i])
			// }
			// fmt.Printf("%d\n", a+b)
			// res := 0
			if n <= 2 {
				fmt.Println(0)
			} else {
				fmt.Println(minZero(num))
			}
			
		}
	}
}

func minZero(num []int64) int {
	ans := 0
//     tmp := 0
	for i := 2; i < len(num); i++ {
		for j := 0; j < i; j++ {
			if i-j >=2 {
// 				tmp = 
				ans = max(ans, minZeros(num[j] * num[i]))
				// fmt.Println(tmp)
			}
			
		}
		
	}
	return ans
}

func minZeros (num int64) int {
	output := 0
	for i := num; i >= 10 ;  {
		if i %10 == 0 {
			output++
			// fmt.Println(output)
		}
		i = i/10
	}
	return output
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}