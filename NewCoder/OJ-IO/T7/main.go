package main

import (
    "fmt"
    "os"
    "bufio"
    "strings"
    "strconv"
)

/*
计算一系列数的和
输入描述:
输入数据有多组, 每行表示一组输入数据。
每行不定有n个整数，空格隔开。(1 <= n <= 100)。
输出描述:
每组数据输出求和的结果
输入例子1:
1 2 3 
4 5 
0 0 0 0 0
输出例子1:
6 9 0
*/

func main() {
    input := bufio.NewScanner(os.Stdin)
    for input.Scan() {
        nums := strings.Split(input.Text(), " ")
        res := 0
        for i := 0; i < len(nums); i++ {
            num, _ := strconv.Atoi(nums[i])
            res += num
        }
        fmt.Println(res)
    }
}