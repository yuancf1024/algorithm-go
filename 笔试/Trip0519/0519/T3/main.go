package main

import (
	"fmt"
	"io"
)

/*
input:
yab

output:
3
*/

func main() {
	str := ""
	// b := 0
	for {
		_, err := fmt.Scanf("%s", &str)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			// for i := 0; i < len(str); i++ {
			// 	fmt.Printf("%c\n", str[i])
			// }
			res := 0
			res = minOperation(str)
			fmt.Println(res)
		}
	}
}


func minOperation(str string) int {
	return 1
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}