package leetcode

import (
	"math"

	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/* 124. 二叉树中的最大路径和
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，
达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

示例 1：

       1
      / \
     2   3

输入：root = [1,2,3]
输出：6

解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

示例 2：

   -10
   / \
  9  20
    /  \
   15   7

输入：root = [-10,9,20,null,null,15,7]
输出：42

解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42

提示：

树中节点数目范围是 [1, 3 * 10^4]
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//  参考halfrost 递归维护最大值
func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	max := math.MinInt32
	getPathSum(root, &max)
	return max
}

func getPathSum(root *TreeNode, maxSum *int) int {
	if root == nil {
		return math.MinInt32
	}
	left := getPathSum(root.Left, maxSum)
	right := getPathSum(root.Right, maxSum)

	currMax := max(max(left + root.Val, right + root.Val), root.Val)
	*maxSum = max(*maxSum, max(currMax, left + right + root.Val))
	return currMax
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
/*
解题思路
给出一个二叉树，要求找一条路径使得路径的和是最大的。
这一题思路比较简单，递归维护最大值即可。
不过需要比较的对象比较多。
maxPathSum(root) = max(maxPathSum(root.Left), maxPathSum(root.Right), maxPathSumFrom(root.Left) (if>0) 
+ maxPathSumFrom(root.Right) (if>0) + root.Val) ，
其中，maxPathSumFrom(root) = max(maxPathSumFrom(root.Left), maxPathSumFrom(root.Right)) + root.Val
*/