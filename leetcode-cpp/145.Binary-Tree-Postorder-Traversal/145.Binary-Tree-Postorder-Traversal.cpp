/**
 * @file 145.Binary-Tree-Postorder-Traversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-145.二叉树的后序遍历
 * 
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[3,2,1]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

提示：

树中节点的数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 
进阶：递归算法很简单，你可以通过迭代算法完成吗？

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

// 二叉树后序遍历 递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    // 后序遍历 : 左右中
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) {
            return;
        }
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
};

// 二叉树后序遍历 迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) { 
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL) {
            return res;
        }
        st.push(root);
        // 后序遍历：左右中 reverse -> 中右左
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val); // 中
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }

        // 翻转res
        for (int i = 0; i < res.size()/2; i++) {
            swap(res[i], res[res.size() - 1]);
        }
        // reverse(res.begin(), res.end()); // 调用库函数翻转
        return res;
    }
};