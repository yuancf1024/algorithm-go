package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/* 102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
（即逐层地，从左到右访问所有节点）。
For example: Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// // BFS+Go内置list
// func levelOrder(root *TreeNode) [][]int {
//     var res [][]int
//     if root == nil {
//         return res
//     }

//     queue := list.New()
//     queue.PushBack(root)
//     var tmpArr []int
//     for queue.Len() > 0 {
//         length := queue.Len()
//         for i := 0; i < length; i++ {
//             node := queue.Remove(queue.Front()).(*TreeNode)
//             if node.Left != nil {
//                 queue.PushBack(node.Left)
//             }

//             if node.Right != nil {
//                 queue.PushBack(node.Right)
//             }
//             tmpArr = append(tmpArr, node.Val)
//         }
//         res = append(res, tmpArr)
//         tmpArr = []int{}
//     }
//     return res
// }

// BFS
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}

	queue := []*TreeNode{root}
	res := make([][]int, 0)
	for len(queue) > 0 {
		l := len(queue)
		tmp := make([]int, 0, l)
		for i := 0; i < l; i++ {
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
			tmp = append(tmp, queue[i].Val)
		}
		queue = queue[l:]
		res = append(res, tmp)
	}
	return res
}

// DFS
func levelOrder1(root *TreeNode) [][]int {
	var res [][]int
	var dfsLevel func(node *TreeNode, level int)
	dfsLevel = func(node *TreeNode, level int) {
		if node == nil {
			return
		}
		if len(res) == level {
			res = append(res, []int{node.Val})
		} else {
			res[level] = append(res[level], node.Val)
		}
		dfsLevel(node.Left, level+1)
		dfsLevel(node.Right, level+1)
	}
	dfsLevel(root, 0)
	return res
}