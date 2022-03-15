package binaryTree

import (
	"testing"
	"github.com/yuancf1024/algorithm-go/structures"
)

func TestPreorderTraversal2(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := PreorderTraversal2(root)
	t.Log(output)
}

func TestPostorderTraversal2(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := PostorderTraversal2(root)
	t.Log(output)
}

func TestInorderTraversal2(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := InorderTraversal2(root)
	t.Log(output)
}

// func TestInorderTraversal3(t *testing.T) {
// 	arr := []int{1, 2, 3}
// 	root := structures.Ints2TreeNode(arr)
// 	output := InorderTraversal3(root)
// 	t.Log(output)
// }

func TestPreorderTraversal_i(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := PreorderTraversal_i(root)
	t.Log(output)
}

func TestPostorderTraversal_i(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := PostorderTraversal_i(root)
	t.Log(output)
}

func TestInorderTraversal_i(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := InorderTraversal_i(root)
	t.Log(output)
}

func TestInorderTraversal_im(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := InorderTraversal_im(root)
	t.Log(output)
}

func TestPreorderTraversal_im(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := PreorderTraversal_im(root)
	t.Log(output)
}

func TestPostorderTraversal_im(t *testing.T) {
	arr := []int{1, 2, 3}
	root := structures.Ints2TreeNode(arr)
	output := PostorderTraversal_im(root)
	t.Log(output)
}