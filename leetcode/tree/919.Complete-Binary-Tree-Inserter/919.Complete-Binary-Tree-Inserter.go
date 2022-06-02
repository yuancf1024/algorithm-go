package leetcode

/* 919. 完全二叉树插入器
完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，
并且所有的节点都尽可能地集中在左侧。

设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。

实现 CBTInserter 类:

CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点 TreeNode。
使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
CBTInserter.get_root() 将返回树的头节点。

示例 1：
输入
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
输出
[null, 1, 2, [1, 2, 3, 4]]

解释
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
 

提示：
树中节点数量范围为 [1, 1000] 
0 <= Node.val <= 5000
root 是完全二叉树
0 <= val <= 5000 
每个测试用例最多调用 insert 和 get_root 操作 10^4 次
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

type CBTInserter struct {
	p []*TreeNode
}

func Constructor(root *TreeNode) CBTInserter {
	this := &CBTInserter{[]*TreeNode{root}}
	for i := 0; i < len(this.p); i++ { // 预处理了个按层次遍历的二叉树的记录列表
		if this.p[i].Left != nil {
			this.p = append(this.p, this.p[i].Left)
		}
		if this.p[i].Right != nil {
			this.p = append(this.p, this.p[i].Right)
		}
	}
	return *this
}


func (this *CBTInserter) Insert(val int) int {
	n := len(this.p)
	father := this.p[(n-1) >> 1] // 插入的时候坐标折半O(1)就可以直接找到父节点了
	this.p = append(this.p, &TreeNode{Val: val})
	if n & 1 == 1 { // n != 0
		father.Left = this.p[n]
	} else { // n == 0
		father.Right = this.p[n]
	}
	return father.Val
}

func (this *CBTInserter) Get_root() *TreeNode {
	return this.p[0]
}

/*
O(n)预处理了个按层次遍历的二叉树的记录列表，
插入的时候坐标折半O(1)就可以直接找到父节点了。
*/

/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(val);
 * param_2 := obj.Get_root();
 */