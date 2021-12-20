package main

import "fmt"

// 普通递归
func Recursive(n int) int {
	if n == 0 {
		return 1
	}

	return n * Recursive(n-1)
}

// 尾递归
func RecursiveTail(n int, a int) int {
	if n == 1 {
		return a
	}

	return RecursiveTail(n-1, a*n)
}

func main() {
	fmt.Println(Recursive(5))
	fmt.Println(RecursiveTail(5, 1))
}

// 普通递归会反复进入一个函数，它的过程如下:
// Rescuvie(5)
// {5 * Rescuvie(4)}
// {5 * {4 * Rescuvie(3)}}
// {5 * {4 * {3 * Rescuvie(2)}}}
// {5 * {4 * {3 * {2 * Rescuvie(1)}}}}
// {5 * {4 * {3 * {2 * 1}}}}
// {5 * {4 * {3 * 2}}}
// {5 * {4 * 6}}
// {5 * 24}
// 120

// 尾递归的过程:
// RescuvieTail(5, 1)
// RescuvieTail(4, 1*5)=RescuvieTail(4, 5)
// RescuvieTail(3, 5*4)=RescuvieTail(3, 20)
// RescuvieTail(2, 20*3)=RescuvieTail(2, 60)
// RescuvieTail(1, 60*2)=RescuvieTail(1, 120)
// 120