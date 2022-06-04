package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/* 113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，
找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

示例 1：

			5
		   / \
		  4   8
		 /   / \
		11  13  4
	   / \     / \
	  7   2   5   1

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

示例 2：

	1
   / \
  2   3

输入：root = [1,2,3], targetSum = 5
输出：[]

示例 3：

输入：root = [1,2], targetSum = 0
输出：[]

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//  参考halfrost 递归
func pathSum(root *TreeNode, targetSum int) [][]int {
	var slice [][]int
	slice = findPath(root, targetSum, slice, []int(nil))
	return slice
}

func findPath(n *TreeNode, sum int, slice [][]int, stack []int) [][]int {
	if n == nil {
		return slice
	}
	sum -= n.Val
	stack = append(stack, n.Val)
	if sum == 0 && n.Left == nil && n.Right == nil {
		slice = append(slice, append([]int{}, stack...))
		stack = stack[:len(stack)-1] // 栈顶pop
	}
	slice = findPath(n.Left, sum, slice, stack)
	slice = findPath(n.Right, sum, slice, stack)
	return slice
}

// 解法二 迭代
func pathSum1(root *TreeNode, targetSum int) [][]int {
	if root == nil {
		return [][]int{}
	}
	if root.Left == nil && root.Right == nil {
		return [][]int{{root.Val}}
	}

	path, res := []int{}, [][]int{}
	tmpLeft := pathSum(root.Left, targetSum-root.Val)
	path = append(path, root.Val)
	if len(tmpLeft) > 0 {
		for i := 0; i < len(tmpLeft); i++ {
			tmpLeft[i] = append(path, tmpLeft[i]...)
		}
		res = append(res, tmpLeft...)
	}
	path = []int{}
	tmpRight := pathSum(root.Right, targetSum-root.Val)
	path = append(path, root.Val)
	if len(tmpRight) > 0 {
		for i := 0; i < len(tmpRight); i++ {
			tmpRight[i] = append(path, tmpRight[i]...)
		}
		res = append(res, tmpRight...)
	}
	return res
}

/*
解题思路
这一题是第 257 题和第 112 题的组合增强版
*/