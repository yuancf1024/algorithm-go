package main

import "fmt"

func main() {
	var n, num int
	nums := make([]int, 0)
	fmt.Scan(&n)
	for ; n > 0; n-- {
		fmt.Scan(&num)
		nums = append(nums, num)
	}
	// 核心代码区
	begin := 1000
	profit := 0
	stock_num := begin / nums[0]
	for i := 1; i < n-1; i++ {
		if nums[i] > nums[i+1] {
			profit += stock_num * (nums[i] - nums[0])
		} else {
			continue
		}
	}
	fmt.Println(begin + profit)
	// for i := 0; i < len(nums); i++ {
	// 	fmt.Println(nums[i])
	// }
}
