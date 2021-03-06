package main

import "math"
/*
- 2022-03-26 该程序的C++版本可以正常运行，但是用Go实现的版本无法运行出正确结果。
可能是Go语言和C++在某些方面存在语言特性的差异。但是目前还没有发现造成这个结果的具体原因。
*/

/* 腾讯2020校园招聘-后台
题目描述：
由于业绩优秀，公司给小Q放了 n 天的假，身为工作狂的小Q打算在在假期中工作、锻炼或者休息。
他有个奇怪的习惯：不会连续两天工作或锻炼。只有当公司营业时，小Q才能去工作，
只有当健身房营业时，小Q才能去健身，小Q一天只能干一件事。给出假期中公司，
健身房的营业情况，求小Q最少需要休息几天。

输入描述: 第一行一个整数 表示放假天数 第二行 n 个数 每个数为0或1,
第 i 个数表示公司在第 i 天是否营业 第三行 n 个数 每个数为0或1,
第 i 个数表示健身房在第 i 天是否营业 （1为营业 0为不营业）

输出描述: 一个整数，表示小Q休息的最少天数

示例一：
输入: 4
1 1 0 0
0 1 1 0

输出: 2
*/

// // leetcode核心代码模式
// func getDays(work []int, gym []int) int {
// 	// 处理逻辑
// }

// ACM模式
import (
	"fmt"
	// "io"
)

func main() {
	var n, a, b int
	for {
		N, _ := fmt.Scanln(&n)
		if N == 0 {
			break
		}
		work := make([]int, 0)
		for i := 0; i < n; i++ {
			fmt.Scan(&a)
			work = append(work, a)
		}
		gym := make([]int, 0)
		for i := 0; i < n; i++ {
			fmt.Scan(&b)
			gym = append(gym, b)
		}

		// 确认输入是否正确
		// fmt.Println(n)
		// fmt.Println(work)
		// fmt.Println(gym)
		// fmt.Println(res)
		// 处理逻辑

		// dp := [10][3]int{} // 数组是不可变的，注意Go语言里面Slice和C++中vector的区别
		// 本题要求最小休息天数，那么数组在初始化时，应该把元素全部置为最大，因为我们的DP数组使用了min
		dp := make([][]int, n+1)
		for i := range dp {
			dp[i] = make([]int, 3)
		}

		for i := 0; i < n+1; i++ {
			for j := 0; j < 3; j++ {
				dp[i][j] = math.MaxInt32
			}
		}
		
		// fmt.Println(dp)
		dp[0][0], dp[0][1], dp[0][2] = 0, 0, 0

		for i := 1; i <= n; i++ {
			// 看看今天是否能工作
			if work[i-1] == 1 {
				dp[i][1] = min(dp[i-1][0], dp[i-1][2])
			}

			// 看看今天是否能锻炼
			if gym[i-1] == 1 {
				dp[i][2] = min(dp[i-1][0], dp[i-1][1])
			}

			dp[i][0] = (min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1) // 休息多一天
		}

		res := min(dp[n][0], min(dp[n][1], dp[n][2]))
		fmt.Println(res)
		// fmt.Println(dp)
	}
}

func min(x, y int) int {
	if x <= y {
		return x
	}
	return y
}

/*
解题思路：

一、状态转移分析
1、每一天小Q都可能处于3个状态，那就是工作、休息、锻炼
2、若第i天小Q处于工作状态，那么第i-1天只能是休息、锻炼
3、若第i天小Q处于锻炼状态，那么第i-1天只能是休息、工作
4、若第i天小Q处于休息状态，那么第i-1天可能是工作、休息、锻炼。

二、状态转移方程组
基于上述逻辑思路，我们可以用dp[i][0]、dp[i][1]、dp[i][2]
分别表示第i天小Q处于休息、工作、锻炼时最少的休息天数。
那么，可得如下状态转移方程式：

1. 选择休息，故天数多1
dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1

2. 不休息，选择工作
dp[i][1] = min(dp[i-1][0], dp[i-1][2])

3. 不休息，选择锻炼
dp[i][2] = min(dp[i-1][0], dp[i-1][1])

4. 边界：第0天的休息天数为0
dp[0][i] = 0 (i=1, 2, 3)

最后只需拿出第n天各种状态下的最少天数，即为答案。
*/
