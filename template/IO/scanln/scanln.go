package main

import "fmt"

func main() {

	var name string
	var age int

	/*
	   和fmt.Scan功能类似，fmt.Scanln也是一个阻塞的函数，如果它获取不到数据就会一直阻塞哟。

	   fmt.Scanln也可以接收多个参数，用户输入参数默认使用空格分割输入设备传入的参数，遇到回车换行符就结束接收参数
	*/
	fmt.Scanln(&name, &age)
	fmt.Println(name, age)

}
