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
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输出描述:
对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
输入例子1:
a,c,bb 
f,dddd 
nowcoder
输出例子1:
a,bb,c 
dddd,f 
nowcoder
*/

func main() {
    input := bufio.NewScanner(os.Stdin)
    for input.Scan() {
        str := strings.Split(input.Text(), ",") // 字符串分割
        sort.StringSlice.Sort(str) // 字符串排序，这里借助了sort.StringSlice方法来实现
        // fmt.Println(strings.Join(str, ",")) 
        res := ""
        for _, v := range str {
            res += "," + v
        }
        fmt.Println(res[1:])
    }
}