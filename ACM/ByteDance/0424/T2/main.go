package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	// "strings"
	// "sort"
)

/* 字符串匹配问题，感觉稍微有点难啊
输入描述：
20522518135
输出描述：
205.225.18.135
205.225.181.35
*/

func main() {
	input := bufio.NewScanner(os.Stdin)
	// input.Scan() // 去掉第一行
	input.Scan() // 获取第二行
	str := input.Text()
	fmt.Println(str)

	// 核心逻辑
	n := len(str)
	nums := make([]int, n)

	for i := 0; i < n; i++ {
		nums[i] = int(str[i]) - 48
	}

	// 构造IP地址

	s := make([]string, 0)

	for i := 0; i < n-2; {
		if nums[i] != 0 && (nums[i]*100+nums[i+1]*10+nums[i+2] <= 255) {
			tmp := nums[i]*100 + nums[i+1]*10 + nums[i+2]
			tmpStr := strconv.Itoa(tmp)
			s = append(s, tmpStr)
			i += 3
		} else if nums[i] != 0 && (nums[i]*10+nums[i+1] <= 255) {
			tmp := nums[i]*100 + nums[i+1]*10 + nums[i+2]
			tmpStr := strconv.Itoa(tmp)
			s = append(s, tmpStr)
			i += 2
		}

	}

	res := ""
	for _, v := range s {
		res += "." + v
	}
	fmt.Println(res[1:])

	// for i := 0; i < len(str); i++ {
	// 	fmt.Println(nums[i])
	// }

	// sort.StringSlice.Sort(str)
	// fmt.Println(strings.Join(str, " ")) // 通过Join来连接，也可以手动连接
	// 手动连接代码形式
	// res := ""
	// for _, v := range str {
	//     res += " " + v
	// }
	// fmt.Println(res[1:]) // 去掉前导空格
}
