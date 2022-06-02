package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/* 814. 二叉树剪枝
给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。

返回移除了所有不包含 1 的子树的原二叉树。

节点 node 的子树为 node 本身加上所有 node 的后代。

示例 1：

	1
   / \
      0
     / \
	0   1

=>   1
      \
	   0
	    \
		 1


输入：root = [1,null,0,0,1]
输出：[1,null,0,null,1]
解释：
只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。

提示：

树中节点的数目在范围 [1, 200] 内
Node.val 为 0 或 1
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func pruneTree(root *TreeNode) *TreeNode {
	if !containsOne(root) {
		return nil
	} else {
		return root
	}
}

func containsOne(node *TreeNode) bool {
	if node == nil {
		return false
	}
	a1 := containsOne(node.Left)
	a2 := containsOne(node.Right)
	if !a1 { // node的左子树不包含1
		node.Left = nil
	}
	if !a2 { // node的右子树不包含1
		node.Right = nil
	}
	return node.Val == 1 || a1 || a2
}

/*
递归：
我们可以使用递归来解决这个问题。我们用 containsOne(node) 函数来
判断以 node 为根的子树中是否包含 1，
- 其不包含 1 当且仅当以 node 的左右孩子为根的子树均不包含 1，
**并且 node 节点本身的值也不为 1**。

如果 node 的左右孩子为根的子树不包含 1，那我们就需要把对应的指针置为空。
例如当 node 的左孩子为根的子树不包含 1 时，我们将 node.left 置为 null。

在递归结束之后，如果整颗二叉树都不包含 1，那么我们返回 null，否则我们返回原来的根节点。
*/