package main

import "fmt"

/*
计算一系列数的和
数据范围：数据组数满足  ，每组数据中的整数个数满足  ，每个数据大小满足 
输入描述:
输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
接下来t行, 每行一组数据。
每行的第一个整数为整数的个数n(1 <= n <= 100)。
接下来n个正整数, 即需要求和的每个正整数。
输出描述:
每组数据输出求和的结果
输入例子1:
2 
4 1 2 3 4 
5 1 2 3 4 5
输出例子1:
10 
15
*/

func main() {
    var t, n, num int
    fmt.Scan(&t)
    for ; t > 0; t-- {
        fmt.Scan(&n)
        res := 0
        for ; n > 0; n-- {
            fmt.Scan(&num)
            res += num
        }
        fmt.Println(res)
    }
}