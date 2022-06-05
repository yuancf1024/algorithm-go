package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type TreeNode = structures.TreeNode

/* 437. 路径总和 III
给定一个二叉树的根节点 root ，和一个整数 targetSum ，
求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，
但是路径方向必须是向下的（只能从父节点到子节点）。

示例 1：

			10
		   /  \
		  5   -3
		 / \    \
		3   2    11
	   / \   \
	  3  -2   1

输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。

示例 2：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//  带缓存 dfs
func pathSum(root *TreeNode, targetSum int) int {
	prefixSum := make(map[int]int)
	prefixSum[0] = 1
	return dfs(root, prefixSum, 0, targetSum)
}

func dfs(root *TreeNode, prefixSum map[int]int, cur, sum int) int {
	if root == nil {
		return 0
	}
	cur += root.Val
	cnt := 0
	if v, ok := prefixSum[cur-sum]; ok {
		cnt = v
	}
	prefixSum[cur]++
	cnt += dfs(root.Left, prefixSum, cur, sum)
	cnt += dfs(root.Right, prefixSum, cur, sum)
	prefixSum[cur]--
	return cnt
}

// 解法二
func pathSumIII(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	res := findPath437(root, sum)
	res += pathSumIII(root.Left, sum)
	res += pathSumIII(root.Right, sum)
	return res
}

// 寻找包含 root 这个结点，且和为 sum 的路径
func findPath437(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	res := 0
	if root.Val == sum {
		res++
	}
	res += findPath437(root.Left, sum-root.Val)
	res += findPath437(root.Right, sum-root.Val)
	return res
}

/*
解题思路
- 这一题是第 112 题 Path Sum 和第 113 题 Path Sum II 的加强版，
这一题要求求出任意一条路径的和为 sum，起点不一定是根节点，
可以是任意节点开始。
- 注意这一题可能出现负数的情况，节点和为 sum，并不一定是最终情况，
有可能下面还有正数节点和负数节点相加正好为 0，那么这也是一种情况。
一定要遍历到底。
- 一个点是否为 sum 的起点，有 3 种情况，第一种情况路径包含该 root 节点，
如果包含该结点，就在它的左子树和右子树中寻找和为 sum-root.Val 的情况。
第二种情况路径不包含该 root 节点，
那么就需要在它的左子树和右子树中分别寻找和为 sum 的结点。
*/