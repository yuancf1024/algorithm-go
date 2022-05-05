package main

import (
	// "crypto/aes"
	"fmt"
	"io"

	// "sort"
	"strconv"
)

/*
input:
3 2
50 4 20

3 3
9 77 13
*/

func main() {
	var n, k int
	var res int
	var nums []int
	var x, y int
	for {
		fmt.Scanf("%d%d", &n, &k)
		for i := 0; i < n; i++ {
			fmt.Scan(&x)
			nums = append(nums, x)
		}

		// 核心代码
		// fmt.Println(n , k)
		// for i := 0; i < len(nums); i++ {
		// 	fmt.Println(nums[i])
		// }
		var tmp = 1
		if n == k {
			for i := 0; i < n; i++ {
				tmp *= nums[i]
			}
			a1 := hasNzero(tmp)
			fmt.Println(a1)
		}
		if k < n {
			res = solutions(nums, k)
			fmt.Println(res)
		}

		_, err := fmt.Scanf("%d", &y)
		if err != nil {
			if err == io.EOF {
				break
			}
		}
	}
}

func solutions(nums []int, k int) int {
	ans := 0
	tmp := 0
	res := make([]int, 0)

	// 核心逻辑
	// 维护一个窗口
	// 回溯
	// 从数组nums中找到k个数的乘积,
	track := []int{}
	backtracking(nums, k, 0, track, &res)
	// fmt.Println(num)
	// for i := 0; i < len(res); i++ {
	// 		fmt.Println(res[i])
	// 	}

	// 假设数组res已经建立好了
	for i := 0; i < len(res); i++ {
		tmp = hasNzero(res[i])
		if tmp >= ans {
			ans = tmp
		}
	}

	return ans
}

func backtracking(nums []int, k, start int, track []int, res *[]int) {
	if len(track) == k {
		sum := 1
		for i := 0; i < len(track); i++ {
			sum *= track[i]
		}
		*res = append(*res, sum)
	}
	for i := start; i < len(nums); i++ {
		track = append(track, nums[i])
		backtracking(nums, k, i+1, track, res)
		track = track[:len(track)-1]
	}
}

func hasNzero(num int) int {
	zero := 0
	str := strconv.Itoa(num)
	n := len(str) - 1
	for i := 0; i < n; i++ {
		// if num < 10 {
		// 	break
		// }
		if num%10 == 0 {
			zero++
		}
		num %= 10 // 这是一个比赛过程的bug ,此处要去除最后一位
		// num /= 10
	}
	return zero
}

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }
