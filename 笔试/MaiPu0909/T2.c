/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * 20分
 * 请编程实现一个函数接口，将两个有序链表合并至同一个
 * 有序链表，链表节点均为降序排列。
 * 
 */

#include <stdio.h>

// 链表节点及List结构定义
struct ListNode {
    struct ListNode* prev;
    struct ListNode* next;
    int val;
};

struct List {
    struct ListNode* head; // 指向链表首节点，空指针表示链表无节点
    struct ListNode* tail; // 指向链表尾节点，空指针表示链表无节点
};

// TODO
int MergeList(struct List* list1, struct List* list2) { 
    // 统计list1长度
    int l1 = 0;
    struct ListNode* node1;

    node1 = list1->head;
    while (node1 != NULL) {
        l1++;
        node1 = node1->next;
    }

    // 统计list2长度
    int l2 = 0;
    struct ListNode* node2;

    node2 = list2->head;
    while (node2 != NULL) {
        l2++;
        node2 = node2->next;
    }
    
    // 合并不成功的情况
    if (l1 == 0 && l2 == 0){
        return -1;
    }

    // TODO核心代码
    // 思路：双指针，然后分别迭代比较
    struct ListNode *p, *tmp; // 创建哨兵节点和临时指针
    p = malloc(sizeof(struct ListNode));
    tmp = p;
    // struct ListNode* node1;
    // node1 = list1->head;
    // struct ListNode* node2;
    // node2 = list2->head;
    while (node1 && node2) {
        if (node1->val < node2->val) {
            tmp->next = node2; // 临时指针指向list2
            tmp = node2; // 赋值
            node2 = node2->next; // 后移
        }
        else {
            tmp->next = node1;
            tmp = node1;
            node1 = node1->next;
        }
    }
    // 处理list1和list2最后一个节点
    if (node1) {
        tmp->next = node1;
    }
    else {
        tmp->next = node2;
    }

    list1->head = p->next; // list1存的是链表合并结果
    list2->head = NULL; // list2为空
    return 0; 
}

int main() {
    struct ListNode* list1;

    return 0;
}