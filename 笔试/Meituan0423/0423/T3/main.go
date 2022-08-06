package main

import "fmt"

/*
样例输入
2
5
3 2 4 1 5
1 2 2 3 1
3
2 2 1
1 1 1
样例输出
Yes
No
*/

func main() {
    var t, n, num, c int
	nums := make([]int, 0)
	color := make([]int, 0)
    fmt.Scan(&t)
    for ; t > 0; t-- {
        fmt.Scan(&n)
		m := n
		for ; n > 0; n-- {
			fmt.Scan(&num)
			nums = append(nums, num)
		}
		for ; m > 0; m-- {
			fmt.Scan(&c)
			color = append(color, c)
		}
		// 核心代码
		// 排序要求：每次交换相邻数，且两个数颜色不能相同
		a := len(nums)
		// 冒泡排序
		for i := 1; i < a; i++ {
			for j := i; j > 0; j-- {
				if nums[j] < nums[j-1] {
					nums[j], nums[j-1] = nums[j-1], nums[j]
					color[j], color[j-1] = color[j-1], color[j]
				}
			}
		}
		count := 0
		for i := 1; i < a; i++ {
			if color[i] == color[i-1] {
				// fmt.Println("No")
				break
			}
			count++
		}
		if count == a {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
    }
}