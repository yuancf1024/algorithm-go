/**
 * @file 101.Symmetric-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * leetcode-101.对称二叉树
 * 
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
 
提示：

树中节点数目在范围 [1, 1000] 内
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

// 参考代码随想录 递归法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return compare(root->left, root->right);
    }
    // 辅函数
    bool compare(TreeNode* left, TreeNode* right) {
        // 首先排除空节点的情况
        if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right != nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            return false;
        }

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right); // 左子树: 左、右子树: 右
        bool inside = compare(left->right, right->left); // 左子树: 右、右子树: 左
        bool isSame = outside && inside; // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;
    }
};

// 迭代法 使用队列
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> que;
        que.push(root->left); // 将左子树的头节点加入队列
        que.push(root->right); // 将右子树的头节点加入队列

        while (!que.empty()) { // 接下来就要判断这两个树是否相互翻转
            TreeNode* leftNode = que.front();
            que.pop();
            TreeNode* rightNode = que.front();
            que.pop();
            if (!leftNode && !rightNode) { // 左右节点均为空，说明是对称的
                continue;
            }

            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            que.push(leftNode->left); // 加入左节点的左孩子
            que.push(rightNode->right); // 加入右节点的右孩子
            que.push(leftNode->right); // 加入左节点的右孩子
            que.push(rightNode->left); // 揭开如右节点的左孩子
        }
        return true;
    }
};

/**
 * @brief 参考代码随想录
 * 思路
首先想清楚，判断对称二叉树要比较的是哪两个节点，要比较的可不是左右节点！

对于二叉树是否对称，要比较的是根节点的左子树与右子树是不是相互翻转的，
理解这一点就知道了其实我们要比较的是两个树（这两个树是根节点的左右子树），
所以在递归遍历的过程中，也是要同时遍历两棵树。

那么如果比较呢？

比较的是两个子树的里侧和外侧的元素是否相等。如图所示：

那么遍历的顺序应该是什么样的呢？

本题遍历只能是“后序遍历”，因为我们要通过递归函数的返回值来
判断两个子树的内侧节点和外侧节点是否相等。

正是因为要遍历两棵树而且要比较内侧和外侧节点，所以准确的来说是
一个树的遍历顺序是左右中，一个树的遍历顺序是右左中。

但都可以理解算是后序遍历，尽管已经不是严格上在一个树上进行遍历的后序遍历了。

其实后序也可以理解为是一种回溯，当然这是题外话，讲回溯的时候会重点讲的。

说到这大家可能感觉我有点啰嗦，哪有这么多道理，上来就干就完事了。
别急，我说的这些在下面的代码讲解中都有身影。

那么我们先来看看递归法的代码应该怎么写。

递归法
递归三部曲

1. 确定递归函数的参数和返回值
因为我们要比较的是根节点的两个子树是否是相互翻转的，
进而判断这个树是不是对称树，所以要比较的是两个树，
参数自然也是左子树节点和右子树节点。

返回值自然是bool类型。

代码如下：

bool compare(TreeNode* left, TreeNode* right)

2. 确定终止条件
要比较两个节点数值相不相同，首先要把两个节点为空的情况弄清楚！
否则后面比较数值的时候就会操作空指针了。

节点为空的情况有：（注意我们比较的其实不是左孩子和右孩子，所以如下我称之为左节点右节点）

- 左节点为空，右节点不为空，不对称，return false
- 左不为空，右为空，不对称 return false
- 左右都为空，对称，返回true

此时已经排除掉了节点为空的情况，那么剩下的就是左右节点不为空：

- 左右都不为空，比较节点数值，不相同就return false

此时左右节点不为空，且数值也不相同的情况我们也处理了。

代码如下：

if (left == NULL && right != NULL) return false;
else if (left != NULL && right == NULL) return false;
else if (left == NULL && right == NULL) return true;
else if (left->val != right->val) return false; // 注意这里我没有使用else

注意上面最后一种情况，我没有使用else，而是elseif， 
因为我们把以上情况都排除之后，剩下的就是 左右节点都不为空，
且数值相同的情况。

3. 确定单层递归的逻辑
此时才进入单层递归的逻辑，单层递归的逻辑就是处理 左右节点都不为空，
且数值相同的情况。

- 比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子。
- 比较内侧是否对称，传入左节点的右孩子，右节点的左孩子。
- 如果左右都对称就返回true ，有一侧不对称就返回false 。

代码如下：

bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
bool isSame = outside && inside;                    // 左子树：中、 右子树：中（逻辑处理）
return isSame;
如上代码中，我们可以看出使用的遍历方式，左子树左右中，右子树右左中，
所以我把这个遍历顺序也称之为“后序遍历”（尽管不是严格的后序遍历）。

最后递归的C++整体代码如下：



迭代法

这道题目我们也可以使用迭代法，但要注意，
这里的迭代法可不是前中后序的迭代写法，因为本题的本质是
判断两个树是否是相互翻转的，其实已经不是所谓二叉树遍历的前中后序的关系了。

这里我们可以使用队列来比较两个树（根节点的左右子树）是否相互翻转，
（注意这不是层序遍历）

使用队列

通过队列来判断根节点的左子树和右子树的内侧和外侧是否相等，如动画所示：


如下的条件判断和递归的逻辑是一样的


 */