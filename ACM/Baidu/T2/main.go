package main

import "fmt"

func main() {
	var m, n int
	var x, y int
	var nums []int
	var time []int
	timeSum := 0
	for {
		fmt.Scan(&m, &n)
		for i := 0; i < m; i++ {
			fmt.Scan(&x)
			nums = append(nums, x)
			timeSum += x
		}
		for j := 0; j < n; j++ {
			fmt.Scanln(&y)
			time = append(time, y)
		}
		// fmt.Println(timeSum)

		// fmt.Println(nums)
		// fmt.Println(time)
		// 逻辑代码
		for i := 0; i < n; i++ {
			useTime := 0
			for j := 0; j < m; j++ {
				useTime += nums[j]
				if useTime == timeSum {
					fmt.Println(m)
					break
				}
				if useTime > time[i] {
					fmt.Println(j)
					break
				}
			}
		}
		break
	}
}

/*
7 4
1 2 3 1 2 3 1
1
8
11
14

1
4
5
7

通过率：60%
*/
