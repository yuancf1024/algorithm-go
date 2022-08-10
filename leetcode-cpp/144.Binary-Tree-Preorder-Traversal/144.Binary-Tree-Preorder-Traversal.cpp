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

// 参考代码随想录model
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
        vec.push_back(cur->val); // 3. 确定单层递归的逻辑：
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
};