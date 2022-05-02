package main

/* 1. 竖着读

只需竖着把字符放进去，转数字去掉前导零排序即可

case

3
0123
1234
2345


12 123 234 345

4
0000
0101
1011
0111

10 11 101 111
*/

import (
	// "sort"
	"fmt"
)

func main() {
	n, len := 0, 0
	fmt.Scan(&n)
	str := make([]string, n)
	for i := 0; i < n; i++ {
		s := ""
		fmt.Scan(&s)
		for j := 0; j < len(s); j++ { // go 语言中怎么动态增加字符串？
			str[j] += s[j]
			fmt.Println(str[j])
		}
	}
	
}