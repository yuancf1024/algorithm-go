package leetcode

import (
	"fmt"
	"testing"
)

// 参考大神halfrost
// https://github.com/halfrost/LeetCode-Go/blob/master/leetcode/0001.Two-Sum/1.%20Two%20Sum_test.go

type question1 struct {
	para1
	ans1
}

// para 是参数
// one 代表第一个参数
type para1 struct {
	nums []int
	target int
}

// ans 是答案
// one 代表第一个答案
type ans1 struct {
	one []int
}

func Test_Problem1(t *testing.T) {
	qs := []question1{
		{
			para1{[]int{3, 2, 4}, 6},
			ans1{[]int{1, 2}},
		},
		
		{
			para1{[]int{3, 2, 4}, 5},
			ans1{[]int{0, 1}},
		},

		{
			para1{[]int{0, 8, 7, 3, 3, 4, 2}, 11},
			ans1{[]int{1, 3}},
		},

		{
			para1{[]int{0, 1}, 1},
			ans1{[]int{0, 1}},
		},

		{
			para1{[]int{0, 3}, 5},
			ans1{[]int{}},
		},
		// 如需多个测试，可以复制上方元素。
	}

	fmt.Printf("------------------------Leetcode Problem 1------------------------\n")

	for _, q := range qs {
		_, p := q.ans1, q.para1
		fmt.Printf("【input】:%v       【output】:%v\n", p, twoSum(p.nums, p.target))
	}
	fmt.Printf("\n\n\n")
}