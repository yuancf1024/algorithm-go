package main

import (
	"fmt"
	"io"
)
/* 7-3 约会App
在 520 这个日子里，没有比开发一个约会 App 更合适做的事情了。
这个软件的需求很简单，用户输入自己的性别、想要约会的异性的年龄范围 
[a,b]、身高范围 [c,d]，你要帮用户筛选出系统中满足其约会条件的所有异性。
注意：性别、年龄、身高的要求必须全都符合要求才可以。

输入格式：
输入第一行首先给出一个用户自己输入的信息，格式如下：
性别 a b c d
其中 性别 为 0 表示女性，1 表示男性，是该用户自己的性别；
后面四个数字依次表示该用户想要约会的异性的年龄下限、年龄上限、身高下限、
身高上限 —— 注意这里的范围都是闭区间。

随后一行给出一个正整数 N≤100，随后 N 行，
每行给出一位系统中登记的约会对象的信息，格式如下：

性别 年龄 身高
这里保证年龄和身高（包括上、下限）均为不超过 200 的正整数，
同行数字间以 1 个空格分隔。

输出格式：
按照输入的顺序，输出每个满足用户约会条件的约会对象的信息，
输出格式与输入格式相同。题目保证至少有一个人可以被输出。

输入样例：
1 20 25 160 175
6
0 28 165
1 21 170
0 25 160
0 22 180
1 20 175
0 20 175
输出样例：
0 25 160
0 20 175

*/

func main() {
	var sex int
	var age_l, age_h, height_l, height_h int
	var n int 
	for {
		_, err := fmt.Scanf("%d %d %d %d %d", &sex, &age_l, &age_h, &height_l, &height_h)
		fmt.Scanf("%d", &n)
		Sex := make([]int, n)
		Age := make([]int, n)
		Height := make([]int, n)
		if err != nil {
			if err == io.EOF {
				break
			}
		} else {
			for i := 0; i < n; i++ {
				fmt.Scanf("%d %d %d", &Sex[i], &Age[i], &Height[i])
			}

			// // 打印
			// fmt.Printf("%d %d %d %d %d", sex, age_l, age_h, height_l, height_h)
			// for i := 0; i < n; i++ {
			// 	fmt.Printf("%d ", Sex[i])
			// }
			// for i := 0; i < n; i++ {
			// 	fmt.Printf("%d ", Age[i])
			// }
			// for i := 0; i < n; i++ {
			// 	fmt.Printf("%d ", Height[i])
			// }

			// 核心代码
			// fmt.Printf("%d %d %d", n, m, k)
			res := make([]int, 0)
			for i := 0; i < n; i++ {
				if Sex[i] != sex && (Age[i] >= age_l && Age[i] <= age_h) && (Height[i] >= height_l && Height[i] <= height_h) {
					res = append(res, i)
				}
			}

			for i := 0; i < len(res); i++ {
				fmt.Printf("%d %d %d\n", Sex[res[i]], Age[res[i]], Height[res[i]])
			}
		}
	}
}
