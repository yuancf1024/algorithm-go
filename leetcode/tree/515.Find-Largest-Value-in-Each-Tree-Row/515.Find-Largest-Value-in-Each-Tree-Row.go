package leetcode

import (
	"math"
	"github.com/yuancf1024/algorithm-go/structures"
)

type TreeNode = structures.TreeNode 

/* 515. 在每个树行中找最大值
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

示例1：
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

示例2：
输入: root = [1,2,3]
输出: [1,3]
 

提示：
二叉树的节点个数的范围是 [0,10^4]
-2^31 <= Node.val <= 2^31 - 1
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//  解法一：层序遍历二叉树，遍历过程中不断更新最大值
func largestValues(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		l := len(queue)
		// tmp := make([]int, l)
		max := math.MinInt32
		for i := 0; i < l; i++ {
			// node := queue[0]
			// queue = queue[1:]
			if queue[i].Val > max {
				max = queue[i].Val
			}
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
		}
		// 找出tmp中的最大值
		queue = queue[l:]
		res = append(res, max)
	}
	return res
}

/* 解题思路
给出一个二叉树，要求依次输出每行的最大值
用 BFS 层序遍历，将每层排序取出最大值。
改进的做法是遍历中不断更新每层的最大值。
*/

// 解法二：深度遍历二叉树
func largestValues2(root *TreeNode) []int {
	var res []int
	var dfs func(root *TreeNode, level int)
	dfs = func(root *TreeNode, level int) {
		if root == nil {
			return
		}
		if len(res) == level {
			res = append(res, root.Val)
		}
		if res[level] < root.Val {
			res[level] = root.Val
		}
		dfs(root.Right, level+1)
		dfs(root.Left, level+1)
	}
	dfs(root, 0)
	return res
}