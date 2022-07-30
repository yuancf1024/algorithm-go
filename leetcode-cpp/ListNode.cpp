// 链表节点定义方式
struct ListNode {
    int val; // 节点上存储的元素
    ListNode *next; // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
    ListNode() : val(0), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}
