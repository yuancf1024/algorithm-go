package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode
/* 199. 二叉树的右视图
给定一个二叉树的 根节点 root，想象自己站在它的右侧，
按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 修改了res的返回结构
func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	queue := []*TreeNode{root}
	res := make([]int, 0)
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
		index := len(tmp) - 1 // 把每一层的最后一个元素添加进res即可
		res = append(res, tmp[index])
	}
	return res
}

// 在模板的基础上微调
func rightSideView1(root *TreeNode) []int {
	if root == nil {
		return []int{}
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

	// 取每一行的最后一个元素
	var finRes []int
	for i := 0; i < len(res); i++ {
		finRes = append(finRes, res[i][len(res[i])-1])
	}

	return finRes
}

/* 解题思路
这一题是按层序遍历的变种题。按照层序把每层的元素都遍历出来，然后依次取每一层的最右边的元素即可。用一个队列即可实现。
第 102 题和第 107 题都是按层序遍历的。
*/