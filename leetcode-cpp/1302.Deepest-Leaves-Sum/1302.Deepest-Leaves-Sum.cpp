/**
 * @file 1302.Deepest-Leaves-Sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1302.层数最深叶子节点的和
 * 
给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。

示例 1：
输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15

示例 2：
输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：19
 
提示：

树中节点数目在范围 [1, 104] 之间。
1 <= Node.val <= 100

 */

/*
自己层序遍历的思路，最后求和这里实际上做麻烦了；
因为while层序的最后一层遍历，直接记录求和结果即可，会自动覆盖前面层的值。
*/

/*
思路：二叉树层序遍历的变体
层序遍历二叉树，只记录最深那一层叶子节点的和即可。
*/
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            vector<int> vec;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(vec);
        }
        int n = res.size(), m = res[n-1].size(); // 通常一般喜欢将这里设置为res[0]，但是这里要求最后一层的和，那么显然层索引为n-1
        for (int i = 0; i < m; ++i) {
            sum += res[n-1][i];
        }
        return sum;
    }
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

// 方法一：深度优先搜索
class Solution {
private:
    int maxLevel = -1;
    int sum = 0;
public:
    int deepestLeavesSum(TreeNode* root) { 
        dfs(root, 0);
        return sum;
    }

    // 辅函数
    void dfs(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }
        if (level > maxLevel) {
            maxLevel = level;
            sum = node->val;
        } else if (level == maxLevel) {
            sum += node->val;
        }
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};

/**
 * @brief
 * 方法一：深度优先搜索
由于层数最深的节点一定是叶节点，因此只要找到所有层数最深的节点并计算节点值之和即可。

可以使用深度优先搜索实现。从根节点开始遍历整个二叉树，
遍历每个节点时需要记录该节点的层数，规定根节点在第0 层。
遍历过程中维护最大层数与最深节点之和。

对于每个非空节点，执行如下操作。

1. 判断当前节点的层数与最大层数的关系：

    - 如果当前节点的层数大于最大层数，则之前遍历到的节点都不是层数最深的节点，
    因此用当前节点的层数更新最大层数，并将最深节点之和更新为当前节点值；

    - 如果当前节点的层数等于最大层数，则将当前节点值加到最深节点之和。

2. 对当前节点的左右子节点继续深度优先搜索。

遍历结束之后，即可得到层数最深叶子节点的和。

复杂度分析
时间复杂度：O(n)，其中n 是二叉树的节点数。
深度优先搜索需要遍历每个节点一次。

空间复杂度：O(n)，其中 n 是二叉树的节点数。
空间复杂度主要取决于递归调用栈的深度，为二叉树的深度，
最坏情况下二叉树的深度是O(n)。
 */

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) { 
        int sum = 0;
        queue<TreeNode*> que;
        que.emplace(root);
        while (!que.empty()) {
            sum = 0;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) {
                    que.emplace(node->left);
                }
                if (node->right) {
                    que.emplace(node->right);
                }
            }
        }
        return sum;
    }
};

/**
 * @brief
 *方法二：广度优先搜索
计算最深节点之和也可以使用广度优先搜索实现。
使用广度优先搜索时，对二叉树层序遍历，此时不需要维护最大层数，
只需要确保每一轮遍历的节点是同一层的全部节点，
则最后一轮遍历的节点是全部最深节点。

初始时，将根节点加入队列，此时队列中只有一个节点，是同一层的全部节点。
每一轮遍历时，首先得到队列中的节点个数 size，从队列中取出size 个节点，
则这size 个节点是同一层的全部节点，记为第x 层。
遍历时，第x 层的每个节点的子节点都在第 x+1 层，将子节点加入队列，
则该轮遍历结束之后，第x 层的节点全部从队列中取出，
第x+1 层的节点全部加入队列，队列中的节点是同一层的全部节点。
因此该方法可以确保每一轮遍历的节点是同一层的全部节点。

遍历过程中，分别计算每一层的节点之和，
则遍历结束时的节点之和即为层数最深叶子节点的和。

复杂度分析

时间复杂度：O(n)，其中n 是二叉树的节点数。
广度优先搜索需要遍历每个节点一次。

空间复杂度：O(n)，其中n 是二叉树的节点数。
空间复杂度主要取决于队列空间，队列中的节点个数不超过n 个。

 */
