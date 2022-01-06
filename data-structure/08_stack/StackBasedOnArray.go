package _8_stack

import "fmt"

/*
基于数组实现栈
*/

// 定义栈
type ArrayStack struct {
	// 数据
	data []interface{}
	// 栈顶指针
	top int
}

// 新建数组栈
func NewArrayStack() *ArrayStack {
	return &ArrayStack{
		data: make([]interface{}, 0, 32), // 类型、长度、容量
		top:  -1,
	}
}

// 判断栈是否为空
func (this *ArrayStack) IsEmpty() bool {
	if this.top < 0 {
		return true
	}
	return false
}

// 入栈
func (this *ArrayStack) Push(v interface{}) {
	if this.top < 0 {
		this.top = 0
	} else {
		this.top += 1
	}

	if this.top > len(this.data)-1 {
		this.data = append(this.data, v)
	} else {
		this.data[this.top] = v // 实际上将v赋给切片的最后一个位置上
	}
}

// 出栈
func (this *ArrayStack) Pop() interface{} {
	if this.IsEmpty() {
		return nil // 如果栈为空，返回nil
	}
	v := this.data[this.top]
	this.top -= 1
	return v // 返回栈顶元素
}

// 返回栈顶元素
func (this *ArrayStack) Top() interface{} {
	if this.IsEmpty() {
		return nil
	}
	return this.data[this.top]
}

// 刷新栈
func (this *ArrayStack) Flush() {
	this.top = -1
}

// 打印栈
func (this *ArrayStack) Print() {
	if this.IsEmpty() {
		fmt.Println("empty stack")
	} else {
		for i := this.top; i >= 0; i-- {
			fmt.Println(this.data[i])
		}
	}
}
