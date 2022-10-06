/**
 * @file 21.Merge-Two-Sorted-Lists.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * leetcode-21. 合并两个有序链表
 * 
将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
 
提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
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


// 递归实现
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

/**
 * @brief 参考leetcode题解
 * 方法一：递归
思路

我们可以如下递归地定义两个链表里的 merge 操作（
忽略边界情况，比如空链表等）：

list1[0]+merge(list1[1:],list2) list1[0]<list2[0]
list2[0]+merge(list1,list2[1:]) otherwise
​

也就是说，两个链表头部值较小的一个节点
与剩下元素的 merge 操作结果合并。

算法

我们直接将以上递归过程建模，同时需要考虑边界情况。

如果 l1 或者 l2 一开始就是空链表 ，
那么没有任何操作需要合并，
所以我们只需要返回非空链表。
否则，我们要判断l1和l2哪一个链表的头节点的值更小，
然后递归地决定下一个添加到结果里的节点。
如果两个链表有一个为空，递归结束。

复杂度分析
时间复杂度：O(n+m)，其中n和m分别为两个链表的长度。
因为每次调用递归都会去掉 l1 或者 l2 的头节点
（直到至少有一个链表为空），函数mergeTwoList
至多只会递归调用每个节点一次。
因此，时间复杂度取决于合并后的链表长度，即O(n+m)。

空间复杂度：O(n+m)，其中n和m分别为两个链表的长度。
递归调用 mergeTwoLists 函数时需要消耗栈空间，
栈空间的大小取决于递归调用的深度。
结束递归调用时mergeTwoLists函数最多调用n+m 次，
因此空间复杂度为O(n+m)。

 */