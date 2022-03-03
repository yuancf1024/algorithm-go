package binarytree

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// 前序遍历的非递归实现
func preOrderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	if root.Left == nil && root.Right == nil {
		return []int{root.Val}
	}

	var stack []*TreeNode
	var res []int
	stack = append(stack, root)
	for len(stack) != 0 {
		e := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		res = append(res, e.Val)
		if e.Right != nil {
			stack = append(stack, e.Right)
		}
		if e.Left != nil {
			stack = append(stack, e.Left)
		}
	}
	return res
}

// func inOrderTraversal(root *TreeNode) []int {
	
// }

// func postOrderTraversal(root *TreeNode) []int {
	
// }