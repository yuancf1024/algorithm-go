package main
/*
N(1≤N≤10^5) 位同学在海滩参加团建，
现在想要建立一个通讯网络供同学们沟通和交流。
第 i 个同学的位置以唯一的 (xi,yi) 来表示,
其中 0<= xi ≤10^6,0≤yi≤10 。
通信网络的架设成本为：(x_i- x_j)^ 2+(y_i-y_j)^2。
若两位同学间有一条链路（节点直接相连或链路由多个子连
接构成），那么这两位同学就可以正常通讯。
请计算出搭建一套能供所有同学正常通讯的网络所需的最小成本。

10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0

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
		m := 2
		// fmt.Scan(&m)
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
		fmt.Println(nums[i])
		// isCondition(nums[i])
	}

}