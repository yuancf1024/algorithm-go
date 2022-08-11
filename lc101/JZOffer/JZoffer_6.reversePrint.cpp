/**
 * @brief 剑指 Offer 06. 从尾到头打印链表
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 * 
示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 
限制：

0 <= 链表长度 <= 10000
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 使用栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* node = head;
        vector<int> res;
        while (node != NULL) {
            nodes.push(node);
            node = node->next;
        }
        while (!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
            res.push_back(node->val);
        }
        return res;
    }
};
/*
思路1：会改变原始链表的结构
先将链表翻转，再遍历打印。

思路2：使用栈
利用栈先进后出的特性，遍历整个链表，将节点加入到stack中；
然后从栈顶依次出栈。

思路3：递归
每访问到一个结点的时候，先递归输出它后面的结点，
再输出该结点自身，这样链表的输出结果就反过来了
*/

// 递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (!head) { // 递归函数返回条件
            return {};
        }
        vector<int> res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};