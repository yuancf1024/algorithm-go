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

/*
确定单层递归的逻辑
这里就把平衡二叉树中删除节点遇到的情况都搞清楚。

有以下五种情况：

第一种情况：没找到删除的节点，遍历到空节点直接返回了
找到删除的节点
第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）
放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。
*/
// 参考代码随想录，没整明白😂
func deleteNode(root *TreeNode, key int) *TreeNode {
	// 第一种情况：没找到删除的节点，遍历到空节点直接返回了
	if root == nil {
		return nil
	}

	if key < root.Val {
		root.Left = deleteNode(root.Left, key)
		return root
	}
	if key > root.Val {
		root.Right = deleteNode(root.Right, key)
		return root
	}
	if root.Right == nil {
		return root.Left
	}
	if root.Left == nil {
		return root.Right
	}

	minnode := root.Right
	for minnode.Left != nil {
		minnode = minnode.Left
	}

	root.Val = minnode.Val
	root.Right = delete(root.Right)
	return root
}

func delete(root *TreeNode) *TreeNode {
	if root.Left == nil {
		pRight := root.Right
		root.Right = nil
		return pRight
	}
	root.Left = delete(root.Left)
	return root
}

// leetcode参考，一个符合工程实际的解法
func deleteNode1(root *TreeNode, key int) *TreeNode {
	dummy := &TreeNode{Left: root}
	parent, cur := dummy, root
	isLeft := true
	for cur != nil {
		if cur.Val == key {
			break
		}
		parent = cur
		if cur.Val > key {
			isLeft = true
			cur = cur.Left
		} else {
			isLeft = false
			cur = cur.Right
		}
	}
	if cur != nil {
		if isLeft {
			parent.Left = delete1(cur)
		} else {
			parent.Right = delete1(cur)
		}
	}
	dummy.Left, cur = nil, dummy.Left
	return cur
}

func delete1(cur *TreeNode) *TreeNode {
	if cur.Left == nil && cur.Right == nil {
		return nil
	}

	if cur.Left == nil {
		res := cur.Right
		cur.Right = nil
		return res
	}

	if cur.Right == nil {
		res := cur.Left
		cur.Left = nil
		return res
	}

	// 在右子树找到最左节点来代替cur（也可以在左子树中找到最右节点来代替cur）
	left, right := cur.Left, cur.Right
	var pre *TreeNode
	p := right
	for p.Left != nil {
		pre = p
		p = p.Left
	}
	p.Left = left
	if pre != nil { // p != right
		pre.Left = p.Right
		p.Right = right
	}
	cur.Left = nil
	cur.Right = nil
	return p
}

