/**
 * @file 94.Binary-Tree-Inorder-Traversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-94. 二叉树的中序遍历
 * 
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
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

// 二叉树中序遍历 递归法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) {
            return;
        }
        // 中序遍历：左中右
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
};

// 二叉树的中序遍历 迭代
// 二叉树的中序遍历需要借助指针的遍历帮助访问节点，栈用来处理节点上的元素
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点入栈
                cur = cur->left; // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据
                st.pop();
                res.push_back(cur->val); // 中
                cur = cur->right; // 右
            }
        }
        return res;
    }
};