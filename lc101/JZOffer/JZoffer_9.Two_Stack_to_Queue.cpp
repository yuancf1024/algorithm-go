/**
 * @file JZoffer_9.Two_Stack_to_Queue.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-JZoffer_9.Two_Stack_to_Queue.cpp
 * 

 */
class CQueue {
public:
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) { // 输入栈不为空
            outStack.push(inStack.top()); // 输入栈元素全部弹出进入输出栈
            inStack.pop();
        }
    }
    CQueue() {

    }
    
    void appendTail(int value) { // 添加到尾部，直接添加进输入栈
        inStack.push(value);
    }
    
    int deleteHead() { // 删除队列头部
        if (outStack.empty()) { // 考虑边界条件
            if (inStack.empty()) {
                return -1;
            }
            in2out();
        }
        int value = outStack.top();
        outStack.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
/*
总结出删除一个元素的步骤：当 stack2 中不为空时，
在 stack2 中的栈顶元素是最先进入队列的元素，可以弹出。
如果stack2为空时，我们把stack1中的元素逐个弹出并压入stack2。
由于先进入队列的元素被压到stack1的底端，
经过弹出和压入之后就处于stack2的顶端了，又可以直接弹出。

leetcode官方题解
方法一：双栈
思路
将一个栈当作输入栈，用于压入 appendTail 传入的数据；
另一个栈当作输出栈，用于 deleteHead 操作。

每次 deleteHead 时，若输出栈为空则将输入栈的全部数据依次弹出
并压入输出栈，这样输出栈从栈顶往栈底的顺序就是
队列从队首往队尾的顺序。

复杂度分析

时间复杂度：appendTail 为 O(1)，deleteHead 为均摊 O(1)。
对于每个元素，至多入栈和出栈各两次，故均摊复杂度为 O(1)。

空间复杂度：O(n)。其中 n 是操作总数。
对于有 n 次 appendTail 操作的情况，
队列中会有 n 个元素，故空间复杂度为 O(n)。

*/