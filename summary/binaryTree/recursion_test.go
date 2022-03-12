package binaryTree

import "testing"

func TestPreorderTraversal(t *testing.T) {
	
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	got := PreorderTraversal(root)
	want := []int{1, 2, 3}
	t.Log(got)

	for i := 0; i < len(arr); i++ {
		if got[i] != want[i] {
			t.Errorf("got %d want %d given: %v", got, want, arr)
			break
		}
	}
}


func TestPreorderTraversal1(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := PreorderTraversal1(root)
	t.Log(output)
}

func TestInorderTraversal(t *testing.T) {
	
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	got := InorderTraversal(root)
	want := []int{2, 1, 3}
	t.Log(got)

	for i := 0; i < len(arr); i++ {
		if got[i] != want[i] {
			t.Errorf("got %d want %d given: %v", got, want, arr)
			break
		}
	}
}

func TestInorderTraversal1(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := InorderTraversal1(root)
	t.Log(output)
}

func TestPostInorderTraversal(t *testing.T) {
	
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	got := PostorderTraversal(root)
	want := []int{2, 3, 1}
	t.Log(got)

	for i := 0; i < len(arr); i++ {
		if got[i] != want[i] {
			t.Errorf("got %d want %d given: %v", got, want, arr)
			break
		}
	}
}

func TestPostorderTraversal1(t *testing.T) {
	arr := []int{1, 2, 3}
	root := Ints2TreeNode(arr)
	output := PostorderTraversal1(root)
	t.Log(output)
}