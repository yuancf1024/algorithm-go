/**
 * @file 662.Maximum-Width-of-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * leetcode-662.二叉树最大宽度
 * 
给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

树的 最大宽度 是所有层中最大的 宽度 。

每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。
将这个二叉树视作与满二叉树结构相同，
两端点间会出现一些延伸到这一层的 null 节点，
这些 null 节点也计入长度。

题目数据保证答案将会在  32 位 带符号整数范围内。

示例 1：
输入：root = [1,3,2,5,3,null,9]
输出：4
解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。

示例 2：
输入：root = [1,3,2,5,null,null,9,6,null,7]
输出：7
解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。

示例 3：
输入：root = [1,3,2,5]
输出：2
解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
 
提示：

树中节点的数目范围是 [1, 3000]
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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 方法一：广度优先搜索
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) { 
        unsigned long long res = 1;
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.emplace_back(root, 1L);
        while (!arr.empty()) {
            vector<pair<TreeNode *, unsigned long long>> tmp;
            for (auto &[node, index] : arr) {
                if (node->left) {
                    tmp.emplace_back(node->left, index * 2);
                }
                if (node->right) {
                    tmp.emplace_back(node->right, index * 2 + 1);
                }
            }
            res = max(res, arr.back().second - arr[0].second + 1);
            arr = move(tmp); // 减少资源创建和释放
        }
        return res;
    }
};

// 方法二：深度优先搜索
class Solution {
    using ULL = unsigned long long;

public:
    int widthOfBinaryTree(TreeNode *root) { 
        unordered_map<int, ULL> levelMin;
        function<ULL(TreeNode *, int, ULL)> dfs = [&](TreeNode *node, int depth,
                                                      ULL index) -> ULL {
            if (node == nullptr) {
                return 0LL;
            }
            if (!levelMin.count(depth)) {
                levelMin[depth] = index; // 每一层最先访问到的节点会是最左边的节点，即每一层编号的最小值
            }
            return max({index - levelMin[depth] + 1LL,
                        dfs(node->left, depth + 1, index * 2),
                        dfs(node->right, depth + 1, index * 2 + 1)});
        };
        return dfs(root, 1, 1LL);
    }
};

/**
 * @brief 参考leetcode官方题解
 * 
 * 方法一：广度优先搜索
思路

此题求二叉树所有层的最大宽度，比较直观的方法是求出每一层的宽度，
然后求出最大值。求每一层的宽度时，
因为两端点间的null节点也需要计入宽度，
因此可以对节点进行编号。一个编号为index的左子节点的编号记为2×index，
右子节点的编号记为2×index+1，
计算每层宽度时，用每层节点的最大编号减去最小编号再加1 即为宽度。

遍历节点时，可以用广度优先搜索来遍历每一层的节点，并求出最大值。

复杂度分析

时间复杂度：O(n)，其中n是二叉树的节点个数。
需要遍历所有节点。

空间复杂度：O(n)。广度优先搜索的空间复杂度最多为O(n)。

方法二：深度优先搜索
思路

仍然按照上述方法编号，可以用深度优先搜索来遍历。
遍历时如果是先访问左子节点，再访问右子节点，
每一层最先访问到的节点会是最左边的节点，即每一层编号的最小值，
需要记录下来进行后续的比较。

一次深度优先搜索中，需要当前节点到当前行最左边节点的宽度，
以及对子节点进行深度优先搜索，求出最大宽度，并返回最大宽度。

复杂度分析

时间复杂度：O(n)，其中n是二叉树的节点个数。
需要遍历所有节点。

空间复杂度：O(n)。递归的深度最多为O(n)。


 */