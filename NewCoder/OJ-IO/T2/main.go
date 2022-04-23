package main

import "fmt"

/*
计算a+b
数据范围：数据组数满足  ，数据大小满足 
输入描述:
输入第一行包括一个数据组数t(1 <= t <= 100)
接下来每行包括两个正整数a,b(1 <= a, b <= 1000)
输出描述:
输出a+b的结果
输入例子1:
2 
1 5 
10 20
输出例子1:
6 
30
*/

func main() {
    var t, a, b int
    fmt.Scan(&t)
    for t > 0 {
        fmt.Scan(&a, &b)
        fmt.Println(a + b)
        t--
    }
}