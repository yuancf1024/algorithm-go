package main

import (
    "fmt"
	// "io"
	"strconv"
)

/*
3
0123
1234
2345


12 123 234 345

4
0000
0101
1011
0111

10 11 101 111
*/

func main() {
    n := 0
	fmt.Scanf("%d", &n)
	str := make([]string, 0)
	for i := 0; i < n; i++ {
		x := ""
		fmt.Scan(&x)
		str = append(str, x)
		// ans = ans + x
	}
	// 核心代码
	nums := make([]int, 0)
	for i := 0; i < n; i++ {
		// fmt.Println(str[i][0:3])
		for k := 0; k <= len(str); k++ {
			// for j := 0; j < len(str[i])-2; j++ {
			// 	num, _ := strconv.Atoi(str[i][j:j+3])
			// 	nums = append(nums, num)
			// }
			for j := 0; j < len(str[i])- k; j++ {
				num, _ := strconv.Atoi(str[i][j:j+k+1])
				nums = append(nums, num)
			}
		}
		
	}
	// 去重
	res := make(map [int]int, 0)
	ans := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			continue
		}
		if _, err := res[nums[i]]; !err {
			ans = append(ans, nums[i])
			res[nums[i]] = nums[i]
		}
	}

	// 排序
	// output := make([]int, len(ans))
	for i := 0; i < len(ans); i++ {
		for j := i; j < len(ans); j++ {
			if ans[i] > ans[j] {
				ans[i], ans[j] = ans[j], ans[i]
			}
		}
		
	}
	for i := 0; i < len(ans); i++ {
		fmt.Printf("%d ", ans[i])
	}
	// fmt.Printf("%d", ans[len(ans)-1])
	fmt.Println()

	// 输出字符串，转字符串
	// out := make([]string, 0)
	// for i := 0; i < len(ans); i++ {
	// 	s := strconv.Itoa(ans[i])
	// 	// s := strconv.FormatInt(ans[i],10)
	// 	out = append(out, s)
	// }

	// for i := 0; i < len(ans); i++ {
	// 	// s := strconv.Itoa(ans[i])
	// 	// s := strconv.FormatInt(ans[i],10)
	// 	fmt.Printf("%s ", out[i])
	// }

	// for i := 0; i < len(ans)-1; i++ {
	// 	fmt.Printf("%s ", out[i])
	// }
	// fmt.Printf("%s", out[len(ans)-1])
	// for i := 0; i < len(ans); i++ {
	// 	fmt.Printf("%s ", out[i])
	// }
	// fmt.Printf("%s", out[len(ans)-1])
	// fmt.Println()
}
