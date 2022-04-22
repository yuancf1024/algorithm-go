package leetcode

import "math"

/*509. 斐波那契数
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。
该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。
*/

// v1：递归
// func fib(n int) int {
// 	if n == 0 {
// 		return 0
// 	}
// 	if n == 1 {
// 		return 1
// 	}
// 	return fib(n-1)+ fib(n-2) // 两次递归，导致了时间复杂度以指数上升
// }

// v2: 递归
// func fib(n int) int {
// 	return dfs(n)
// }

// var m map[int]int = make(map[int]int)

// func dfs(n int) int {
// 	if n < 2 {
// 		return n
// 	}
// 	// 读取缓存
// 	if m[n] != 0 {
// 		return m[n]
// 	}
// 	ans := dfs(n-2) + dfs(n-1)
// 	m[n] = ans
// 	return ans
// }

/*509. 斐波那契数
这一题解法很多，大的分类是四种，递归，记忆化搜索(dp)，矩阵快速幂，
通项公式。其中记忆化搜索可以写 3 种方法，自底向上的，自顶向下的，
优化空间复杂度版的。通项公式方法实质是求 a^b 这个还可以用快速幂优化
时间复杂度到 O(log n) 。
*/

// 解法一 递归法 时间复杂度 O(2^n)，空间复杂度 O(n)
func fib(n int) int {
	if n <= 1 {
		return n
	}
	return fib(n-1) + fib(n-2)
}

// 解法二 自底向上的记忆化搜索 时间复杂度 O(n)，空间复杂度 O(n)
func fib1(n int) int {
	if n <= 1 {
		return n
	}
	cache := map[int]int{0: 0, 1: 1}
	for i := 2; i <= n; i++ {
		cache[i] = cache[i-1] + cache[i-2]
	}
	return cache[n]
}

// 解法三 自顶向下的记忆化搜索 时间复杂度 O(n)，空间复杂度 O(n)
func fib2(n int) int {
	if n <= 1 {
		return n
	}
	return memoize(n, map[int]int{0: 0, 1: 1})
}

func memoize(n int, cache map[int]int) int {
	if _, ok := cache[n]; ok {
		return cache[n]
	}
	cache[n] = memoize(n-1, cache) + memoize(n-2, cache)
	return memoize(n, cache)
}

// 解法四 优化版的 dp，节约内存空间 间复杂度 O(n)，空间复杂度 O(1)
func fib3(n int) int {
	if n <= 1 {
		return n
	}
	if n == 2 {
		return 1
	}
	current, prev1, prev2 := 0, 1, 1
	for i := 3; i <= n; i++ {
		current = prev1 + prev2
		prev2 = prev1
		prev1 = current
	}
	return current
}

// *****************分割线：进阶版的方法**************
// 解法五 矩阵快速幂 时间复杂度 O(log n)，空间复杂度 O(log n)
// | 1 1 | ^ n   = | F(n+1) F(n)   |
// | 1 0 |		   | F(n)	F(n-1) |
func fib4(N int) int {
	if N <= 1 {
		return N
	}
	var A = [2][2]int{
		{1, 1},
		{1, 0},
	}
	A = matrixPower(A, N-1)
	return A[0][0]
}

func matrixPower(A [2][2]int, N int) [2][2]int {
	if N <= 1 {
		return A
	}
	A = matrixPower(A, N/2)
	A = multiply(A, A)

	var B = [2][2]int{
		{1, 1},
		{1, 0},
	}
	if N%2 != 0 {
		A = multiply(A, B)
	}

	return A
}

func multiply(A [2][2]int, B [2][2]int) [2][2]int {
	x := A[0][0]*B[0][0] + A[0][1]*B[1][0]
	y := A[0][0]*B[0][1] + A[0][1]*B[1][1]
	z := A[1][0]*B[0][0] + A[1][1]*B[1][0]
	w := A[1][0]*B[0][1] + A[1][1]*B[1][1]
	A[0][0] = x
	A[0][1] = y
	A[1][0] = z
	A[1][1] = w
	return A
}

// 解法六 公式法 f(n)=(1/√5)*{[(1+√5)/2]^n -[(1-√5)/2]^n}，用 时间复杂度在 O(log n) 和 O(n) 之间，空间复杂度 O(1)
// 经过实际测试，会发现 pow() 系统函数比快速幂慢，说明 pow() 比 O(log n) 慢
// 斐波那契数列是一个自然数的数列，通项公式却是用无理数来表达的。而且当 n 趋向于无穷大时，前一项与后一项的比值越来越逼近黄金分割 0.618（或者说后一项与前一项的比值小数部分越来越逼近 0.618）。
// 斐波那契数列用计算机计算的时候可以直接用四舍五入函数 Round 来计算。
func fib5(N int) int {
	var goldenRatio float64 = float64((1 + math.Sqrt(5)) / 2)
	return int(math.Round(math.Pow(goldenRatio, float64(N)) / math.Sqrt(5)))
}

// 解法七 协程版，但是时间特别慢，不推荐，放在这里只是告诉大家，写 LeetCode 算法题的时候，启动 goroutine 特别慢
func fib6(N int) int {
    return <-fibb(N)
}

func fibb(n int) <- chan int {
    result := make(chan int)
    go func() {
        defer close(result)
        
        if n <= 1 {
            result <- n
            return
        }
        result <- <-fibb(n-1) + <-fibb(n-2)
    }()
    return result
}