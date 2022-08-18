/**
 * @file 226.Invert-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * leetcode-226.翻转二叉树
 * 
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

示例 2：
输入：root = [2,1,3]
输出：[2,3,1]

示例 3：
输入：root = []
输出：[]
 
提示：

树中节点数目范围在 [0, 100] 内
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

// 递归法 前序遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right); // 中
        invertTree(root->left); // 左
        invertTree(root->right); // 右
        return root;
    }
};

// 迭代法 DFS 前序遍历 借助栈
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); // 中
            st.pop();
            swap(node->left, node->right);
            if (node->right) {
                st.push(node->right); // 右
            }
            if (node->left) {
                st.push(node->left); // 左
            }
        }
        return root;
    }
};

// BFS 层序遍历 借助队列
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { 
        queue<TreeNode*> que;
        if (root != NULL) {
            que.push(root);
        }
        while( !que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); // 节点处理
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};

/**
 * @brief 参考代码随想录
 * 这道题目背后有一个让程序员心酸的故事，
 * 听说 Homebrew的作者Max Howell，就是因为没在白板上写出翻转二叉树，
 * 最后被Google拒绝了。（真假不做判断，权当一个乐子哈）

#题外话

这道题目是非常经典的题目，也是比较简单的题目（至少一看就会）。

但正是因为这道题太简单，一看就会，一些同学都没有抓住起本质，
稀里糊涂的就把这道题目过了。

如果做过这道题的同学也建议认真看完，相信一定有所收获！

#思路
我们之前介绍的都是各种方式遍历二叉树，这次要翻转了，感觉还是有点懵逼。

这得怎么翻转呢？

如果要从整个树来看，翻转还真的挺复杂，整个树以中间分割线进行翻转，如图：

可以发现想要翻转它，其实就把每一个节点的左右孩子交换一下就可以了。

关键在于遍历顺序，前中后序应该选哪一种遍历顺序？ 
（一些同学这道题都过了，但是不知道自己用的是什么顺序）

遍历的过程中去翻转每一个节点的左右孩子就可以达到整体翻转的效果。

注意只要把每一个节点的左右孩子翻转一下，就可以达到整体翻转的效果

这道题目使用前序遍历和后序遍历都可以，唯独中序遍历不方便，
因为中序遍历会把某些节点的左右孩子翻转了两次！建议拿纸画一画，就理解了

那么层序遍历可以不可以呢？依然可以的！
只要把每一个节点的左右孩子翻转一下的遍历方式都是可以的！


#递归法

对于二叉树的递归法的前中后序遍历，已经在二叉树：前中后序递归遍历详细讲解了。

我们下文以前序遍历为例，通过动画来看一下翻转的过程:

我们来看一下递归三部曲：

1. 确定递归函数的参数和返回值
参数就是要传入节点的指针，不需要其他参数了，通常此时定下来主要参数，
如果在写递归的逻辑中发现还需要其他参数的时候，随时补充。

返回值的话其实也不需要，但是题目中给出的要返回root节点的指针，
可以直接使用题目定义好的函数，所以就函数的返回类型为TreeNode*。

TreeNode* invertTree(TreeNode* root)

2. 确定终止条件
当前节点为空的时候，就返回

if (root == NULL) return root;


3. 确定单层递归的逻辑
因为是先前序遍历，所以先进行交换左右孩子节点，
然后反转左子树，反转右子树。

swap(root->left, root->right);
invertTree(root->left);
invertTree(root->right);
基于这递归三步法，代码基本写完，C++代码如下：


迭代法
#深度优先遍历
二叉树：听说递归能做的，栈也能做！ 中给出了前中后序迭代方式的写法，
所以本地可以很轻松的切出如下迭代法的代码：

C++代码迭代法（前序遍历）


广度优先遍历

也就是层序遍历，层数遍历也是可以翻转这棵树的，
因为层序遍历也可以把每个节点的左右孩子都翻转一遍，代码如下：
 */