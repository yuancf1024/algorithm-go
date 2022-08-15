/**
 * @file 641.Design-Circular-Deque.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * leetcode-641.设计循环双端队列
 * 
设计实现双端队列。

实现 MyCircularDeque 类:

MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
boolean insertFront()：将一个元素添加到双端队列头部。 
如果操作成功返回 true ，否则返回 false 。
boolean insertLast() ：将一个元素添加到双端队列尾部。
如果操作成功返回 true ，否则返回 false 。
boolean deleteFront() ：从双端队列头部删除一个元素。 
如果操作成功返回 true ，否则返回 false 。
boolean deleteLast() ：从双端队列尾部删除一个元素。
如果操作成功返回 true ，否则返回 false 。
int getFront() )：从双端队列头部获得一个元素。
如果双端队列为空，返回 -1 。
int getRear() ：获得双端队列的最后一个元素。 
如果双端队列为空，返回 -1 。
boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
 

示例 1：

输入
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
输出
[null, true, true, true, false, 2, true, true, true, 4]

解释
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
 
 

提示：

1 <= k <= 1000
0 <= value <= 1000
insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull  调用次数不大于 2000 次
 */

// 建议掌握链表这种方式
// 双向链表定义方式
struct DLinkListNode {
    int val;
    DLinkListNode *prev, *next;
    DLinkListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};

// 方法二：链表
class MyCircularDeque {
private:
    DLinkListNode *head, *tail;
    int capacity;
    int size;

public:
    // 构造函数,双端队列最大为 k
    MyCircularDeque(int k) : capacity(k), size(0), head(nullptr), tail(nullptr) {

    }
    
    // 将一个元素添加到双端队列头部
    bool insertFront(int value) {
        if (size == capacity) {
            return false;
        }
        DLinkListNode *node = new DLinkListNode(value);
        if (size == 0) {
            head = tail = node;
        } else {
            node->next = head; // node节点插入head前
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }

    // 将一个元素添加到双端队列尾部
    bool insertLast(int value) {
        if (size == capacity) {
            return false;
        }
        DLinkListNode *node = new DLinkListNode(value);
        if (size == 0) {
            head = tail = node;
        } else {
            tail->next = node; // node节点插入tail之后
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }

    // 从双端队列头部删除一个元素
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        DLinkListNode *node = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete node;
        size--;
        return true;
    }

    // 从双端队列尾部删除一个元素
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        DLinkListNode *node = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        delete node;
        size--;
        return true;
    }

    // 从双端队列头部获得一个元素
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->val;
    }

    // 获得双端队列的最后一个元素
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->val;
    }

    // 判断双端队列是否为空
    bool isEmpty() { 
        return size == 0;
    }

    // 判断双端队列是否为满
    bool isFull() { 
        return size == capacity; 
    }
};

// 方法一：数组
class MyCircularDeque {
private:
    vector<int> elements;
    int rear, front;
    int capacity;

public:
    // 构造函数,双端队列最大为 k
    MyCircularDeque(int k) { 
        capacity = k + 1; // 初始空间大小为k+1
        rear = front = 0; // 0
        elements = vector<int>(k + 1);
    }

    // 将一个元素添加到双端队列头部
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity; //
        elements[front] = value;
        return true;
    }

    // 将一个元素添加到双端队列尾部
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    // 从双端队列头部删除一个元素
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    // 从双端队列尾部删除一个元素
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    // 从双端队列头部获得一个元素
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return elements[front];
    }

    // 获得双端队列的最后一个元素
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return elements[(rear-1+capacity) % capacity];
    }

    // 判断双端队列是否为空
    bool isEmpty() { 
        return rear == front; 
    }

    // 判断双端队列是否满
    bool isFull() { 
        return (rear + 1) % capacity == front;
    }
};




/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

/**
 * @brief 
 * 方法一：数组
可以参考循环队列：「622. 设计循环队列」，我们利用循环队列实现双端队列。
在循环队列中的基础上，我们增加 insertFront 和 deleteFront 函数实现即可。
根据循环队列的定义，队列判空的条件是front=rear，
而队列判满的条件是 front=(rear+1) mod capacity。

对于一个固定大小的数组，只要知道队尾rear 与队首front，
即可计算出队列当前的长度：
(rear−front+capacity) mod capacity

循环双端队列与循环队列的属性一致:

- elements：一个固定大小的数组，用于保存循环队列的元素。
- capacity：循环队列的容量，即队列中最多可以容纳的元素数量。
- front：队列首元素对应的数组的索引。
- rear：队列尾元素对应的索引的下一个索引。

循环双端队列的接口方法如下：
- MyCircularDeque(int k)：初始化队列，同时 base 数组的空间初始化大小为k+1。
front,rear 全部初始化为 0。
- insertFront(int value)：队列未满时，在队首插入一个元素。
我们首先将队首 front 移动一个位置，更新队首索引为front 
更新为(front−1+capacity) mod capacity。
- insertLast(int value)：队列未满时，在队列的尾部插入一个元素，
并同时将队尾的索引rear 更新为(rear+1) mod capacity。
- deleteFront()：队列不为空时，从队首删除一个元素，
并同时将队首的索引front 更新为(front+1) mod capacity。
- deleteLast()：队列不为空时，从队尾删除一个元素。
并同时将队尾的索引rear 更新为(rear−1+capacity) mod capacity。
- getFront()：返回队首的元素，需要检测队列是否为空。
- getRear()：返回队尾的元素，需要检测队列是否为空。
- isEmpty()：检测队列是否为空，根据之前的定义只需判断rear是否等于front。
- isFull()：检测队列是否已满，
根据之前的定义只需判断 front 是否等于(rear+1) mod capacity。

复杂度分析
时间复杂度：初始化和每项操作的时间复杂度均为O(1)。
空间复杂度：O(k)，其中k为给定的队列元素数目。


方法二：链表
我们同样可以使用双向链表来模拟双端队列，
实现双端队列队首与队尾元素的添加、删除。
双向链表实现比较简单，双向链表支持O(1) 时间复杂度内
在指定节点的前后插入新的节点或者删除新的节点。

循环双端队列的属性如下:
- head：队列的头节点；
- tail：队列的尾节点
- capacity：队列的容量大小。
- size：队列当前的元素数量。
循环双端队列的接口方法如下：

- MyCircularDeque(int k)：初始化队列，同时初始化队列元素数量 
size 为 0。head,tail 初始化为空。
- insertFront(int value)：队列未满时，在队首头结点
head 之前插入一个新的节点，并更新 head，并更新 size。
- insertLast(int value)：队列未满时，
在队尾节点tail 之后插入一个新的节点，并更新 tail，并更新 size。
- deleteFront()：队列不为空时，删除头结点head，
并更新head 为head 的后一个节点，并更新size。
- deleteLast()：队列不为空时，删除尾结点tail，
并更新 tail 为 tail 的前一个节点，并更新 size。
- getFront()：返回队首节点指向的值，需要检测队列是否为空。
- getRear()：返回队尾节点指向的值，需要检测队列是否为空。
- isEmpty()：检测当前size是否为0。
- isFull()：检测当前size是否为capacity。

复杂度分析
时间复杂度：初始化和每项操作的时间复杂度均为O(1)。

空间复杂度：O(k)，其中k为给定的队列元素数目。
 */

