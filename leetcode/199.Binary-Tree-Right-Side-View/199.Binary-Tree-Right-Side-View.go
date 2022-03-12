package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
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
		index := len(tmp) - 1
		res = append(res, tmp[index])
	}
	return res
}