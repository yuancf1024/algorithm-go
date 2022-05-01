package leetcode

/* 69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，
例如 pow(x, 0.5) 或者 x ** 0.5 。
*/

func mySqrt1(x int) int {
	left, right, res := 0, x, -1
	for left <= right {
		pivot := left + ((right - left) >> 1)
		if pivot * pivot <= x {
			res = pivot
			left = pivot + 1
		} else {
			right = pivot - 1
		}
	}
	return res
}

/* 

*/

// 解法一 二分, 找到最后一个满足 n^2 <= x 的整数n
func mySqrt2(x int) int {
	l, r := 0, x
	for l < r {
		mid := (l + r + 1) / 2
		if mid*mid > x {
			r = mid - 1
		} else {
			l = mid
		}
	}
	return l
}

// 解法二 牛顿迭代法 https://en.wikipedia.org/wiki/Integer_square_root
func mySqrt1(x int) int {
	r := x
	for r*r > x {
		r = (r + x/r) / 2
	}
	return r
}

// 解法三 Quake III 游戏引擎中有一种比 STL 的 sqrt 快 4 倍的实现 https://en.wikipedia.org/wiki/Fast_inverse_square_root
// float Q_rsqrt( float number )
// {
// 	long i;
// 	float x2, y;
// 	const float threehalfs = 1.5F;

// 	x2 = number * 0.5F;
// 	y  = number;
// 	i  = * ( long * ) &y;                       // evil floating point bit level hacking
// 	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
// 	y  = * ( float * ) &i;
// 	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
// //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
// 	return y;
// }