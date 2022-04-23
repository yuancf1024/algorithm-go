package main

import "fmt"

/*
计算一系列数的和
数据范围：数据组数满足  ，每组数据中整数个数满足  ，每组数据中的值满足 
输入描述:
输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。
输出描述:
每组数据输出求和的结果
输入例子1:
4 1 2 3 4 
5 1 2 3 4 5 
0
输出例子1:
10 
15
*/

func main() {
    var n, num int
    for {
        fmt.Scan(&n)
        if n == 0 {
            break
        }
        sum := 0
        for n > 0 {
            fmt.Scan(&num)
            sum += num
            n--
        }
        fmt.Println(sum)
    }
}