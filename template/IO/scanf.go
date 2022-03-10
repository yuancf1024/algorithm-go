package main

import "fmt"

func main() {

	var name string
	var age int

	/*
	   和fmt.Scanln功能类似，fmt.Scanf也是一个阻塞的函数，如果它获取不到数据就会一直阻塞哟。

	   其实fmt.Scanln和fmt.Scanf可都以接收多个参数，用户输入参数默认使用空格分割输入设备传入的参数，遇到回车换行符就结束接收参数

	   唯一区别就是可以格式化用户输入的数据类型,如下所示:
	       %s:
	           表示接收的参数会被转换成一个字符串类型，赋值给变量
	       %d:
	           表示接收的参数会被转换成一个整形类型，赋值给变量

	   生产环境中使用fmt.Scanln和fmt.Scanf的情况相对较少，一般使用fmt.Scan的情况较多~
	*/
	fmt.Scanf("%s%d", &name, &age)
	fmt.Println(name, age)

}
