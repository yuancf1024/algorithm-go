/**
 * @file 979.Distribute-Coins-in-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-979.在二叉树中分配硬币

 * @version 0.1
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>

using namespace std;

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

给你一个有n个结点的二叉树的根结点root ，
其中树中每个结点node都对应有node.val枚硬币。
整棵树上一共有n枚硬币。

在一次移动中，我们可以选择两个相邻的结点，
然后将一枚硬币从其中一个结点移动到另一个结点。
移动可以是从父结点到子结点，或者从子结点移动到父结点。

返回使每个结点上只有一枚硬币所需的最少移动次数。

示例 1：

输入：root = [3,0,0]
输出：2
解释：一枚硬币从根结点移动到左子结点，
一枚硬币从根结点移动到右子结点。

示例 2：
输入：root = [0,3,0]
输出：3
解释：将两枚硬币从根结点的左子结点移动到根结点
（两次移动）。然后，将一枚硬币从根结点移动到右子结点。

提示：
    树中节点的数目为n
    1 <= n <= 100
    0 <= Node.val <= n
所有 Node.val 的值之和是n

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int move = 0;

        function<int(const TreeNode *)> dfs = [&](const TreeNode *root) -> int {
            int moveleft = 0;
            int moveright = 0;
            if (root == nullptr) {
                return 0;
            }
            if (root -> left) {
                moveleft = dfs(root->left);
            }
            if (root -> right) {
                moveright = dfs(root->right);
            }
            move += abs(moveleft) + abs(moveright);
            return moveleft + moveright + root->val - 1;
        };

        dfs(root);
        return move;
    }
};

int main() {

    return 0;
}

/**
 * @brief leetcode官方题解
 * 
方法一：深度优先搜索

思路与算法

题目中要求求出移动步数，设 dfs(a)表示若使得
以a为根节点的子树满足每个节点均只有一个金币时，
节点a的父节点需要从节点a「拿走」的金币数目，
我们可以定义如下：
    如果dfs(a)>0，则表示节点a需要向a的父节点移动dfs(a)个金币；
    如果dfs(a)=0，则表示节点a与a的父节点之间不需要移动；
    如果dfs(a)<0，则表示节点a的父节点需要向a移动∣dfs(a)∣个金币；
综上可知道无论哪个方向移动，节点a与其父节点之间的金币移动此时一定为∣dfs(a)∣；
设 count(a)表示当以节点a为根节点的子树中含有的二叉树节点数目，
设 sum(a)表示以节点a为根节点的子树中含有的二叉树节点的值之和，
此时可以知道 dfs(a)=sum(a)−count(a)，则可以按照以下几种情形分析：

    假设 sum(a)>count(a)，即此时子树中金币总数量大于节点的总数量，
        此时需要向a的父节点移动 sum(a)−count(a)个金币；
    假设 sum(a)<count(a)，即此时子树中金币总数量小于节点的总数量，
        此时需要从a的父节点需要移动 count(a)−sum(a)个金币；
    假设 sum(a)=count(a)，即此时子树中金币总数量等于节点的总数量，
        此时a的父节点与a之间不需要移动即可，最优策略一定是a的
        左子树与右子树之间的金币互相移动即可，此处不再证明；

假设当前节点为 node，设 val(node)表示节点node初始时的金币数目，
它的左孩子为left，它的右孩子为right，则此时可以知道如下：

    若要使得左子树每个节点的数目均为1，此时node需要从 left「拿走」的为金币数目
        dfs(left)，此时left与node之间需要移动∣dfs(left)∣次金币；
    若要使得右子树每个节点的数目均为1，此时node需要从right「拿走」的金币数目
        dfs(right)，此时right与node之间需要移动∣dfs(right)∣次金币；
    此时根节点的金币总数目即为 move(left)+move(right)+val(node)，
        由于node本身需要保留一个金币，此时node的根节点需要向它「拿走」的金币数目
        即为 move(left)+move(right)+val(node)−1；
综上我们采用递归，每次递归遍历节点node时，返回其父节点需要从node「拿走」的金币数目，
并统计当前节点与其子节点之间的移动金币的次数，我们通过递归遍历
即可求得所有节点与其父节点之间的移动金币的次数统计之和即为总的金币移动次数。

由于本题中树中金币的数目与树中节点的数目相等，
根据上述推论可以知道根节点 root一定不需要再向其父节点移动金币。

复杂度分析

- 时间复杂度：O(n)，其中n表示二叉树中节点的数目。
只需要遍历一遍即可，因此时间复杂度为O(n)。

- 空间复杂度：O(n)，其中n表示二叉树中节点的数目。
递归深度与二叉树的深度有关，其中二叉树的深度最小值为log⁡n，
深度最大值为n，递归深度最多为n层，因此空间复杂度为O(n)。
 */