package main

import "fmt"

func main() {

	name := "yuancf1024"
	age := 24

	fmt.Println("=======Println==========")

	/*
	   Println 将变量的值取出来打印并换行,变量之间默认添加空格
	*/
	fmt.Println(name, age)

	fmt.Println("========Print==========")

	/*
	   Print 将变量的值取出来打印但不换行，变量之间默认直接连接


	*/
	fmt.Print(name, age)

	fmt.Println("=================")

	fmt.Println("========Printf=========")

	/*
	   常用的占位符:
	       %s: 表示一个字符串类型
	       %d: 表示一个整形类型
	       %T: 表示一个变量对应的数据类型
	       %f: 表示一个浮点数类型
	       %t: 表示一个布尔类型
	       %c: 表示一个字符类型
	       %p: 表示一个指针类型
	       \t: 表示一个制表符
	       \n: 表示换行符

	   可以使用占位符格式化打印结果，如下所示。
	*/
	fmt.Printf("姓名：%s 年龄：%d\n", name, age)
}
