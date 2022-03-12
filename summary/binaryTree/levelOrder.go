package binaryTree

/** 102.二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。
（即逐层地，从左到右访问所有节点）。
**/

// import "container/list"
// import "github.com/yuancf1024/algorithm-go/structures"

// type TreeNode = structures.TreeNode
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 调用了Go语言的标准库，在牛客上无法正常提交
// func LevelOrder(root *TreeNode) [][]int {
// 	res := [][]int{}
// 	if root == nil { // 防止为空
// 		return res
// 	}

// 	queue := list.New()
// 	queue.PushBack(root)
// 	var tmpArr []int
// 	for queue.Len() > 0 {
// 		length := queue.Len() 
// 		// 保存当前层的长度，然后处理当前层（十分重要，防止添加下层元素影响判断层中元素的个数）
// 		for i := 0; i < length; i++ {
// 			node := queue.Remove(queue.Front()).(*TreeNode) // 出队列
// 			if node.Left != nil {
// 				queue.PushBack(node.Left)
// 			}
// 			if node.Right != nil {
// 				queue.PushBack(node.Right)
// 			}
// 			tmpArr = append(tmpArr, node.Val) // 将值加入本层切片中
// 		}
// 		res = append(res, tmpArr) // 放入结果集
// 		tmpArr = []int{} // 清空层的数据
// 	}
// 	return res
// }

// 解法1：广度优先BFS
func LevelOrder(root *TreeNode) [][]int {
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

// 解法2：深度优先DFS (很巧妙)
func LevelOrder1(root *TreeNode) [][]int {
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