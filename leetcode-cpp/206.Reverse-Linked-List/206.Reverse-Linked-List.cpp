/* 206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 
进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 双指针 参考代码随想录
class Solution {
public:
    ListNode* reverseList(ListNode* head) { 
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur) {
            temp = cur->next; // 保存一下cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre和cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

/*
思路

方法1：双指针

首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。

然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，
也就是保存一下这个节点。

为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，
将cur->next 指向pre ，此时已经反转了第一个节点了。

接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。

最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 
此时我们return pre指针就可以了，pre指针就指向了新的头结点。

*/

// 递归法 从前往后反转
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL)
            return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }
};

/*
方法2：递归法

递归法相对抽象一些，但是其实和双指针法是一样的逻辑，
同样是当cur为空的时候循环结束，不断将cur指向pre的过程。

关键是初始化的地方，可能有的同学会不理解， 
可以看到双指针法中初始化 cur = head，pre = NULL，
在递归法中可以从如下代码看出初始化的逻辑也是一样的，只不过写法变了。

具体可以看代码（已经详细注释），双指针法写出来之后，
理解如下递归写法就不难了，代码逻辑都是一样的。

我们可以发现，上面的递归写法和双指针法实质上都是从前往后翻转指针指向，
其实还有另外一种与双指针法不同思路的递归写法：从后往前翻转指针指向。
*/

// 递归法 从后往前翻转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 边缘条件判断
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        
        // 递归调用，翻转第二个节点后开始往后的链表
        ListNode* last = reverseList(head->next);
        // 翻转头节点与第一个节点的指向
        head->next->next = head;
        // 此时的head节点为尾节点，next需要指向NULL
        head->next = NULL;
        return last;
    }
};