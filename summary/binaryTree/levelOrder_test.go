package binaryTree

import (
	"testing"
	"github.com/yuancf1024/algorithm-go/structures"
)

func TestLevelOrder(t *testing.T) {
	arr := []int{3, 9, 20, structures.NULL, structures.NULL, 15, 7}
	root := structures.Ints2TreeNode(arr)
	output := LevelOrder(root)
	t.Log(output)
}

func TestLevelOrder1(t *testing.T) {
	arr := []int{3, 9, 20, structures.NULL, structures.NULL, 15, 7}
	root := structures.Ints2TreeNode(arr)
	output := LevelOrder1(root)
	t.Log(output)
}