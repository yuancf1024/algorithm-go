package Recursion

// 迭代实现阶乘
type Fac struct {
	val map[int]int
}

// 新建阶乘，返回一个指针指向ta
func NewFactorial(n int) *Fac {
	return &Fac{
		make(map[int]int, n), // n代表map长度
	}
}

// 计算阶乘
func (fac *Fac) Factorial(n int) int {
	if fac.val[n] != 0 {
		return fac.val[n]
	}

	if n <= 1 {
		fac.val[n] = 1
		return 1
	} else {
		res := n * fac.Factorial(n-1)
		fac.val[n] = res
		return res
	}
}

// 打印阶乘的值
func (fac *Fac) Print(n int) {
	println(fac.val[n])
}