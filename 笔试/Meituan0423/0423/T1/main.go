package main

import (
    "fmt"
    "os"
    "bufio"
    // "strings"
    // "sort"
)

func main() {
	var n int
	fmt.Scan(&n)
    input := bufio.NewScanner(os.Stdin)
    input.Scan() // 获取第二行
    str := input.Text() 
	s := make([]byte, len(str))
	for i := 0; i < len(str); i++ {
		s[i] = str[i]
	}
	// fmt.Println()
    // 核心代码逻辑区
	swap := 0
	for i := 1; i < len(str)-1; i++ {
		if s[i] == s[i-1] && str[i] == s[i+1] {
			// fmt.Println(-1)
			swap = -1
			break
		} else if s[i] == s[i-1] && s[i] != s[i+1] {
			s[i], s[i+1] = s[i+1], s[i]
			swap++
		}
	}
	fmt.Println(swap)
	// for _, s := range str {
	// 	fmt.Println(s)
	// }
	// for i := 0; i < len(s); i++ {
	// 	fmt.Println(s[i])
	// }
}