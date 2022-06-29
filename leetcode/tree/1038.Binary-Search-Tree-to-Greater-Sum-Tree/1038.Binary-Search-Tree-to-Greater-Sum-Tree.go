package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* 1038. 从二叉搜索树到更大和树
给定一个二叉搜索树 root (BST)，请将它的每个节点的值替换成树中大于或者
等于该节点值的所有节点值之和。

提醒一下， 二叉搜索树 满足下列约束条件：
- 节点的左子树仅包含键 小于 节点键的节点。
- 节点的右子树仅包含键 大于 节点键的节点。
- 左右子树也必须是二叉搜索树。

示例 2：

输入：root = [0,null,1]
输出：[1,null,1]
 

提示：
树中的节点数在 [1, 100] 范围内。
0 <= Node.val <= 100
树中的所有值均 不重复 。
 
*/

// 参考leetcode-538
func bstToGst(root *TreeNode) *TreeNode {
	if root == nil { // 边界条件判断
		return nil
	}
	sum := 0
	dfs1038(root, &sum)
	return root
}

func dfs1038(root *TreeNode, sum *int) {
	if root == nil{ // 边界条件判断
		return
	}
	/*按照右节点-根节点-左节点的顺序累加*/
	dfs1038(root.Right, sum)
	root.Val += *sum
	*sum = root.Val
	dfs1038(root.Left, sum)
}