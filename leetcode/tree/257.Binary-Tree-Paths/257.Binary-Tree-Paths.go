package leetcode

import (
	"strconv"
	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/* 257. 二叉树的所有路径
给你一个二叉树的根节点 root ，按 任意顺序 ，
返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。

 
示例 1：

	1
   / \
  2   3
   \
    5

输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
示例 2：

输入：root = [1]
输出：["1"]
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
func binaryTreePaths(root *TreeNode) []string {
	res := []string{}
	if root == nil {
		return res
	}
	if root.Left == nil && root.Right == nil {
		return []string{strconv.Itoa(root.Val)}
	}
	tmpLeft := binaryTreePaths((root.Left))
	for i := 0; i < len(tmpLeft); i++ {
		res = append(res, strconv.Itoa(root.Val) + "->" + tmpLeft[i])
	}
	tmpRight := binaryTreePaths(root.Right)
	for i := 0; i < len(tmpRight); i++ {
		res = append(res, strconv.Itoa(root.Val) + "->" + tmpRight[i])
	}
	return res
}

/*
解题思路
Google 的面试题，考察递归
*/