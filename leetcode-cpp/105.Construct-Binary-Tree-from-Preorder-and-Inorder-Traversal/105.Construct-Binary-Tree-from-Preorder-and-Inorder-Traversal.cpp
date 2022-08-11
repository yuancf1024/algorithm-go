/**
 * @file 105.Construct-Binary-Tree-from-Preorder-and-Inorder-Traversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-105.从前序与中序遍历序列构造二叉树
 * 
给定两个整数数组 preorder 和 inorder ，
其中 preorder 是二叉树的先序遍历， 
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]

示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列
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
/* 
前序：中左右
中序：左中右
根据前序和后序的特点，使用前序的第一个节点作为root开始构建二叉树，
然后从中序数组找到对应root节点对应的索引index，
拿左边的构建左子树，拿右边的构建右子树，其余部分依次递归解决。
 */
// 2022-08-11 复写 前序和中序序列构建二叉树
class Solution {
    int pre_idx;
    unordered_map<int, int> idxmap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_idx = 0;
        // 构造哈希表
        int index = 0;
        for (auto& val : inorder) {
            idxmap[val] = index;
            index++;
        }
        return helper(0, (int)inorder.size()-1, preorder, inorder);
    }

    TreeNode* helper(int in_left, int in_right, vector<int>& preorder, vector<int>& inorder) {
        // 递归结束条件
        if (in_left > in_right) {
            return nullptr;
        }
        int root_val = preorder[pre_idx];
        TreeNode* root = new TreeNode(root_val);

        // 根据root位置分成两棵子树
        int idx = idxmap[root_val];
        pre_idx++;
        root->left = helper(in_left, idx-1, preorder, inorder);
        root->right = helper(idx+1, in_right, preorder, inorder);
        return root;
    }
};