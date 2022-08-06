package main

import (
	"fmt"
	"io"
	// "math"
)

/*
春天是鲜花的季节，水仙花就是其中最迷人的代表，
数学上有个水仙花数，他是这样定义的： “水仙花数”是
指一个三位数，它的各位数字的立方和等于其本身，
比如：153=1^3+5^3+3^3。 
现在要求输出所有在m和n范围内的水仙花数。
样例输入
100 120
300 380

样例输出
no
370 371
*/

func main() {
	m := 0
	n := 0
	for {
		_, err := fmt.Scanf("%d%d", &m, &n)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码区
			t := 0
			for i := m; i <= n; i++ {
				a := i / 100
				b := i%100/10
				c := i%10

				if (i == a*a*a + b*b*b + c*c*c) && t == 0 {
					fmt.Printf("%d ", i)
					t++;
				} else if (i == a*a*a + b*b*b + c*c*c) && t == 1 {
					fmt.Printf("%d ", i)
				}
			}
			if t != 0 {
				fmt.Println()
			}
			if t == 0 {
				fmt.Println("no")
			}
			// fmt.Printf("%.2f\n", s)
		}
	}
}
