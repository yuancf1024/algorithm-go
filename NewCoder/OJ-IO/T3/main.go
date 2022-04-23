package main

import "fmt"

/*
计算a+b
数据范围：数据组数满足  ， 数据大小满足 
输入描述:
输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 如果输入为0 0则结束输入
输出描述:
输出a+b的结果
输入例子1:
1 5 
10 20 
0 0
输出例子1:
6 30
*/

func main() {
    var a, b int
    for {
        fmt.Scan(&a, &b)
        if a == 0 && b == 0 {
            break
        }
        fmt.Println(a + b)
    }
}