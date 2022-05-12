package main

import (
	"fmt"
	// "sort"
	// "io"
	// "strconv"
)

/*
2 2
1 1
1 2
2 1
*/


// Go语言实现的图，还不太熟悉，属于知识盲区，建议C++实现
func main() {
	var n, m int
	fmt.Scanf("%d%d", &n, &m)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	u := make([]int, m)
	v := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d", &u[i], &v[i])
	}
	// 核心代码
	// for i := 0; i < m; i++ {
	// 	fmt.Println(v[i])
	// }


	// fmt.Println(dp[N][W])
}

// func depthFirst(m map[string][]string) []string {
//     var order []string
//     seen := make(map[string]bool)
//     var visitAll func(items []string)
//     visitAll = func(items []string) {
//         for _, item := range items {
//             if !seen[item] {
//                 seen[item] = true
//                 visitAll(m[item])
//                 order = append(order, item)
//             }
//         }
//     }
//     var keys []string
//     for key := range m {
//         keys = append(keys, key)
//     }
//     sort.Strings(keys)
//     visitAll(keys)
//     return order
// }
