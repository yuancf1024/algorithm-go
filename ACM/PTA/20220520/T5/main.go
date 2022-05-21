package main

import (
	"fmt"
	"io"
	"strconv"
)
/* 7-5 我侬数
元初的中国书画大家赵孟頫的妻子管道升曾经写过一首脍炙人口的《我侬词》，
词中道：“把一块泥，捻一个你，塑一个我。将咱们两个一齐打破，用水调和。再捏一个你，再塑一个我。我泥中有你，你泥中有我。”
给定一对正整数 A 和 B，将它们的各位数字收集到一起，再重新分成两个数 A 和 B ′，我们称这样的 A′和 B′
互为基于 A 和 B 的“我侬数“。本题就请你判断任一对数字是否是基于给定 A 和 B 的“我侬数“。

输入格式：

输入首先在第一行中给出两个不超过 10^4位的正整数 A 和 B，
为“我侬数“的基础数。随后每行给出一对不超过 2×10^4位的正整数 A′和B′。
数字间以 1 个空格分隔。

输入以一对 0 结束，这一对 0 不要处理。
题目保证至少有一对需要判定的数字。

输出格式：
对每一对 A′和 B′，判断其是否是基于给定 A 和 B 的“我侬数“。
如果是，则在一行中输出 Yes，否则输出 No。

注意：所有数字均不考虑前导 0。例如 A=101，B=2021，
则我们不能判定 012 和 0121 为“我侬数“。

输入样例：
521212577999 21100008482136
521212577999 21100008482136
00210908482136 512121257799
123456789012597890 11100222
786238645254 19024781758903
21100008482136 521212577999
90 52121257792110008482136
0 0
输出样例：
Yes
No
Yes
No
Yes
No

*/

func main() {
	var A, B int
	for {
		_, err := fmt.Scanf("%d %d", &A, &B)
		a := make([]int, 0)
		b := make([]int, 0)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			for {
				var x, y int
				fmt.Scanf("%d %d", &x, &y)
				if x == 0 && y == 0 {
					break
				} else {
					a = append(a, int(x))
					b = append(b, int(y))
				}
			}

			// fmt.Printf("%d %d\n", A, B)
			// 核心代码
			hashmap := make(map[byte]int,0)
			stra := strconv.Itoa(A)
			strb := strconv.Itoa(B)
			for i := 0; i < len(stra); i++ {
				hashmap[stra[i] - '0']++
			}
			for i := 0; i < len(strb); i++ {
				hashmap[stra[i] - '0']++
			}

			for i := 0; i < len(a); i++ {

				tmpa := strconv.Itoa(a[i])
				tmpb := strconv.Itoa(b[i])
				if tmpa[0] == '0'  || tmpb[0] == '0' {
					fmt.Println("No")
					continue
				}
				tmpMap := hashmap
				for j := 0; j < len(tmpa); j++ {
					tmpMap[tmpa[j]-'0']--
				}
				for j := 0; j < len(tmpb); j++ {
					tmpMap[tmpb[j]-'0']--
				}
				for _, v := range tmpMap {
					if v == 0 {
						fmt.Println("Yes")
					}
				}
			}
		}
	}
}
