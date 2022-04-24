package main

import (
	"fmt"
	"io"
	"math"
)

/*
数列的定义如下： 数列的第一项为n，
以后各项为前一项的平方根，求数列的前m项的和。
样例输入
81 4
2 2

样例输出
94.73
3.41

*/

func main() {
	a := 0.0
	b := 0
	for {
		_, err := fmt.Scanf("%f%d", &a, &b)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码区
			s := 0.0
			for ; b > 0; b-- {
				s += a
				a = math.Sqrt(a)
			}
			fmt.Printf("%.2f\n", s)
		}
	}
}
