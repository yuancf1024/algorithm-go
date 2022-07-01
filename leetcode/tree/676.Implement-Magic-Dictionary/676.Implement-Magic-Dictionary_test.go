package leetcode

import (
	"fmt"
	"testing"
)

func Test_Problem676(t *testing.T) {
	dict := []string{"hello", "leetcode"}
	obj := Constructor676()
	obj.BuildDict(dict)
	fmt.Printf("obj = %v\n", obj)
	fmt.Println(obj.Search("hello")) // 即使完全一样也会输出false，需要有一个字母不一样
	fmt.Println(obj.Search("apple"))
	fmt.Println(obj.Search("leetcode"))
	fmt.Println(obj.Search("leetcoded"))
	fmt.Println(obj.Search("hhllo"))
	fmt.Println(obj.Search("hell"))
}