package _8_stack

import "fmt"

type Browser struct {
	forwardStack Stack
	backStack    Stack
}

// 新建浏览器结构体，存储2个栈
func NewBrowser() *Browser {
	return &Browser{
		forwardStack: NewArrayStack(),
		backStack:    NewLinkedListStack(),
	}
}

// 判断能否前进浏览
func (this *Browser) CanForward() bool {
	if this.forwardStack.IsEmpty() {
		return false
	}
	return true
}

// 判断能否后退浏览
func (this *Browser) CanBack() bool {
	if this.backStack.IsEmpty() {
		return false
	}
	return true
}

// 打开某个页面
func (this *Browser) Open(addr string) {
	fmt.Printf("Open new addr %+v\n", addr)
	this.forwardStack.Flush()
}

// 浏览过的页面进入backStack
func (this *Browser) PushBack(addr string) {
	this.backStack.Push(addr) 
}

// 前进，该页面从forwardStack出栈进入backStack
func (this *Browser) Forward() {
	if this.forwardStack.IsEmpty() {
		return
	}
	top := this.forwardStack.Pop()
	this.backStack.Push(top)
	fmt.Printf("forward to %+v\n", top)
}

// 后退，该页面从backStack出栈进入forwardStack
func (this *Browser) Back() {
	if this.backStack.IsEmpty() {
		return
	}

	top := this.backStack.Pop()
	this.forwardStack.Push(top)
	fmt.Printf("back to %+v\n", top)
}