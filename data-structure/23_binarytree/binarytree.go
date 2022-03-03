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

// 中序遍历的递归实现
func inOrderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	if root.Left == nil && root.Right == nil {
		return []int{root.Val}
	}

	res := inOrderTraversal(root.Left)
	res = append(res, root.Val)
	res = append(res, inOrderTraversal(root.Right)...)
	// inOrderTraversal(root.Right)的元素被打散一个个append进res

	return res
}

// 后序遍历的递归实现
func postOrderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	var res []int
	if root.Left != nil {
		lres := postOrderTraversal(root.Left)
		if len(lres) > 0 {
			res = append(res, lres...)
		}
	}

	if root.Right != nil {
		rres := postOrderTraversal(root.Right)
		if len(rres) > 0 {
			res = append(res, rres...)
		}
	}

	res = append(res, root.Val)
	return res
}