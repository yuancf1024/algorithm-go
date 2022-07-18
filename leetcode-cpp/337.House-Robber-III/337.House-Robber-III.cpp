/* 337. 打家劫舍 III
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，
我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，
小偷能够盗取的最高金额 。

示例 1:
输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7

示例 2:
输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9

提示：
树的节点数在 [1, 10^4] 范围内
0 <= Node.val <= 10^4
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

// 暴力递归
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        // 偷父节点
        int val1 = root->val;
        if (root->left) // 跳过root->left,相当于不考虑左孩子了
            val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) // 跳过root->right,相当于不考虑右孩子了
            val1 += rob(root->right->left) + rob(root->right->right);
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        return max(val1, val2);
    }
};

/* 参考代码随想录

本题一定是要后序遍历，因为通过递归函数的返回值来做下一步计算。

与198.打家劫舍，213.打家劫舍II一样，关键是要讨论当前节点抢还是不抢。

如果抢了当前节点，两个孩子就不能动，如果没抢当前节点，
就可以考虑抢左右孩子（注意这里说的是“考虑”）

- 时间复杂度：$O(n^2)$，这个时间复杂度不太标准，
也不容易准确化，例如越往下的节点重复计算次数就越多
- 空间复杂度：$O(\log n)$，算上递推系统栈的空间
当然以上代码超时了，这个递归的过程中其实是有重复计算了。

我们计算了root的四个孙子（左右孩子的孩子）为头结点的子树的情况，
又计算了root的左右孩子为头结点的子树的情况，计算左右孩子的时候其实又把孙子计算了一遍。
*/

// 记忆化递推
class Solution {
public:
    unordered_map<TreeNode*, int> umap; // 记录计算过的结果
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        if (umap[root])
            return umap[root]; // 如果umap里已经有记录则直接返回
        // 偷父节点
        int val1 = root->val;
        if (root->left) // 跳过root->left
            val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) // 跳过root->right
            val1 += rob(root->right->left) + rob(root->right->right);
        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        umap[root] = max(val1, val2); // umap记录一下结果
        return max(val1, val2);
    }
};

/*
使用一个map把计算过的结果保存一下，这样如果计算过孙子了，
那么计算孩子的时候可以复用孙子节点的结果。
时间复杂度：$O(n)$
空间复杂度：$O(\log n)$，算上递推系统栈的空间
*/

// 动态规划
class Solution {
public:
    int rob(TreeNode* root) { 
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }

    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};

/*
时间复杂度：$O(n)$，每个节点只遍历了一次
空间复杂度：$O(\log n)$，算上递推系统栈的空间
*/

/*
在上面两种方法，其实对一个节点 偷与不偷得到的最大金钱都没有做记录，
而是需要实时计算。

而动态规划其实就是使用状态转移容器来记录状态的变化，
这里可以使用一个长度为2的数组，
记录当前节点偷与不偷所得到的的最大金钱。

这道题目算是树形dp的入门题目，因为是在树上进行状态转移，
我们在讲解二叉树的时候说过递归三部曲，那么下面我以递归三部曲为框架，
其中融合动规五部曲的内容来进行讲解。

1. 确定递归函数的参数和返回值
这里我们要求一个节点 偷与不偷的两个状态所得到的金钱，
那么返回值就是一个长度为2的数组。

vector<int> robTree(TreeNode* cur){}

其实这里的返回数组就是dp数组。
所以dp数组（dp table）以及下标的含义：
下标为0记录不偷该节点所得到的的最大金钱，
下标为1记录偷该节点所得到的的最大金钱。
所以本题dp数组就是一个长度为2的数组！

那么有同学可能疑惑，长度为2的数组怎么标记树中每个节点的状态呢？
别忘了在递归的过程中，系统栈会保存每一层递归的参数。
如果还不理解的话，就接着往下看，看到代码就理解了哈。

2. 确定终止条件
在遍历的过程中，如果遇到空节点的话，
很明显，无论偷还是不偷都是0，所以就返回

if (cur == NULL) return vector<int>{0, 0};

这也相当于dp数组的初始化

3. 确定遍历顺序
首先明确的是使用后序遍历。
因为通过递归函数的返回值来做下一步计算。
- 通过递归左节点，得到左节点偷与不偷的金钱。
- 通过递归右节点，得到右节点偷与不偷的金钱。

// 下标0：不偷，下标1：偷
vector<int> left = robTree(cur->left); // 左
vector<int> right = robTree(cur->right); // 右
// 中

4. 确定单层递归的逻辑
- 如果是偷当前节点，那么左右孩子就不能偷，
val1 = cur->val + left[0] + right[0];
（如果对下标含义不理解就在回顾一下dp数组的含义）

- 如果不偷当前节点，那么左右孩子就可以偷，
至于到底偷不偷一定是选一个最大的，所以：
val2 = max(left[0], left[1]) +
max(right[0], right[1]);

- 最后当前节点的状态就是{val2, val1};
即：{不偷当前节点得到的最大金钱，偷当前节点得到的最大金钱}

vector<int> left = robTree(cur->left); // 左
vector<int> right = robTree(cur->right); // 右

// 偷cur
int val1 = cur->val + left[0] + right[0];
// 不偷cur
int val2 = max(left[0], left[1]) + max(right[0], right[1]);
return {val2, val1};

5. 举例推导dp数组
以示例1为例，dp数组状态如下：
（注意用后序遍历的方式推导）

*/
