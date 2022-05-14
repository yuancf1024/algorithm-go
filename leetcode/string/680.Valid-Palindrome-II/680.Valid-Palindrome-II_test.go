package leetcode

import (
	"fmt"
	"testing"
)

func Test_Problem680(t *testing.T) {

	tcs := []struct {
		s   string
		ans bool
	}{

		{
			"aba",
			true,
		},

		{
			"abca",
			true,
		},

		{
			"abc",
			false,
		},
	}
	fmt.Printf("------------------------Leetcode Problem 125------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【input】:%v       【output】:%v\n", tc, validPalindrome(tc.s))
	}
	fmt.Printf("\n\n\n")
}