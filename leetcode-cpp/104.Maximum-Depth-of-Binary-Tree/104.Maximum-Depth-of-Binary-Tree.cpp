/**
 * @file 104.Maximum-Depth-of-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * leetcode-104.二叉树的最大深度
 * 
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 */

// 递归: 后序遍历（左右中）来计算树的高度
class Solution {
public:
    int maxDepth(TreeNode* root) { 
        return getDepth(root);
    }

    // 辅函数
    int getDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = getDepth(node->left); // 左
        int rightDepth = getDepth(node->right); // 右
        int depth = 1 + max(leftDepth, rightDepth); // 中
        return depth;
    }
};

// 递归(后序遍历)的精简版
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


// 递归(前序遍历) (充分表现出求深度回溯的过程)
class Solution {
public:
    int result;
    int maxDepth(TreeNode* root) { 
        result = 0;
        if (root == NULL) {
            return result;
        }
        getDepth(root, 1);
        return result;
    }

    // 辅函数
    void getDepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result; // 中

        if (node->left == NULL && node->right == NULL) {
            return;
        }

        if (node->left) { // 左
            depth++; // 深度+1
            getDepth(node->left, depth);
            depth--; // 回溯，深度-1
        }

        if (node->right) { // 右
            depth++; // 深度+1
            getDepth(node->right, depth);
            depth--; // 回溯，深度-1
        }
        return;
    }
};

// 迭代法 层序遍历记录深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++; // 记录深度
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return depth;
    }
};


/**
 * @brief 参考代码随想录
 * 
 * 递归法
本题可以使用前序（中左右），也可以使用后序遍历（左右中），
使用前序求的就是深度，使用后序求的是高度。

而根节点的高度就是二叉树的最大深度，
所以本题中我们通过后序求的根节点高度来求的二叉树最大深度。

这一点其实是很多同学没有想清楚的，很多题解同样没有讲清楚。

我先用后序遍历（左右中）来计算树的高度。

1. 确定递归函数的参数和返回值：
参数就是传入树的根节点，返回就返回这棵树的深度，所以返回值为int类型。
代码如下：
int getdepth(treenode* node)

2. 确定终止条件：如果为空节点的话，就返回0，表示高度为0。
代码如下：
if (node == NULL) return 0;

3. 确定单层递归的逻辑：
先求它的左子树的深度，再求的右子树的深度，
最后取左右深度最大的数值 再+1 （加1是因为算上当前中间节点）
就是目前节点为根节点的树的深度。
代码如下：
int leftdepth = getdepth(node->left);       // 左
int rightdepth = getdepth(node->right);     // 右
int depth = 1 + max(leftdepth, rightdepth); // 中
return depth;


#迭代法
使用迭代法的话，使用层序遍历是最为合适的，因为最大的深度就是二叉树的层数，
和层序遍历的方式极其吻合。

在二叉树中，一层一层的来遍历二叉树，记录一下遍历的层数就是二叉树的深度，
如图所示：

所以这道题的迭代法就是一道模板题，可以使用二叉树层序遍历的模板来解决的。

 */