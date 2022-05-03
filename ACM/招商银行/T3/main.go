package main

/*
训练营圆满结束，同学们站在一起合影。
已知第i个同学喜欢的颜色是ai
​（注：可能有多个同学喜欢同一种颜色）。
合影的照片用一个数组表示，bi代表照片第i段的颜色。
对于一个照片的区间而言，只要这个区间存在某同学喜欢的颜色，
这个同学就会喜欢这个区间。
现在有q次询问，每次询问一个区间[l,r]
有多少个同学喜欢。

4 5
2 6 3 6 // 同学喜欢的颜色
1 6 3 6 6 // 合影照片每一段的颜色。
3
1 1
2 3
4 5
*/


import "fmt"

func main() {
    n, m := 0, 0
	q := 0
	// ans := 0

	fmt.Scan(&n, &m)
	// fmt.Scan(&m)

	color := make([]int, n)
	for i := 0; i < n; i++ {
		x := 0
		fmt.Scan(&x)
		color[i] = x
	}

	pic := make([]int, m)
	for i := 0; i < m; i++ {
		y := 0
		fmt.Scan(&y)
		pic[i] = y
	}

	fmt.Scan(&q)
	nums := make([][]int, q)
	for i := 0; i < q; i++ {
		// nums[i] = make([]int, m)
		// fmt.Scan(&m)
		nums[i] = make([]int, 2)
		for j := 0; j < 2; j++ {
			x := 0
			fmt.Scan(&x)
			nums[i][j] = x
			// ans = ans + x
		}
	}
	// 核心代码
	// fmt.Println(color)
	// fmt.Println(pic)
	colorMap := make(map[int]int)
	for i := 0; i < n; i++ {
		colorMap[color[i]]++
	}
	for i := 0; i < q; i++ {
		Query(nums[i], pic, color, colorMap)
	}

}

func Query(nums []int, pic, color []int, colorMap map[int]int) {
	// res := 0
	// return res
	// 核心代码

	ans := 0
	// fmt.Println(nums[i])
	// Query(nums[i])
	// 逻辑处理代码
	a1 := nums[0]
	a2 := nums[1]
	// 制作一个哈希表
	query := make(map[int]bool)
	for i := a1-1; i < a2; i++ {
		query[pic[i]] = true
	}

	for k, _ := range query {
		ans += colorMap[k]
	}

	// for i := 0 ; i < n; i++ {
	// 	if query[color[i]] {
	// 		ans++
	// 	}
	// }
	
	fmt.Println(ans)
	// fmt.Println(res)
}

