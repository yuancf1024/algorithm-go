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

/*
思路与算法
题目本身希望我们将二叉树的每一层节点都连接起来形成一个链表。
因此直观的做法我们可以对二叉树进行层次遍历，在层次遍历的过程中将我们将
二叉树每一层的节点拿出来遍历并连接。

层次遍历基于广度优先搜索，它与广度优先搜索的不同之处在于，
广度优先搜索每次只会取出一个节点来拓展，而层次遍历会每次将队列中的
所有元素都拿出来拓展，这样能保证每次从队列中拿出来遍历的元素都是属于
同一层的，因此我们可以在遍历的过程中修改每个节点的 next 指针，
同时拓展下一层的新队列。

复杂度分析

时间复杂度：O(N)。每个节点会被访问一次且只会被访问一次，
即从队列中弹出，并建立 next 指针。

空间复杂度：O(N)。这是一棵完美二叉树，它的最后一个层级包含 N/2 个节点。
广度优先遍历的复杂度取决于一个层级上的最大元素数量。
这种情况下空间复杂度为 O(N)。

执行用时：4 ms, 在所有 Go 提交中击败了90.00%的用户
内存消耗：6.4 MB, 在所有 Go 提交中击败了48.82%的用户
*/

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
执行用时：4 ms, 在所有 Go 提交中击败了90.00%的用户
内存消耗：6.2 MB, 在所有 Go 提交中击败了98.87%的用户
*/

/*
使用层次遍历？

解题思路

本质上是二叉树的层序遍历，
基于广度优先搜索，将每层的节点放入队列，并遍历队列进行连接。
*/