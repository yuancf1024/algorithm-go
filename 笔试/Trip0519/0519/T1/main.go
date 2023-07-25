package main

import (
	"fmt"
	"io"
	"strconv"
)

/*
input:
8
3 3 2 3 13 13 13 2

output:
3(2) 2 3 13(3) 2
*/

func main() {
	n := 0
	b := 0
	for {
		_, err := fmt.Scanf("%d", &n)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			nums := make([]int, n)
			for i := 0; i < n; i++ {
				fmt.Scanf("%d", &b)
				nums[i] = b
			}
			res := make([]string, 0)
			for i := 1; i < n-1; i++ {
				tmp := 1
				res = append(res, strconv.Itoa(nums[0]))
				if nums[i] != nums[i-1] {
					res = append(res, strconv.Itoa(nums[i]))
					continue
				} else {
					tmp++
				}
				if nums[i] != nums[i+1] {
					res = append(res, strconv.Itoa(nums[i]) + " " + strconv.Itoa(tmp))
				}
			}
			// 遍历数组
			for i := 0; i < len(res)-1; i++ {
				fmt.Print(res[i])
				fmt.Print(" ")
			}
			fmt.Print(res[len(res)-1])
		}
	}
}
