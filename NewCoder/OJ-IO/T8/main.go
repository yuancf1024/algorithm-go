package main

import (
    "fmt"
    "os"
    "bufio"
    "strings"
    "sort"
)

/*
对输入的字符串进行排序后输出
输入描述:
输入有两行，第一行n
第二行是n个字符串，字符串之间用空格隔开
输出描述:
输出一行排序后的字符串，空格隔开，无结尾空格
输入例子1:
5 
c d a bb e
输出例子1:
a bb c d e
*/

func main() {
    input := bufio.NewScanner(os.Stdin)
    input.Scan() // 去掉第一行
    input.Scan() // 获取第二行
    str := strings.Split(input.Text(), " ") // 字符串分割
    sort.StringSlice.Sort(str) // 字符串排序，这里借助了sort.StringSlice方法来实现
    // fmt.Println(strings.Join(str, " ")) // 通过Join来连接，也可以手动连接
    // 手动连接代码形式
    res := ""
    for _, v := range str {
        res += " " + v
    }
    fmt.Println(res[1:]) // 去掉前导空格
}