/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

/*
反转链表

*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * #例如 
#输入 {1.2,3,4,5}
#输出 {5,4,3,2,1}
     * @param head ListNode类 链表的头节点
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head) {
        // write code here
        ListNode* cur = head;
        ListNode* temp;
        ListNode* pre = nullptr;
        while (cur != nullptr) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};