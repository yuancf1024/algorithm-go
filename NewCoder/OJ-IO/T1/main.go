package main // 包名

import ( // 调用的包
    "fmt"
    "io"
)

/*
数据范围： 数据组数  , 数据大小满足 

输入描述:
输入包括两个正整数a,b(1 <= a, b <= 1000),输入数据包括多组。
输出描述:
输出a+b的结果
输入例子1:
1 5 
10 20
输出例子1:
6 
30
*/

func main(){
    var a, b int
    for { // 循环获取输入
        if _, err := fmt.Scan(&a, &b); err != io.EOF {
            fmt.Println(a + b)
        } else {
            break
        }
    }
}