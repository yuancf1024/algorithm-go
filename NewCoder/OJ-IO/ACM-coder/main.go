package main

import (
	"fmt"
	"io"
)

func main() {
	a := 0
	b := 0
	for {
		_, err := fmt.Scanf("%d%d", &a, &b)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			fmt.Printf("%d\n", a+b)
		}
	}
}
