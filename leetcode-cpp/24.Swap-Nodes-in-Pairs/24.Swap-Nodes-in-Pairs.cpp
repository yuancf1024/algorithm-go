/* 24. Swap Nodes in Pairs
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
 
提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

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

// 参考代码随想录
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头节点
        dummyHead->next = head; // 将虚拟头节点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next; // 步骤1
            cur->next->next = tmp; // 步骤2
            cur->next->next->next = tmp1; // 步骤3

            cur = cur->next->next; // 移动两位，准备下一轮交换
        }
        return dummyHead->next;
    }
};

/*
思路：

这道题目正常模拟就可以了。

建议使用虚拟头结点，这样会方便很多，要不然每次针对头结点
（没有前一个指针指向头结点），还要单独处理。

接下来就是交换相邻两个元素了，此时一定要画图，不画图，操作多个指针很容易乱，
而且要操作的先后顺序

初始时，cur指向虚拟头结点，然后进行如下三步：

cur->1->2->3->4->

1. cur->2
2. 2->1
3. 1->3

操作之后，链表如下：
cur->2->1->3->4->

*/