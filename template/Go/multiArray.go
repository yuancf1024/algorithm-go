package main

import (
	"fmt"
	"runtime"
	"strconv"
)

func main() {
	// 方法1
	row, column := 3, 4
	var answer [][]int
	for i := 0; i < row; i++ {
		inline := make([]int, column)
		answer = append(answer, inline)
	}
	fmt.Println(answer)

	// 方法2
	answer1 := make([][]int, row)
	for i := range answer1 {
		answer1[i] = make([]int, column)
	}
	fmt.Println(answer1)

	fmt.Println(runtime.GOARCH)  //CPU型号
	fmt.Println(strconv.IntSize) //int位数

}
