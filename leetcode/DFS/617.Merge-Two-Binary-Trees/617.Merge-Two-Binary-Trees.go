package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* 617. 合并二叉树
给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠
（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。
合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后
节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。
*/

type TreeNode = structures.TreeNode

// DFS 实现 简洁易懂
func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil {
		return root2
	}
	if root2 == nil {
		return root1
	}

	root1.Val += root2.Val
	root1.Left = mergeTrees(root1.Left, root2.Left)
	root1.Right = mergeTrees(root1.Right, root2.Right)
	return root1
}

/*
解题思路
简单题。采用深搜的思路，分别从根节点开始同时遍历两个二叉树，
并将对应的节点进行合并。两个二叉树的对应节点可能存在以下三种情况：
- 如果两个二叉树的对应节点都为空，则合并后的二叉树的对应节点也为空；
- 如果两个二叉树的对应节点只有一个为空，则合并后的二叉树的对应节点为其中的非空节点；
- 如果两个二叉树的对应节点都不为空，则合并后的二叉树的对应节点的值
为两个二叉树的对应节点的值之和，此时需要显性合并两个节点。

对一个节点进行合并之后，还要对该节点的左右子树分别进行合并。
用递归实现即可。

复杂度分析

时间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点个数。
对两个二叉树同时进行深度优先搜索，只有当两个二叉树中的对应节点
都不为空时才会对该节点进行显性合并操作，因此被访问到的节点数
不会超过较小的二叉树的节点数。

空间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点个数。
空间复杂度取决于递归调用的层数，递归调用的层数不会超过较小的二叉树
的最大高度，最坏情况下，二叉树的高度等于节点数。
*/

// BFS 好像有点难顶😂
func mergeTrees_v2(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil {
		return root2
	}
	if root2 == nil {
		return root1
	}

	merged := &TreeNode{Val: root1.Val + root2.Val}
	queue := []*TreeNode{merged}
	queue1 := []*TreeNode{root1}
	queue2 := []*TreeNode{root2}

	for len(queue1) > 0 && len(queue2) > 0 {
		node := queue[0]
		queue = queue[1:]
		node1 := queue1[0]
		queue1 = queue1[1:]
		node2 := queue2[0]
		queue2 = queue2[1:]
		left1, right1 := node1.Left, node1.Right
		left2, right2 := node2.Left, node2.Right
		if left1 != nil || left2 != nil {
			if left1 != nil && left2 != nil {
				left := &TreeNode{Val: left1.Val + left2.Val}
				node.Left = left
				queue = append(queue, left)
				queue1 = append(queue1, left1)
				queue2 = append(queue2, left2)
			} else if left1 != nil {
				node.Left = left1
			} else {
				node.Left = left2
			}
		}

		if right1 != nil || right2 != nil {
			if right1 != nil && right2 != nil {
				right := &TreeNode{Val: right1.Val + right2.Val}
				node.Right = right
				queue = append(queue, right)
				queue1 = append(queue1, right1)
				queue2 = append(queue2, right2)
			} else if right1 != nil {
				node.Right = right1
			} else {
				node.Right = right2
			}
		}
	}
	return merged
}

/*
也可以使用广度优先搜索合并两个二叉树。首先判断两个二叉树是否为空，
- 如果两个二叉树都为空，则合并后的二叉树也为空，
- 如果只有一个二叉树为空，则合并后的二叉树为另一个非空的二叉树。
- 如果两个二叉树都不为空，则首先计算合并后的根节点的值，
然后从合并后的二叉树与两个原始二叉树的根节点开始广度优先搜索，
从根节点开始同时遍历每个二叉树，并将对应的节点进行合并。

使用三个队列分别存储合并后的二叉树的节点以及两个原始二叉树的节点。
初始时将每个二叉树的根节点分别加入相应的队列。每次从每个队列中取出一个节点，
判断两个原始二叉树的节点的左右子节点是否为空。
如果两个原始二叉树的当前节点中至少有一个节点的左子节点不为空，
则合并后的二叉树的对应节点的左子节点也不为空。对于右子节点同理。

如果合并后的二叉树的左子节点不为空，则需要根据两个原始二叉树的左子节点计算
合并后的二叉树的左子节点以及整个左子树。考虑以下两种情况：

1. 如果两个原始二叉树的左子节点都不为空，则合并后的二叉树的左子节点的值
为两个原始二叉树的左子节点的值之和，在创建合并后的二叉树的左子节点之后，
将每个二叉树中的左子节点都加入相应的队列；

2. 如果两个原始二叉树的左子节点有一个为空，即有一个原始二叉树的左子树为空，
则合并后的二叉树的左子树即为另一个原始二叉树的左子树，
此时也不需要对非空左子树继续遍历，因此不需要将左子节点加入队列。

对于右子节点和右子树，处理方法与左子节点和左子树相同。

复杂度分析

时间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点个数。
对两个二叉树同时进行广度优先搜索，只有当两个二叉树中的对应节点都不为空时
才会访问到该节点，因此被访问到的节点数不会超过较小的二叉树的节点数。

空间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点个数。
空间复杂度取决于队列中的元素个数，队列中的元素个数不会超过较小的二叉树的
节点数。
*/