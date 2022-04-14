package leetcode

// import "github.com/yuancf1024/algorithm-go/structures"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/* 116. 填充每个节点的下一个右侧节点指针
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。
二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。初始状态下，
所有 next 指针都被设置为 NULL。
*/

// type TreeNode = structures.TreeNode

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

// 解法1： 迭代 BFS
func connect(root *Node) *Node {
	if root == nil {
		return root
	}

	q := []*Node{root}
	for len(q) > 0 {
		var p []*Node
		// 遍历这一层的所有节点
		for i, node := range q {
			if i+1 < len(q) {
				node.Next = q[i+1] // 指针指向其下一个右侧节点
			}
			if node.Left != nil {
				p = append(p, node.Left) // 左节点添加进下一层
			}
			if node.Right != nil {
				p = append(p, node.Right)
			}
		}
		q = p // 把下一层赋给q
	}
	return root
}

// 解法二 递归 DFS
func connect2(root *Node) *Node {
	if root == nil {
		return nil
	}
	connectTwoNode(root.Left, root.Right)
	return root
}

func connectTwoNode(node1, node2 *Node) {
	if node1 == nil || node2 == nil {
		return
	}
	node1.Next = node2
	connectTwoNode(node1.Left, node1.Right)
	connectTwoNode(node2.Left, node2.Right)
	connectTwoNode(node1.Right, node2.Left)
}

/*
使用层次遍历？

解题思路

本质上是二叉树的层序遍历，
基于广度优先搜索，将每层的节点放入队列，并遍历队列进行连接。
*/