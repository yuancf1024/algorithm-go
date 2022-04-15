package leetcode

/* 232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。
队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top,
 size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来
模拟一个栈，只要是标准的栈操作即可。
*/

type MyQueue struct {
	Stack *[]int
	Queue *[]int
}

// 初始化数据结构
func Constructor232() MyQueue {
	tmp1, tmp2 := []int{}, []int{}
	return MyQueue{Stack: &tmp1, Queue: &tmp2}
}

// Push 将元素 x 推到队列的末尾
func (this *MyQueue) Push(x int)  {
	*this.Stack = append(*this.Stack, x)
}

// Pop 从队列的开头移除并返回元素
func (this *MyQueue) Pop() int {
	if len(*this.Queue) == 0 {
		this.fromStackToQueue(this.Stack, this.Queue)
	}
	popped := (*this.Queue)[len(*this.Queue)-1] // 队头元素
	*this.Queue = (*this.Queue)[:len(*this.Queue)-1] // 队头出队
	return popped
}

// Peek 返回队列开头的元素
func (this *MyQueue) Peek() int {
	if len(*this.Queue) == 0 {
		this.fromStackToQueue(this.Stack, this.Queue)
	}
	return (*this.Queue)[len(*this.Queue)-1]
}

// Empty 返回队列是否为空
func (this *MyQueue) Empty() bool {
	return len(*this.Stack) + len(*this.Queue) == 0
}

func (this *MyQueue) fromStackToQueue(s, q *[]int) {
	for len(*s) > 0 {
		poped := (*s)[len(*s) - 1] //输入栈栈顶元素弹出
		*s = (*s)[:len(*s)-1]

		*q = append(*q, poped) // 将元素加入输出栈
		// 巧妙地实现了队列头部，先进先出
	}
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */

// 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？
// 换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。

/*
思路
将一个栈当作输入栈，用于压入 push 传入的数据；另一个栈当作输出栈，
用于 pop 和 peek 操作。

每次 pop 或 peek 时，若输出栈为空则将输入栈的全部数据依次弹出并压入输出栈，
这样输出栈从栈顶往栈底的顺序就是队列从队首往队尾的顺序。

复杂度分析
时间复杂度：push 和 empty 为 O(1)，pop 和 peek 为均摊 O(1)。
对于每个元素，至多入栈和出栈各两次，故均摊复杂度为 O(1)。

空间复杂度：O(n)。其中 n 是操作总数。对于有 n 次push 操作的情况，
队列中会有 n 个元素，故空间复杂度为 O(n)。

执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了25.91%的用户
*/