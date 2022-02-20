package main

import "fmt"

// 方法1：简单计算每个整数的二进制形式中1的个数
// 时间复杂度：O(nk)
func countBits(n int) []int {
	// var result[n+1] int
	result := make([]int, n+1)
	for i := 0; i <= n; i++ {
		j := i
		for j != 0 {
			result[i]++
			j = j & (j - 1) // 位与运算后，j的二进制形式最右边的1变成了0
		}
	}
	return result
}

// 方法2：根据“i&（i-1）”计算i的二进制形式中1的个数
// 时间复杂度：O(n)
// “i&（i-1）”将i的二进制形式中最右边的1变成0，也就是说，
// 整数i的二进制形式中1的个数比“i&（i-1）”的二进制形式中1的个数多1
func countBits1(n int) []int {
	result := make([]int, n+1)
	for i := 1; i <= n; i++ {
		result[i] = result[i&(i-1)] + 1
	}
	return result
}

// 方法3：根据“i/2”计算i的二进制形式中1的个数
// 时间复杂度：O(n)
// i>>1”计算“i/2”，用“i&1”计算“i%2”
func countBits2(n int) []int {
	result := make([]int, n+1)
	for i := 1; i <= n; i++ {
		result[i] = result[i >> 1] + (i & 1);
	}
	return result
}

func main() {
	fmt.Println(countBits2(2)) // Output: [0,1,1]
	fmt.Println(countBits2(5)) // Output: [0,1,1,2,1,2]
}

// 方法2和方法3过于巧妙。😂