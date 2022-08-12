/**
 * @file 225.Implement-Stack-using-Queues.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-225. 用队列实现栈
 * 
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 

注意：

你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 

示例：

输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False

 */


class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;
    /*初始化数据结构*/
    MyStack() {}

    // 元素x入栈
    void push(int x) { 
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
    }
    // 移除栈顶元素并返回
    int pop() { 
        int r = queue1.front();
        queue1.pop();
        return r;
    }

    // 获取栈顶元素
    int top() { 
        int r = queue1.front();
        return r;
    }
    // 返回栈是否为空
    bool empty() { 
        return queue1.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/**
 * @brief 
 * 绪论
这道题目是为初级读者准备的，题目涉及到栈和队列两种数据结构。

栈是一种后进先出的数据结构，元素从顶端入栈，然后从顶端出栈。

队列是一种先进先出的数据结构，元素从后端入队，然后从前端出队。

方法一：两个队列

为了满足栈的特性，即最后入栈的元素最先出栈，
在使用队列实现栈时，应满足队列前端的元素是最后入栈的元素。
可以使用两个队列实现栈的操作，其中 queue1用于存储栈内的元素，
queue2作为入栈操作的辅助队列。

入栈操作时，首先将元素入队到queue2，
然后将queu1的全部元素依次出队并入队到queue2，
此时queue2的前端的元素即为新入栈的元素，再将queue1和queue 2互换，
则queue1的元素即为栈内的元素，
queue1​的前端和后端分别对应栈顶和栈底。

由于每次入栈操作都确保queue1的前端元素为栈顶元素，
因此出栈操作和获得栈顶元素操作都可以简单实现。
出栈操作只需要移除queue 1的前端元素并返回即可，
获得栈顶元素操作只需要获得queue1的前端元素并返回即可（不移除元素）。

由于queue1用于存储栈内的元素，判断栈是否为空时，
只需要判断queue1是否为空即可。

复杂度分析

时间复杂度：入栈操作O(n)，其余操作都是O(1)，其中 n 是栈内的元素个数。
入栈操作需要将queue1中的n个元素出队，
并入队n+1 个元素到queue2，共有2n+1次操作，
每次出队和入队操作的时间复杂度都是 O(1)，
因此入栈操作的时间复杂度是O(n)。
出栈操作对应将queue1​的前端元素出队，时间复杂度是O(1)。
获得栈顶元素操作对应获得queue1的前端元素，时间复杂度是O(1)。
判断栈是否为空操作只需要判断queue1是否为空，时间复杂度是O(1)。

空间复杂度：O(n)，其中n是栈内的元素个数。
需要使用两个队列存储栈内的元素。

 */