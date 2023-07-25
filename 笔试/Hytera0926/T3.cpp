/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * 链表 20分
 * 
 * 随机输入整型数据，创建2个有序链表(从小到大)
 * 利用递归的方式合并两个链表，
 * 行成新的链表并打印出来。
 */

#include <bits/stdc++.h>

using namespace std;

struct LinkList {
    int val;
    LinkList* next;
    LinkList(int x) : val(x), next(NULL) {}
    LinkList() : val(0), next(NULL) {}
    LinkList(int x, LinkList* next) : val(x), next(next) {}
};

LinkList* Merge(LinkList* pHead1, LinkList* pHead2) {
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    if (pHead1->val < pHead2->val) {
        pHead1->next = Merge(pHead1->next, pHead2);
        return pHead1;
    }
    else {
        pHead2->next = Merge(pHead1, pHead2->next);
        return pHead2;
    }
    return NULL;
}

int main() {
    int t;
    vector<int> nums1;
    vector<int> nums2;
    while (cin >> t) {
        nums1.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }
    while (cin >> t) {
        nums2.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }

    LinkList* pHead1 = new LinkList(nums1[0]);
    LinkList* cur = pHead1;

    for (int i = 1; i < nums1.size(); ++i) {
        LinkList* node = new LinkList(nums1[i]);
        cur->next = node;
        cur = cur->next;
    }
    cur->next = NULL;

    LinkList* pHead2 = new LinkList(nums2[0]);
    LinkList* cur2 = pHead2;

    for (int i = 1; i < nums2.size(); ++i) {
        LinkList* node = new LinkList(nums2[i]);
        cur2->next = node;
        cur2 = cur2->next;
    }
    cur2->next = NULL;

    LinkList* root = Merge(pHead1, pHead2);

    // 打印链表
    while (root != NULL) {
        cout << root->val << " ";
        root = root->next;
    }

    // 核心代码
    // 创建链表

    // 合并

    // 遍历print
    // for (auto& x : nums1) {
    //     cout << x << " ";
    // }

    // for (auto& x : nums2) {
    //     cout << x << " ";
    // }

    return 0;
}