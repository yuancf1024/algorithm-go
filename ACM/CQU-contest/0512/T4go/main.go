package main

import (
	"fmt"
	"io"
	// "strconv"
)

func main() {
	var a int
	for { // 循环获取输入
		if _, err := fmt.Scan(&a); err != io.EOF {
			// 核心代码
			var res bool
			// res = isPalindrome(a)
			fmt.Println(res)
			// fmt.Println(a)
		} else {
			break
		}
	}
}
