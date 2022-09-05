/**
 * @file 958.Check-Completeness-of-a-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-05
 * 
 * @copyright Copyright (c) 2022
 * leetcode-958.二叉树的完全性检验
 * 
给定一个二叉树的 root ，确定它是否是一个 完全二叉树 。

在一个 完全二叉树 中，除了最后一个关卡外，
所有关卡都是完全被填满的，并且最后一个关卡中的所有节点都是尽可能靠左的。
它可以包含 1 到 2h 节点之间的最后一级 h 。

示例 1：
输入：root = [1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），
且最后一层中的所有结点（{4,5,6}）都尽可能地向左。

示例 2：
输入：root = [1,2,3,4,5,null,7]
输出：false
解释：值为 7 的结点没有尽可能靠向左侧。
 
提示：

树的结点数在范围  [1, 100] 内。
1 <= Node.val <= 1000
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

// 非常巧妙的解法——层序遍历，同层若在非空的节点前有空，则不满足
class Solution {
public:
    bool isCompleteTree(TreeNode* root) { 
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) { // 核心思路：层序遍历，只要出现过空节点，就不能再出现任何非空节点
                flag = true;
                continue;
            }
            if (flag) {
                return false;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};