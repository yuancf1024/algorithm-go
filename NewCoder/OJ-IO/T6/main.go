// 方法1：fmt.Scan
// /*
package main

import (
    "fmt"
    "io"
)

/*
计算一系列数的和
数据范围：  ， 所有数都满足 
输入描述:
输入数据有多组, 每行表示一组输入数据。
每行的第一个整数为整数的个数n(1 <= n <= 100)。
接下来n个正整数, 即需要求和的每个正整数。
输出描述:
每组数据输出求和的结果
输入例子1:
4 1 2 3 4 
5 1 2 3 4 5
输出例子1:
10 
15
*/

func main() {
    var n, num int
    for {
        if _, err := fmt.Scan(&n); err != io.EOF {
            res := 0
            for ; n > 0; n-- {
                fmt.Scan(&num)
                res += num
            }
            fmt.Println(res)
        } else {
            break
        }
    }
}
// */

// // 方法2：使用bufio
// package main

// import (
//     "fmt"
//     "os"
//     "bufio"
//     "strings"
//     "strconv"
// )

// func main() {
//     input := bufio.NewScanner(os.Stdin)
//     for input.Scan() {
//         nums := strings.Split(input.Text(), " ")
//         res := 0
//         for i := 1; i < len(nums); i++ {
//             num, _ := strconv.Atoi(nums[i])
//             res += num
//         }
//         fmt.Println(res)
//     }
// }