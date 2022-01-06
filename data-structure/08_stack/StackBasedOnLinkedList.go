package _8_stack

import "fmt"

/*
基于链表实现的栈
*/

// 定义节点
type node struct {
	next *node
	val  interface{}
}

// 定义链表栈
type LinkedListStack struct {
	// 栈顶节点
	topNode *node
}

// 新建链表栈
func NewLinkedListStack() *LinkedListStack {
	return &LinkedListStack{nil}
}

// 判断链表栈是否为空
func (this *LinkedListStack) IsEmpty() bool {
	return this.topNode == nil
}

// 入栈
func (this *LinkedListStack) Push(v interface{}) {
	this.topNode = &node{next: this.topNode, val: v}
}

// 出栈
func (this *LinkedListStack) Pop() interface{} {
	if this.IsEmpty() {
		return nil
	}
	v := this.topNode.val
	this.topNode = this.topNode.next
	return v
}

// 返回栈顶元素
func (this *LinkedListStack) Top() interface{} {
	if this.IsEmpty() {
		return nil
	}

	return this.topNode.val
}

// 刷新栈
func (this *LinkedListStack) Flush() {
	this.topNode = nil
}

// 打印栈的元素
func (this *LinkedListStack) Print() {
	if this.IsEmpty() {
		fmt.Println("empty stack")
	} else {
		cur := this.topNode
		for cur != nil {
			fmt.Println(cur.val)
			cur = cur.next
		}
	}
}