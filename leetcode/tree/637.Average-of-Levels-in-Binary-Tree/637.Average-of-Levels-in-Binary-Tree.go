package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/*
给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。
与实际答案相差 10-5 以内的答案可以被接受。
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 方法1：微调BFS层次遍历代码：不够灵活
func averageOfLevels(root *TreeNode) []float64 {

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

	// 计算每一层的平均值
	// go语言的除法，这里用着不利索
	var finRes []float64
	for i := 0; i < len(res); i++ {
		var sum int
		for j := 0; j < len(res[i]); j++ {
			sum += res[i][j]
		}
		tmp := float64(sum) / float64(len(res[i]))
		finRes = append(finRes, tmp)
	}
	return finRes
}

// 方法2：BFS层次遍历代码：改模板
func averageOfLevels1(root *TreeNode) []float64 {
	if root == nil {
		return nil
	}

	queue := []*TreeNode{root}
	res := make([]float64, 0)
	for len(queue) > 0 {
		l := len(queue)
		var sum int = 0
		for i := 0; i < l; i++ {
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
			sum += queue[i].Val
		}
		queue = queue[l:]
		res = append(res, float64(sum) / float64(l))
	}
	return res
}

/**
方法1：
执行用时: 4 ms 在所有 Go 提交中击败了98%的用户
内存消耗: 6.7 MB 在所有 Go 提交中击败了19%的用户
方法2：
执行用时：8 ms, 在所有 Go 提交中击败了77.03%的用户
内存消耗：6 MB, 在所有 Go 提交中击败了98.84%的用户

方法1：直接接着模板，然后计算每行的平均值。因为需要额外开辟内存空间，
所以内存消耗较多，但是速度非常快，说明原始的模板代码写得很好。
方法2：在模板代码中，也就是层序遍历节点时，计算每层总和和平均值，
因此for循环中夹杂着计算，时间复杂度提高，但节约了内存空间。
**/