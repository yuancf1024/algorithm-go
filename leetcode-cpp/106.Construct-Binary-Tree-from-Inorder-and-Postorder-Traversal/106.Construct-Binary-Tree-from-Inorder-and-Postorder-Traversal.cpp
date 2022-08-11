/**
 * @file 106.Construct-Binary-Tree-from-Inorder-and-Postorder-Traversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-106.从中序与后序遍历序列构造二叉树
 * 
给定两个整数数组 inorder 和 postorder ，
其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，
请你构造并返回这颗 二叉树 。

示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]

示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]

提示:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历
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

// 方法一：递归
class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立(元素,下标)键值对的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }

    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder) {
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return nullptr;
        }

        // 选择post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        // 根据root所在位置分成左右两棵子树
        int index = idx_map[root_val]; // 元素，下标

        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
};

/**
 * @brief 参考leetcode题解
 * 

方法一：递归
思路
首先解决这道题我们需要明确给定一棵二叉树，我们是如何对其进行中序遍历与后序遍历的：

- 中序遍历的顺序是每次遍历左孩子，再遍历根节点，最后遍历右孩子。
- 后序遍历的顺序是每次遍历左孩子，再遍历右孩子，最后遍历根节点。
写成代码的形式即：
// 中序遍历
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
// 后序遍历
void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->val);
}

因此根据上文所述，我们可以发现后序遍历的数组最后一个元素代表的即为根节点。
知道这个性质后，我们可以利用已知的根节点信息在中序遍历的数组中找到根节点
所在的下标，然后根据其将中序遍历的数组分成左右两部分，左边部分即左子树，
右边部分为右子树，针对每个部分可以用同样的方法继续递归下去构造。

*算法

为了高效查找根节点元素在中序遍历数组中的下标，
我们选择创建哈希表来存储中序序列，即建立一个（元素，下标）键值对的哈希表。

定义递归函数 helper(in_left, in_right) 表示
当前递归到中序序列中当前子树的左右边界，递归入口为helper(0, n - 1) ：

- 如果 in_left > in_right，说明子树为空，返回空节点。
- 选择后序遍历的最后一个节点作为根节点。
- 利用哈希表 O(1) 查询当根节点在中序遍历中下标为 index。
从 in_left 到 index - 1 属于左子树，
从 index + 1 到 in_right 属于右子树。
- 根据后序遍历逻辑，递归创建右子树 helper(index + 1, in_right) 
和左子树 helper(in_left, index - 1)。
注意这里有需要先创建右子树，再创建左子树的依赖关系。
可以理解为在后序遍历的数组中整个数组是先存储左子树的节点，
再存储右子树的节点，最后存储根节点，
如果按每次选择「后序遍历的最后一个节点」为根节点，
则先被构造出来的应该为右子树。
- 返回根节点 root。

复杂度分析
时间复杂度：O(n)，其中 n 是树中的节点个数。

空间复杂度：O(n)。我们需要使用 O(n) 的空间存储哈希表，
以及 O(h)（其中 h 是树的高度）的空间表示递归时栈空间。
这里 h<n，所以总空间复杂度为 )O(n)。

方法二：迭代法
迭代法不是很好理解，因此本题就理解递归来解决。
 */