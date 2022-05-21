package main

import (
	"fmt"
	"io"
)
/* 7-2 分糖豆
N 个宝宝分 M 颗 m&m 糖豆，如果每人分 K 个，够不够分呀？

输入格式：
输入在一行中给出 3 个正整数，分别是 N（不超过 100），是宝宝们的总人数；
M（不超过 1000），是糖豆的总颗数；
K（不超过 10），是要分给每个宝宝的糖豆数。

输出格式：
如果每人 K 个正好能够分完，输出 zheng hao mei ren K!；
如果分完了还剩 X 颗糖豆，则输出 hai sheng X!；
如果不够分的，还差 X 颗糖豆，则输出 hai cha X!。

输入样例 1：
10 50 5

输出样例 1：
zheng hao mei ren 5!

输入样例 2：
12 30 2

输出样例 2：
hai sheng 6!

输入样例 3：
15 40 3

输出样例 3：
hai cha 5!

*/

func main() {
	var n, m, k int
	for {
		_, err := fmt.Scanf("%d %d %d", &n, &m, &k)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			// 核心代码
			// fmt.Printf("%d %d %d", n, m, k)
			if n*k > m {
				fmt.Printf("hai cha %d!\n", n*k-m)
			} else if m - n*k > 0 {
				fmt.Printf("hai sheng %d!\n", m-n*k)
			} else if n*k - m == 0  {
				fmt.Printf("zheng hao mei ren %d!\n", m / 3)
			}
		}
	}
}
