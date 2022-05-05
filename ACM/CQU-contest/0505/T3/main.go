package main

import (
	"fmt"
	"io"
	"sort"
	// "strconv"
)

/*
input:
8 9 10
1 2 8 9 10
*/

func main() {
	var a, b, c int
	var res []int
	for {
		_, err := fmt.Scanf("%d%d%d", &a, &b, &c)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			res = traversal(a, b, c)
			// 去重
			// for i := 1; i < len(res); i++ {
			// 	if res[i] == res[i-1] {
			// 		res
			// 	}
			// }
			for i := 0; i < len(res)-1; i++ {
				fmt.Print(res[i])
				fmt.Print(" ")
			}
			fmt.Print(res[len(res)-1])
		}
	}
}

func traversal(a, b, c int) []int {
	var res []int
	res = append(res, c)

	if c > a {
		res = append(res, c-a)
		res = append(res, a)
	}

	if c > b {
		res = append(res, b)
		res = append(res, c-b)
		
	}

	if a < b && (b-a) != (c-a) && (b-a) != (c-b) {
		res = append(res, b-a)
	} else if a > b && (a-b) != (c-a) && (b-a) != (c-b) {
		res = append(res, a- b)
	}
	


	sort.Slice(res, func(i int, j int) bool {
		return res[i] < res[j]
	})
	return res
}