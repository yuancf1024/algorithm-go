// 2022-08-31 复写中序和后序还原二叉树
/*
算法思路：
可以发现后序遍历的数组最后一个元素代表的即为根节点。
知道这个性质后，我们可以利用已知的根节点信息在中序遍历的数组中找到根节点
所在的下标，然后根据其将中序遍历的数组分成左右两部分，左边部分即左子树，
右边部分为右子树，针对每个部分可以用同样的方法继续递归下去构造。

*算法

为了高效查找根节点元素在中序遍历数组中的下标，
我们选择创建哈希表来存储中序序列，
即建立一个（元素，下标）键值对的哈希表。

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

*/
class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立(元素，下标)键值对的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }

    // 辅助函数
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder) {
        // 如果这里没有节点构造二叉树，结束递归
        if (in_left > in_right) {
            return nullptr;
        }
        // 选择post_idx位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        // 根据root所在位置分成两颗子树
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