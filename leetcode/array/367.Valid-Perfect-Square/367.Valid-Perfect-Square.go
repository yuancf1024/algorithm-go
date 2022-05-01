package leetcode

/* 367. 有效的完全平方数
给定一个 正整数 num ，编写一个函数，
如果 num 是一个完全平方数，则返回 true ，
否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。
*/

func isPerfectSquare(num int) bool {
	left, right, res := 0, num, false
	for left <= right {
		mid := left + ((right - left) >> 1)
		if mid * mid > num {
			right = mid - 1
		} else if mid * mid < num {
			left = mid + 1
		} else {
			res = true
			break
		}
	}
	return res
}