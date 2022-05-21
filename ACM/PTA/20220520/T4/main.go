package main

import (
	"fmt"
	"io"
)
/* 7-4 关于奇数的等式
给定任一正奇数 n>3 和一个解的上界 m>3，求三个正奇数 x、y、z，
满足 0<x<y<z≤m 且有等式 3/n=1/x+1/y+1/z。

输入格式：
输入给出正奇数 3<n<400 和解的上界 m≤1000。

输出格式：
在一行中输出给定范围内最小的一组解 x y z
（即存在多组解时取最小的 x，并列时取最小的 y）。
数字间以 1 个空格分隔，行首尾不得有多余空格。

如果给定范围内无解，则输出 No solution in (3, m]. 
其中 m 是给定的上界。

输入样例 1：
27 500

输出样例 1：
11 55 495

输入样例 2：
27 50

输出样例 2：
No solution in (3, 50].

*/

func main() {
	var n, m int
	for {
		_, err := fmt.Scanf("%d %d", &n, &m)
		// x := make([]int, 0)
		// y := make([]int, 0)
		// z := make([]int, 0)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			// fmt.Printf("%d %d\n", n, m)
			var find bool = false
			for i := 1; i <= m; i += 2 {
				for j := i+2; j <= m; j += 2 {
					for k := j+2; k <= m; k += 2 {
						if 3*i*j*k == n*(i*j+i*k+j*k) {
							// x = append(x, i) // 有趣，这个地方使用数组来储存x、y、z却得不到最终的结果
							// y = append(x, j)
							// z = append(x, k)
							fmt.Printf("%d %d %d\n", i, j, k)
							find = true
							break
						}
					}
					if find {
						break
					}
				}
				if find {
					break
				}
			}
			// if len(x) == 0 {
			// 	fmt.Printf("No solution in (3, %d].\n", m)
			// } 
			// else {
			// 	fmt.Printf("%d %d %d\n", x[0], y[0], z[0])
			// }
			if !find {
				fmt.Printf("No solution in (3, %d].\n", m)
			}
			
		}
	}
}
