/* 102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
（即逐层地，从左到右访问所有节点）。
For example: Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/

// 二叉树的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

// 借助队列实现层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) { 
        queue<TreeNode *> que; // 新建队列
        if (root != NULL) // 根节点不为空
            que.push(root); // 根节点入队
        vector<vector<int>> result; // 新建二维动态数组，存储整棵二叉树结果
        while (!que.empty()) { // 循环的结束条件：队列为空
            int size = que.size(); // 队列长度
            vector<int> vec; // 新建一维动态数组，存储二叉树每一层的节点
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); // 访问队首元素
                que.pop(); // 队首出队
                vec.push_back(node->val); // 动态数组添加遍历节点值
                if (node->left)
                    que.push(node->left); // 左子节点入队
                if (node->right)
                    que.push(node->right); // 右子节点入队
            }
            result.push_back(vec); // 遍历完一层节点的数组添加进二维数组
        }
        return result;
    }
};

// 递归法
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if (cur == nullptr)
            return;
        if (result.size() == depth)
            result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};