package leetcode

import (
	"fmt"
	"testing"
)

type question88 struct {
	para88
	ans88
}

// para 是参数
// one 代表第一个参数
type para88 struct {
	one []int
	m   int
	two []int
	n   int
}

// ans 是答案
// one 代表第一个答案
type ans88 struct {
	one []int
}

func Test_Problem88(t *testing.T) {

	qs := []question88{

		{
			para88{[]int{0}, 0, []int{1}, 1},
			ans88{[]int{1}},
		},

		{
			para88{[]int{1, 2, 3, 0, 0, 0}, 3, []int{2, 5, 6}, 3},
			ans88{[]int{1, 2, 2, 3, 5, 6}},
		},
	}
	fmt.Printf("------------------------Leetcode Problem 88------------------------\n")
	
	// merge 函数
	for _, q := range qs {
		_, p := q.ans88, q.para88
		fmt.Printf("【intput】:%v,%v,%v,%v       ", p.one, p.m, p.two, p.n)
		merge(p.one, p.m, p.two, p.n)
		fmt.Printf("【output】:%v\n", p)
	}
	fmt.Printf("\n\n\n")
	
	// merge1 函数
	for _, q := range qs {
		_, p := q.ans88, q.para88
		fmt.Printf("【intput】:%v,%v,%v,%v       ", p.one, p.m, p.two, p.n)
		merge1(p.one, p.m, p.two, p.n)
		fmt.Printf("【output】:%v\n", p)
	}
	fmt.Printf("\n\n\n")

	// merge2 函数
	for _, q := range qs {
		_, p := q.ans88, q.para88
		fmt.Printf("【intput】:%v,%v,%v,%v       ", p.one, p.m, p.two, p.n)
		merge2(p.one, p.m, p.two, p.n)
		fmt.Printf("【output】:%v\n", p)
	}
	fmt.Printf("\n\n\n")
}