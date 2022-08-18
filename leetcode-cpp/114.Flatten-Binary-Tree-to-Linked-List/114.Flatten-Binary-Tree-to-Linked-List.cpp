/**
 * @file 114.Flatten-Binary-Tree-to-Linked-List.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * leetcode-114.二叉树展开为链表
 * 
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，
其中 right 子指针指向链表中下一个结点，
而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
 
示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [0]
输出：[0]
 
提示：

树中结点数在范围 [0, 2000] 内
-100 <= Node.val <= 100

进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 方法一：前序遍历 递归实现
class Solution {
public:
    void flatten(TreeNode* root) { 
        vector<TreeNode*> list;
        preorderTraversal(root, list);
        int n = list.size();
        for (int i = 1; i < n; ++i) {
            TreeNode *prev = list.at(i - 1), *cur = list.at(i);
            prev->left = nullptr;
            prev->right = cur;
        }
    }
    void preorderTraversal(TreeNode* root, vector<TreeNode*> &list) {
        if (root != nullptr) {
            list.push_back(root);
            preorderTraversal(root->left, list);
            preorderTraversal(root->right, list);
        }
    }
};

// 方法一：前序遍历 迭代实现 借助栈
class Solution {
public:
    void flatten(TreeNode* root) { 
        vector<TreeNode*> list;
        stack<TreeNode*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            list.push_back(node); // 中
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        int n = list.size();
        for (int i = 1; i < n; ++i) {
            TreeNode *prev = list.at(i - 1), *cur = list.at(i);
            prev->left = nullptr;
            prev->right = cur;
        }
    }
};

// 方法二：前序遍历和展开同步进行
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        auto stk = stack<TreeNode*>();
        stk.push(root);
        TreeNode* prev = nullptr;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (prev != nullptr) {
                prev->left = nullptr;
                prev->right = cur;
            }
            // TreeNode *left = cur->left, *right = cur->right;
            if (cur->right != nullptr) {
                stk.push(cur->right);
            }
            if (cur->left != nullptr) {
                stk.push(cur->left);
            }
            prev = cur;
        }
    }
};

// 方法三：寻找前驱节点 非常巧妙地方法
class Solution {
public:
    void flatten(TreeNode* root) { 
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) { // 对于当前节点，如果其左子节点不为空
                auto next = cur->left; // 则在其左子树中找到最右边的节点
                auto predecessor = next;
                while (predecessor->right != nullptr) { // cur左子树中最右边的节点
                    predecessor = predecessor->right;
                }
                predecessor->right = cur->right; // 将当前节点的右子节点赋给前驱节点的右子节点
                cur->left = nullptr; // 将当前节点的左子节点设为空
                cur->right = next; // 将当前节点的左子节点赋给当前节点的右子节点
            }
            cur = cur->right; // 对当前节点处理结束后，继续处理链表中的下一个节点，直到所有节点都处理结束。
        }
     }
};


/**
 * @brief 
 * 方法一：前序遍历
将二叉树展开为单链表之后，单链表中的节点顺序即为二叉树的前序遍历
访问各节点的顺序。因此，可以对二叉树进行前序遍历，获得各节点被访问到的顺序。
由于将二叉树展开为链表之后会破坏二叉树的结构，因此在前序遍历结束之后
更新每个节点的左右子节点的信息，将二叉树展开为单链表。

对二叉树的前序遍历不熟悉的读者请自行练习「144. 二叉树的前序遍历」。

前序遍历可以通过递归或者迭代的方式实现。
以下代码通过递归实现前序遍历。

复杂度分析
时间复杂度：O(n)，其中n 是二叉树的节点数。
前序遍历的时间复杂度是O(n)，前序遍历之后，
需要对每个节点更新左右子节点的信息，时间复杂度也是O(n)。

空间复杂度：O(n)，其中n 是二叉树的节点数。
空间复杂度取决于栈（递归调用栈或者迭代中显性使用的栈）和
存储前序遍历结果的列表的大小，栈内的元素个数不会超过n，
前序遍历列表中的元素个数是n。


方法二：前序遍历和展开同步进行

使用方法一的前序遍历，由于将节点展开之后会破坏二叉树的结构
而丢失子节点的信息，因此前序遍历和展开为单链表分成了两步。
能不能在不丢失子节点的信息的情况下，将前序遍历和展开为单链表同时进行？

之所以会在破坏二叉树的结构之后丢失子节点的信息，
是因为在对左子树进行遍历时，没有存储右子节点的信息，
在遍历完左子树之后才获得右子节点的信息。

只要对前序遍历进行修改，在遍历左子树之前就获得左右子节点的信息，
并存入栈内，子节点的信息就不会丢失，就可以将前序遍历和展开为单链表同时进行。

该做法不适用于递归实现的前序遍历，只适用于迭代实现的前序遍历。
修改后的前序遍历的具体做法是，每次从栈内弹出一个节点作为当前访问的节点，
获得该节点的子节点，如果子节点不为空，
则依次将右子节点和左子节点压入栈内（注意入栈顺序）。

展开为单链表的做法是，维护上一个访问的节点 prev，每次访问一个节点时，
令当前访问的节点为 curr，将 prev 的左子节点设为 null 以及将
 prev 的右子节点设为 curr，然后将 curr 赋值给 prev，
 进入下一个节点的访问，直到遍历结束。
 
 需要注意的是，初始时 prev 为 null，
 只有在 prev 不为 null 时才能对 prev 的左右子节点进行更新。


复杂度分析

时间复杂度：O(n)，其中n 是二叉树的节点数。
前序遍历的时间复杂度是O(n)，前序遍历的同时对每个节点更新左右子节点的信息，
更新子节点信息的时间复杂度是O(1)，因此总时间复杂度是O(n)。

空间复杂度：O(n)，其中n 是二叉树的节点数。
空间复杂度取决于栈的大小，栈内的元素个数不会超过n。


方法三：寻找前驱节点

前两种方法都借助前序遍历，前序遍历过程中需要使用栈存储节点。
有没有空间复杂度是O(1) 的做法呢？

注意到前序遍历访问各节点的顺序是根节点、左子树、右子树。
如果一个节点的左子节点为空，则该节点不需要进行展开操作。
如果一个节点的左子节点不为空，则该节点的左子树中的最后一个节点被访问之后，
该节点的右子节点被访问。

该节点的左子树中最后一个被访问的节点是左子树中的最右边的节点，
也是该节点的前驱节点。因此，问题转化成寻找当前节点的前驱节点。

具体做法是，对于当前节点，如果其左子节点不为空，
则在其左子树中找到最右边的节点，作为前驱节点，
将当前节点的右子节点赋给前驱节点的右子节点，
然后将当前节点的左子节点赋给当前节点的右子节点，
并将当前节点的左子节点设为空。对当前节点处理结束后，
继续处理链表中的下一个节点，直到所有节点都处理结束。
动画参考: 方法三 https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/

复杂度分析

时间复杂度：O(n)，其中n 是二叉树的节点数。
展开为单链表的过程中，需要对每个节点访问一次，在寻找前驱节点的过程中，
每个节点最多被额外访问一次。

空间复杂度：O(1)。

 */