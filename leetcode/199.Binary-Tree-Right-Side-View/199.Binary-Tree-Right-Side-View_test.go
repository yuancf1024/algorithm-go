package leetcode

import (
	"testing"
	"github.com/yuancf1024/algorithm-go/structures"
)

func TestRightSideView(t *testing.T) {
	arr := []int{1, 2, 3, structures.NULL, 5, structures.NULL, 4}
	root := structures.Ints2TreeNode(arr)
	output := rightSideView(root)
	t.Log(output)
}