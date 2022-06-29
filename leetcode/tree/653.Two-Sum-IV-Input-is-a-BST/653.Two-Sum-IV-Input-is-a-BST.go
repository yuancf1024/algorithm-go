package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/* 653. 两数之和 IV - 输入 BST
给定一个二叉搜索树 root 和一个目标结果 k，
如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//  参考halfrost
func findTarget(root *TreeNode, k int) bool {
	m := make(map[int]int, 0)
	return findTargetDFS(root, k, m)
}

func findTargetDFS(root *TreeNode, k int, m map[int]int) bool {
	if root == nil {
		return false
	}
	if _, ok := m[k-root.Val]; ok {
		return ok
	}
	m[root.Val]++
	return findTargetDFS(root.Left, k, m) || findTargetDFS(root.Right, k, m)
}

/*
解题思路
在树中判断是否存在 2 个数的和是 sum。
这一题是 two sum 问题的变形题，只不过题目背景是在 BST 上处理的。
处理思路大体一致，用 map 记录已经访问过的节点值。
边遍历树边查看 map 里面是否有 sum 的另外一半。
*/