package _8_stack

type Stack interface {
	Push(v interface{}) // 入栈
	Pop() interface{} // 出栈
	IsEmpty() bool // 判断栈是否为空
	Top() interface{} // 返回栈顶元素
	Flush() // 刷新
}