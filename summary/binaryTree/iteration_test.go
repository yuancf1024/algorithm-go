package binaryTree

import "testing"

func TestPreorderTraversal_i(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := PreorderTraversal_i(root)
	t.Log(output)
}

func TestPostorderTraversal_i(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := PostorderTraversal_i(root)
	t.Log(output)
}

func TestInorderTraversal_i(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := InorderTraversal_i(root)
	t.Log(output)
}

func TestInorderTraversal_im(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := InorderTraversal_im(root)
	t.Log(output)
}

func TestPreorderTraversal_im(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := PreorderTraversal_im(root)
	t.Log(output)
}

func TestPostorderTraversal_im(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := PostorderTraversal_im(root)
	t.Log(output)
}