package leetcode

import (
	"testing"
	"github.com/yuancf1024/algorithm-go/structures"
)

func TestLevelOrderBottom(t *testing.T) {
	arr := []int{3, 9, 20, structures.NULL, structures.NULL, 15, 7}
	root := structures.Ints2TreeNode(arr)
	output := levelOrderBottom(root)
	t.Log(output)
}