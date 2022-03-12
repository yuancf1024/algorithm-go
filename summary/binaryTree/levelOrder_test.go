package binaryTree

import "testing"

func TestLevelOrder(t *testing.T) {
	arr := []int{3, 9, 20, NULL, NULL, 15, 7}
	root := Ints2TreeNode(arr)
	output := LevelOrder(root)
	t.Log(output)
}