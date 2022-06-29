package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/* 538. 把二叉搜索树转换为累加树
给出二叉 搜索 树的根节点，该树的节点值各不相同，
请你将其转换为累加树（Greater Sum Tree），
使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

- 节点的左子树仅包含键 小于 节点键的节点。
- 节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。

示例 2：

输入：root = [0,null,1]
输出：[1,null,1]
示例 3：

输入：root = [1,0,2]
输出：[3,3,2]
示例 4：

输入：root = [3,2,4,1]
输出：[7,9,4,10]

提示：
树中的节点数介于 0 和 10^4 之间。
每个节点的值介于 -10^4 和 10^4 之间。
树中的所有值 互不相同 。
给定的树为二叉搜索树。
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
// 参考halfrost 
func convertBST(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	sum := 0
	dfs538(root, &sum)
	return root
}

func dfs538(root *TreeNode, sum *int) {
	if root == nil {
		return
	}
	/*按照 右节点 - 根节点 - 左节点的顺序遍历，并累加*/
	dfs538(root.Right, sum)
	root.Val += *sum
	*sum = root.Val
	dfs538(root.Left, sum)
}

/*
解题思路
根据二叉搜索树的有序性，想要将其转换为累加树，只需按照 
右节点 - 根节点 - 左节点的顺序遍历，并累加和即可。
此题同第 1038 题。
*/