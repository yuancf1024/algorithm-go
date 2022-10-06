/**
 * @file 143.Reorder-List.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * leetcode-143.重排链表
 * 
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，
而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]

示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
 
提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
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
#include <bits/stdc++.h>

using namespace std;

// 链表节点定义方式
struct ListNode {
    int val; // 节点上存储的元素
    ListNode *next; // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
    ListNode() : val(0), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 方法一：线性表
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode*> vec;
        ListNode* node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};


// 方法2：寻找链表中间节点+链表逆序+合并链表
class Solution {
public:
    // 重排链表
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head); // 1. 寻找链表中间节点
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2); // 2. 链表逆序
        mergeList(l1, l2); // 3. 合并链表
    }

    // 寻找链表中节点
    ListNode* middleNode(ListNode* head) { 
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 反转链表
    ListNode* reverseList(ListNode* head) { 
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }

    // 合并链表
    void mergeList(ListNode* l1, ListNode* l2) { 
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};



/*
思路：方法一：线性表
因为链表不支持下标访问，所以我们无法随机访问链表中任意位置的元素。

因此比较容易想到的一个方法是，
我们利用线性表存储该链表，
然后利用线性表可以下标访问的特点，
直接按顺序访问指定元素，重建该链表即可。
复杂度分析

时间复杂度：O(N)，其中N是链表中的节点数。

空间复杂度：O(N)，其中N是链表中的节点数。
主要为线性表的开销。

方法二：寻找链表中点 + 链表逆序 + 合并链表
注意到目标链表即为将原链表的左半端
和反转后的右半端合并后的结果。

这样我们的任务即可划分为三步：

1. 找到原链表的中点（参考「876. 链表的中间结点」）。
我们可以使用快慢指针来O(N)地找到链表的中间节点。

2. 将原链表的右半端反转（参考「206. 反转链表」）。
我们可以使用迭代法实现链表的反转。

3. 将原链表的两端合并。

因为两链表长度相差不超过1，因此直接合并即可。

复杂度分析
时间复杂度：O(N)，其中N是链表中的节点数。
空间复杂度：O(1)。

*/

