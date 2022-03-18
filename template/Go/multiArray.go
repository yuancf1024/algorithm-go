package main

import (
	"fmt"
	"runtime"
	"strconv"
)

func main() {
	// 方法1
	r, c := 3, 4
	var a [][]int
	for i := 0; i < r; i++ {
		inline := make([]int, c)
		a = append(a, inline)
	}
	fmt.Println(a)

	// 方法2
	a1 := make([][]int, r) // 二维切片，r行
	for i := range a1 {
		a1[i] = make([]int, c) // 每一行c列
	}
	fmt.Println(a1)

	fmt.Println(runtime.GOARCH)  //CPU型号
	fmt.Println(strconv.IntSize) //int位数


}
