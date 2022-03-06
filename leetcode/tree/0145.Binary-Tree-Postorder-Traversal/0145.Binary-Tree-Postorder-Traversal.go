package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode = structures.TreeNode

// 递归解法
func postorderTraversal(root *TreeNode) []int {
    var res []int
    traversal(root, &res)
    return res
}

func traversal(cur *TreeNode, output *[]int) {
    if cur == nil {
        return
    }

    traversal(cur.Left, output)
    traversal(cur.Right, output)
    *output = append(*output, cur.Val)

}