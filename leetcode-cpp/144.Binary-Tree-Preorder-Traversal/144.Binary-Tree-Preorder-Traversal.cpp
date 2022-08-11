/**
 * @file 144.Binary-Tree-Preorder-Traversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * leetcode-144. 二叉树的前序遍历
 * 
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

示例 5：
输入：root = [1,null,2]
输出：[1,2]

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

// 2022-08-10 复写 前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> vec;
        preorder(root, vec);
        return vec;
    }
    void preorder(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) {
            return;
        }
        vec.push_back(cur->val);
        preorder(cur->left, vec);
        preorder(cur->right, vec);
    }
};

// 参考代码随想录model 二叉树前序遍历 递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode* cur, vector<int>& vec) { // 1. 确定递归函数的参数和返回值
        if (cur == NULL) { // 2. 确定终止条件
            return;
        }
        vec.push_back(cur->val); // 3. 确定单层递归的逻辑：中左右
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
};

// 二叉树前序遍历 迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        st.push(root);
        while (!st.empty()) { // 栈不为空
            TreeNode* node = st.top();
            st.pop(); // 栈顶出栈
            res.push_back(node->val); // 中
            if (node->right) {
                st.push(node->right); // 右：空节点不入栈
            }
            if (node->left) {
                st.push(node->left); // 左：空节点不入栈
            }
        }
        return res;
    }
};
/*
前序遍历是中左右，每次先处理的是中间节点，那么先将根节点放入栈中，
然后将右孩子加入栈，再加入左孩子。
*/
