package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/**
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 
（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
**/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func levelOrderBottom(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }

    queue := []*TreeNode{root}
    res := make([][]int,0)
    for len(queue) > 0 {
        l := len(queue)
        tmpArr := make([]int, 0, l)
        for i := 0; i < l; i++ {
            if queue[i].Left != nil {
                queue = append(queue, queue[i].Left)
            }
            if queue[i].Right != nil {
                queue = append(queue, queue[i].Right)
            }
            tmpArr = append(tmpArr, queue[i].Val)
        }
        queue = queue[l:]
        res = append(res, tmpArr)
    }
    // 反转1
    // l, r := 0, len(res)-1
    // for l < r {
    //     res[l], res[r] = res[r], res[l]
    //     l, r = l+1, r-1
    // }

    // 反转2
    length := len(res)
    for i := 0; i < length/2; i++ {
        res[i], res[length-i-1] = res[length-i-1], res[i]
    }
    return res
}