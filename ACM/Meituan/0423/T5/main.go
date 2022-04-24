package main

import "fmt"

/*
样例输入
5 10
ADD 1 10
QUERY
ADD 2 5
PASS 3
PASS 2
QUERY
PASS 10
QUERY
PASS 5
QUERY
样例输出
1
2
1
-1
*/

func main() {
    var t, n, num, c int
	log := make([][])
    fmt.Scan(&t, &n)
    for ; n > 0; n-- {
        fmt.Scan(&n)
		for ; n > 0; n-- {
			fmt.Scan(&num)
			nums = append(nums, num)
		}
		// 核心代码
		// 排序要求：每次交换相邻数，且两个数颜色不能相同
		
    }
}