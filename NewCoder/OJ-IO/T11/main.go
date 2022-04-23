// 方法1：使用bufio包

// package main

// import (
//     "fmt"
//     "os"
//     "bufio"
//     "strings"
//     "strconv"
// )

/*
数据范围： 
输入描述:
输入有多组测试用例，每组空格隔开两个整数
输出描述:
对于每组数据输出一行两个整数的和
输入例子1:
1 1
输出例子1:
2
*/

// func main() {
//     input := bufio.NewScanner(os.Stdin)
//     for input.Scan() {
//         nums := strings.Split(input.Text(), " ")
//         res := 0
//         for i := 0; i < len(nums); i++ {
//             num, _ := strconv.Atoi(nums[i])
//             res += num
//         }
//         fmt.Println(res)
//     }
// }


// 方法2：使用Scan
package main

import (
    "fmt"
    "io"
)

func main() {
    var a, b int
    for { // 循环输入
        if _, err := fmt.Scan(&a, &b); err != io.EOF {
            // 逻辑代码
            fmt.Println(a + b)
        } else {
            break
        }
    }
}