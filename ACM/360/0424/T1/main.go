package main

import (
	"fmt"
)

func main() {
	n, m := 0, 0
	// ans := 0

	fmt.Scan(&n, &m)
	// fmt.Scan(&m)
	nums := make([][]int, n)
	for i := 0; i < n; i++ {
		nums[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			x := 0
			fmt.Scan(&x)
			nums[i][j] = x
			// ans = ans + x
		}
	}
	// for i := 0; i < n; i++ {
	//     for j := 0; j < m; j++ {
	//         fmt.Println(nums[i][j])
	//         // ans = ans + x
	//     }
	// }
	// 核心代码区
	// 	需要以7天为周期做一个求和
	// res := make([]int , m)
	// ans := make([]int, 0)
	// k := n/7+1
	max := make([][]int,n/7+1)
	for i := 0; i < n/7+1; i++ {
		max[i] = make([]int, m)
	}

	for i := 0; i < m; i++ {
		for k := 0; k < n/7+1; k++ {
			if k < n/7 {
				for j := k*7; j < k*7+7; j++ {
					// res[i] += nums[j][i]
					max[k][i] += nums[j][i]
				}
			} else {
				for j := k*7; j < n; j++ {
					// res[i] += nums[j][i]
					max[k][i] += nums[j][i]
				}
			}
			
		}
		// ans = append(ans, res[i])
	}
	output := 0
	for i := 0; i < n/7+1; i++ {
		tmp := max[i][0]
		for j := 1; j < m; j++ {
			if max[i][j] > tmp {
				tmp = max[i][j]
			}
		}
		output += tmp
	}
	// for i := 1; i < m; i++ {
	// 	if ans[i] > output {
	// 		output = ans[i]
	// 	}
	// }
	// for i := 0; i < n/7+1; i++ {
	//     for j := 0; j < m; j++ {
	//         fmt.Println(max[i][j])
	//         // ans = ans + x
	//     }
	// }
	if n <= 7 {
		fmt.Println(output+n/7)
	} else if n <= 14 {
		fmt.Println(output+n/7+1)
	}
}