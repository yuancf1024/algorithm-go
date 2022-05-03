package main

/*
训练营有三位同学抽到了大奖，现在准备把一些糖果分发给这三位同学。
已知一共有n包糖果，每包糖果里有 2 颗或者3颗。请问是否有一种分发方案，使得这三位同学拿到的糖果数量相等？
请注意，不能把整包糖果拆开分发。

3
3
2 3 3
4
2 2 2 3
8
2 3 2 2 2 2 3 2
*/

import "fmt"

func main() {
    n :=  0
	// ans := 0

	fmt.Scan(&n)
	// fmt.Scan(&m)
	nums := make([][]int, n)
	for i := 0; i < n; i++ {
		// nums[i] = make([]int, m)
		m := 0
		fmt.Scan(&m)
		nums[i] = make([]int, m)
		for j := 0; j < m; j++ {
			x := 0
			fmt.Scan(&x)
			nums[i][j] = x
			// ans = ans + x
		}
	}
	// 核心代码
	for i := 0; i < n; i++ {
		// fmt.Println(nums[i])
		isCondition(nums[i])
	}

}

func isCondition(nums []int) {
	res := "NO"
	n := len(nums)
	sum := 0
	sum1, sum2 := 0, 0
	// 逻辑条件
	for i := 0; i < n; i++ {
		sum += nums[i]
	}

	target := sum / 3.0



	// sum 代表总和
	for i := 0; i < n; i++ {
		for j := i+1; j < n; j++ {
			for k := j+1; k < n; k++ {
				
			}
		}
	}

	for i := 0; i < n; i++ {
		if sum1 != target {
			sum1 += nums[i]
		}

		if sum2 != target {
			sum2 += nums[i]
		}
		
		if sum1 == target && sum2 == target {
			res = "YES"
			break
		}
	}

	// return res
	fmt.Println(res)
}