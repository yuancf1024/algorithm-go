package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

/*95. 不同的二叉搜索树 II
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 
互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type TreeNode = structures.TreeNode

// 递归求解1
// func generateTrees(n int) []*TreeNode {
// 	if n == 0 {
// 		return []*TreeNode{}
// 	}
// 	return generateBSTree(1, n)
// }

// func generateBSTree(start, end int) []*TreeNode {
// 	tree := []*TreeNode{}
// 	if start > end {
// 		tree = append(tree, nil)
// 		return tree
// 	}
// 	for i := start; i <= end; i++ {
// 		left := generateBSTree(start, i-1)
// 		right := generateBSTree(i+1, end)
// 		for _, l := range left {
// 			for _, r := range right {
// 				root := &TreeNode{Val: i, Left: l, Right: r}
// 				tree = append(tree, root)
// 			}
// 		}
// 	}
// 	return tree
// }

/*解题思路：
输出 1-n 元素组成的 BST 所有解。这一题递归求解即可。
外层循环遍历 1-n 所有结点，作为根结点，内层双层递归分别求出左子树和右子树。
*/

// 递归求解2 更容易理解
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return nil
	}
	return generate(1, n)
}

func generate(start, end int) []*TreeNode {
	if start > end {
		return []*TreeNode{nil}
	}

	ans := make([]*TreeNode, 0)
	for i := start; i <= end; i++ {
		// 递归生成所有左右子树
		lefts := generate(start, i-1)
		rights := generate(i+1, end)
		// 拼接左右子树后返回
		for j := 0; j < len(lefts); j++ {
			for k := 0; k < len(rights); k++ {
				root := &TreeNode{Val: i}
				root.Left = lefts[j]
				root.Right = rights[k]
				ans = append(ans, root)
			}
		}
	}
	return ans
}