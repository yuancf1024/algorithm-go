/**
 * @file Reverse-LinkedList.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(-1), next(NULL) {}
};

// 反转链表
ListNode* reverse(ListNode* head) { 
    ListNode* pre = new ListNode();
    ListNode* cur = head;
    ListNode* tmp = head;

    while (cur != nullptr) {
        tmp = cur->next; 
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main() {
    // 创建链表
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    head = reverse(head);
    // 打印输出链表
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}