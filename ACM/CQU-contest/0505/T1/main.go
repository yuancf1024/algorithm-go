package main

import (
	"fmt"
	"io"
	"strconv"
)

func main() {
	var a int
	for { // 循环获取输入
		if _, err := fmt.Scan(&a); err != io.EOF {
			// 核心代码
			var res bool
			res = isPalindrome(a)
			fmt.Println(res)
			// fmt.Println(a)
		} else {
			break
		}
	}
}

func isPalindrome(num int) bool {
	if num < 0 {
		// fmt.Println(false)
		return false
	}

	res := true

	str := strconv.Itoa(num)
	n := len(str)
	slow, fast := 0, n-1
	for slow < fast {
		if str[slow] == str[fast] {
			slow++
			fast--
		} else {
			res = false
			break
		}

	}
	// fmt.Println(res)
	return res
}
