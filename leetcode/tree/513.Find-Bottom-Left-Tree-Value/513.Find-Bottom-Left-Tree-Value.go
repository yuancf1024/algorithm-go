package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/* 513. 找树左下角的值
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

Example 1:

Input:

    2
   / \
  1   3

Output:
1
Example 2:

Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// BFS
func findBottomLeftValue(root *TreeNode) int {
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		next := []*TreeNode{}
		for _, node := range queue {
			if node.Left != nil {
				next = append(next, node.Left)
			}
			if node.Right != nil {
				next = append(next, node.Right)
			}
		}
		if len(next) == 0 {
			return queue[0].Val
		}
		queue = next
	}
	return 0
}

// DFS
func findBottomLeftValue1(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res, maxHeight := 0, -1
	findBottomLeftValueDFS(root, 0, &res, &maxHeight)
	return res
}

func findBottomLeftValueDFS(root *TreeNode, curHeight int, res, maxHeight *int) {
	if curHeight > *maxHeight && root.Left == nil && root.Right == nil {
		*maxHeight = curHeight
		*res = root.Val
	}
	if root.Left != nil {
		findBottomLeftValueDFS(root.Left, curHeight+1, res, maxHeight)
	}
	if root.Right != nil {
		findBottomLeftValueDFS(root.Right, curHeight+1, res, maxHeight)
	}
}

/* 解题思路
给出一棵树，输出这棵树最下一层中最左边的节点的值。
这一题用 DFS 和 BFS 均可解题。
*/


