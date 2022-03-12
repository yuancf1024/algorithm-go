package binaryTree

import "container/list"

/** 102.二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。
（即逐层地，从左到右访问所有节点）。
**/

func LevelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	if root == nil { // 防止为空
		return res
	}

	queue := list.New()
	queue.PushBack(root)
	var tmpArr []int
	for queue.Len() > 0 {
		length := queue.Len() 
		// 保存当前层的长度，然后处理当前层（十分重要，防止添加下层元素影响判断层中元素的个数）
		for i := 0; i < length; i++ {
			node := queue.Remove(queue.Front()).(*TreeNode) // 出队列
			if node.Left != nil {
				queue.PushBack(node.Left)
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
			}
			tmpArr = append(tmpArr, node.Val) // 将值加入本层切片中
		}
		res = append(res, tmpArr) // 放入结果集
		tmpArr = []int{} // 清空层的数据
	}
	return res
}
