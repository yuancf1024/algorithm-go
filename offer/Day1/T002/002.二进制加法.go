package main

import (
	"fmt"
	"strconv"
)

// 方法一：模拟
// 借鉴「列竖式」的方法，末尾对齐，逐位相加。
func addBinary(a string, b string) string {
	ans := ""
	carry := 0
	lenA, lenB := len(a), len(b)
	n := max(lenA, lenB)

	for i := 0; i < n; i++ {
		if i < lenA {
			carry += int(a[lenA-i-1] - '0')
		}
		if i < lenB {
			carry += int(b[lenB-i-1] - '0')
		}
		ans = strconv.Itoa(carry%2) + ans
		carry /= 2
	}
	if carry > 0 {
		ans = "1" + ans
	}
	return ans
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}


func main() {
	fmt.Println(addBinary("11", "10")) // "101"
	fmt.Println(addBinary("1010", "1011")) // "10101"
}