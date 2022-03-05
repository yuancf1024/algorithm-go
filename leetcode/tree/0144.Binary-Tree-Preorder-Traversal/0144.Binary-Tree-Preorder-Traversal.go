package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type TreeNode = structures.TreeNode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 2022-03-05自己写的, 遍历时如果没有对切片res取址会报错
func preorderTraversal(root *TreeNode) []int {
	var res []int
	traversal(root, &res)
	return res
}

func traversal(cur *TreeNode, output *[]int) {
	if cur == nil {
		return
	}

	*output = append(*output, cur.Val) // *output 解引用，从对应地址获取值
	traversal(cur.Left, output) // output 本身是一个指针
	traversal(cur.Right, output)
}

// 解法一 递归
// func preorderTraversal(root *TreeNode) []int {
// 	res := []int{}
// 	if root != nil {
// 		res = append(res, root.Val)
// 		tmp := preorderTraversal(root.Left)
// 		for _, t := range tmp {
// 			res = append(res, t)
// 		}
// 		tmp = preorderTraversal(root.Right)
// 		for _, t := range tmp {
// 			res = append(res, t)
// 		}
// 	}
// 	return res
// }

// 解法二 递归
func preorderTraversal1(root *TreeNode) []int {
	var result []int
	preorder(root, &result)
	return result
}

func preorder(root *TreeNode, output *[]int) {
	if root != nil {
		*output = append(*output, root.Val)
		preorder(root.Left, output)
		preorder(root.Right, output)
	}
}

// 解法三 非递归，用栈模拟递归过程
func preorderTraversal2(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	stack, res := []*TreeNode{}, []int{}
	stack = append(stack, root)
	for len(stack) != 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if node != nil {
			res = append(res, node.Val)
		}
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}
	return res
}