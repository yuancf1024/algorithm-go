package main

import (
	"fmt"
)

/*
题目描述：
老张在一家工程公司担任规划师。一天，这个工程公司接到
了市政府的道路翻新任务，需要在已有的路网上规划一些
路段进行翻新，并保证规划中的翻新道路经过了所给路网上
所有的结点（一段翻新道路经过其两端的结点），同时
所有翻新的路段必须构成一棵树，也就是说不可以存在
一段不与其他翻新路段相连的翻新路段。因为翻新成本
与道路长度有关，所以需要规划翻新的道路长度和最小，
老张想请你帮忙计算这个最小长度和。
*/

func main() {
	n, m := 0, 0
	// ans := 0

	fmt.Scan(&n, &m)
	// fmt.Scan(&m)
	nums := make([][]int, 3)
	for i := 0; i < n; i++ {
		nums[i] = make([]int, m)
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < m; j++ {
			x := 0
			fmt.Scan(&x)
			nums[i][j] = x
			// ans = ans + x
		}
	}
	for i := 0; i < n; i++ {
	    for j := 0; j < m; j++ {
	        fmt.Println(nums[i][j])
	        // ans = ans + x
	    }
	}
	// 核心代码区
	// 考察构建树，最短路径和
	length := 0
	for i := 0; i < m; i++ {
		length += nums[2][i]
	}
	fmt.Println(length)
}