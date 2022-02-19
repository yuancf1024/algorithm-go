package main

import (
	"fmt"
	"math"
)

// 参考何海涛的实现
func divide(a int, b int) int {
	if a == math.MinInt32 && b == -1 {
		return math.MaxInt32
	}
	var negative int = 2
	if a > 0 {
		negative--
		a = -a
	}
	if b > 0 {
		negative--
		b = -b
	}
	result := divideCore(a, b)
	if negative == 1 {
		return -result
	} else {
		return result
	}
}

func divideCore(dividend int, divisor int) int {
	var result int = 0
	for dividend <= divisor { // 注意前面已经对a、b都添加了负号
		var value int = divisor
		var quotient int = 1
		for (value >= math.MinInt32/2) && (dividend <= value+value) {
			quotient += quotient
			value += value
		}
		result += quotient
		dividend -= value
	}
	return result
}

// 实现2：时间复杂度O(n) 空间复杂度O(1)
func divide1(a int, b int) int {
	if a == math.MinInt32 && b == -1 {
		// 此时发生溢出
		// math.MinInt32 -> 2^31
		// math.MaxInt32 -> 2^31-1
		return math.MaxInt32
	}

	sign := 1
	if (a > 0 && b < 0) || (a < 0 && b > 0) {
		sign = -1
	}

	if a > 0 {
		a = -a
	}

	if b > 0 {
		b = -b
	}

	res := 0
	for a <= b {
		a -= b
		res++
	}
	return sign * res
}

// 实现3：时间复杂度O(logn * logn) 空间复杂度O(1)
func divide2(a int, b int) int {
	if a == math.MinInt32 && b == -1 {
		return math.MaxInt32
	}
	sign := 1
	if (a > 0 && b < 0) || (a < 0 && b > 0) {
		sign = -1
	}

	if a > 0 {
		a = -a
	}

	if b > 0 {
		b = -b
	}

	res := 0
	for a <= b {
		value, k := b, 1
		for (value >= math.MinInt32/2) && a <= value+value {
			value += value
			if k > math.MaxInt32/2 {
				return math.MinInt32
			}
			k += k
		}
		a -= value
		res += k
	}
	return sign * res
}

func main() {
	fmt.Println(divide(15, 2))
	fmt.Println(divide(7, -3))
	fmt.Println(divide(0, 1))
	fmt.Println(divide(1, 1))
}
