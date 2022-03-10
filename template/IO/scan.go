package main

import "fmt"

func main() {

	var name string
	var age int

	/*
	   使用"&"获取score变量的内存地址(即取变量内存地址的运算符)，通过键盘输入为score变量指向的内存地址赋初值。

	   fmt.Scan是一个阻塞的函数，如果它获取不到数据就会一直阻塞哟。

	   fmt.Scan可以接收多个参数，用户输入参数默认使用空格或者回车换行符分割输入设备传入的参数，直到接收所有的参数为止
	*/
	fmt.Scan(&name, &age)

	fmt.Println(name, age)

}
