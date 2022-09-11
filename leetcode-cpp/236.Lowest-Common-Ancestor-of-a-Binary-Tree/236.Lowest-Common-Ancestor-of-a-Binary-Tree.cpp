/**
 * @file 236.Lowest-Common-Ancestor-of-a-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * leetcode-236. 二叉树的最近公共祖先
 * 
 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。
因为根据定义最近公共祖先节点可以为节点本身。

示例 3：
输入：root = [1,2], p = 1, q = 2
输出：1
 
提示：

树中节点数目在范围 [2, 10^5] 内。
-10^9 <= Node.val <= 10^9
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 方法一：递归
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
    // 辅函数
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson ||rson))) {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
};

// 递归的一种非常巧妙的方法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        return root;
    }
};

/*
方法一：递归
思路和算法

我们递归遍历整棵二叉树，定义 f_x表示x节点的子树中是否包含p节点或q节点，
如果包含为 true，否则为 false。
那么符合条件的最近公共祖先x一定满足如下条件：

(f_lson && f_rson) || ((x = p || x = q) && (f_lson || f_rson))

其中lson和rson分别代表x节点的左孩子和右孩子。
初看可能会感觉条件判断有点复杂，
我们来一条条看，f_lson&& f_rson说明左子树和右子树均包含p节点或q节点，
如果左子树包含的是p节点，那么右子树只能包含q节点，
反之亦然，因为p节点和q节点都是不同且唯一的节点，
因此如果满足这个判断条件即可说明x就是我们要找的最近公共祖先。

再来看第二条判断条件，这个判断条件即是考虑了x恰好是p节点或q节点
且它的左子树或右子树有一个包含了另一个节点的情况，
因此如果满足这个判断条件亦可说明x就是我们要找的最近公共祖先。

你可能会疑惑这样找出来的公共祖先深度是否是最大的。
其实是最大的，因为我们是自底向上从叶子节点开始更新的，
所以在所有满足条件的公共祖先中一定是深度最大的祖先先被访问到，
且由于f_x本身的定义很巧妙，在找到最近公共祖先x以后，
f_x按定义被设置为true ，即假定了这个子树中只有一个p节点或q节点，
因此其他公共祖先不会再被判断为符合条件。

下图展示了一个示例，搜索树中两个节点 9 和 11 的最近公共祖先。

复杂度分析

时间复杂度：O(N)，其中N是二叉树的节点数。
二叉树的所有节点有且只会被访问一次，因此时间复杂度为O(N)。

空间复杂度：O(N) ，其中N是二叉树的节点数。
递归调用的栈深度取决于二叉树的高度，二叉树最坏情况下为一条链，
此时高度为N，因此空间复杂度为O(N)。
*/


/*
方法二：存储父节点
思路
我们可以用哈希表存储所有节点的父节点，
然后我们就可以利用节点的父节点信息从 p 结点开始不断往上跳，
并记录已经访问过的节点，再从 q 节点开始不断往上跳，
如果碰到已经访问过的节点，那么这个节点就是我们要找的最近公共祖先。

算法

1. 从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
2. 从 p 节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
3. 同样，我们再从 q 节点开始不断往它的祖先移动，
如果有祖先已经被访问过，即意味着这是 p 和 q 的深度最深的公共祖先，
即 LCA 节点。

复杂度分析

时间复杂度：O(N)，其中N是二叉树的节点数。
二叉树的所有节点有且只会被访问一次，
从p和q节点往上跳经过的祖先节点个数不会超过N，因此总的时间复杂度为O(N)。

空间复杂度：O(N)，其中N是二叉树的节点数。
递归调用的栈深度取决于二叉树的高度，二叉树最坏情况下为一条链，
此时高度为N，因此空间复杂度为O(N)，
哈希表存储每个节点的父节点也需要O(N) 的空间复杂度，
因此最后总的空间复杂度为O(N)。

*/ 
// 方法二：存储父节点
class Solution1 {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) {
                return q;
            }
            q = fa[q->val];
        }
        return nullptr;
    }

    // 辅函数
    void dfs(TreeNode* root) {
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
};