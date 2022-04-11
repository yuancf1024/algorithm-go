package leetcode

func reverseString(s []byte)  {
    n := len(s)
    if n == 1 {
        return 
    }

    slow, fast := 0, n-1
    for ; slow < n / 2; slow++ { // slow 不能等于 n/2
        s[slow], s[fast] = s[fast], s[slow]
        fast--
    }
    // return s
}


// 优雅的实现
func reverseString_v1(s []byte) {
	n := len(s)
	for i, j := 0, n - 1; i < j; {
		s[i], s[j] = s[j], s[i]
		i++
		j--
	}
}
/*
这一题的解题思路是用 2 个指针，指针对撞的思路，来不断交换首尾元素，即可。
*/