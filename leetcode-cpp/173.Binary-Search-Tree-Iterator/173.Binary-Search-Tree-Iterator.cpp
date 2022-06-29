/* 173. 二叉搜索树迭代器
实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。
BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于
 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，
所以对 next() 的首次调用将返回 BST 中的最小元素。

你可以假设 next() 调用总是有效的，也就是说，
当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
根据二叉搜索树的性质，不难发现，原问题等价于对二叉搜索树进行中序遍历

方法一：扁平化
我们可以直接对二叉搜索树做一次完全的递归遍历，获取中序遍历的全部结果并保存在数组中。
随后，我们利用得到的数组本身来实现迭代器。

复杂度分析
- 时间复杂度：初始化需要 O(n) 的时间，其中 n 为树中节点的数量。
随后每次调用只需要 O(1) 的时间。
- 空间复杂度：O(n)，因为需要保存中序遍历的全部结果。
*/

class BSTIterator {
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> arr;
    int idx;

public:
    BSTIterator(TreeNode* root): idx(0), arr(inorderTraversal(root)) {
        
    }

    int next() { return arr[idx++]; }

    bool hasNext() { return (idx < arr.size()); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */