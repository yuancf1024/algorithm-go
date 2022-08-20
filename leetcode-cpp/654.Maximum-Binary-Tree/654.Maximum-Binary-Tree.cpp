/**
 * @file 654.Maximum-Binary-Tree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * leetcode-654.最大二叉树
给定一个不重复的整数数组 nums 。 
最大二叉树 可以用下面的算法从 nums 递归地构建:

- 创建一个根节点，其值为 nums 中的最大值。
- 递归地在最大值 左边 的 子数组前缀上 构建左子树。
- 递归地在最大值 右边 的 子数组后缀上 构建右子树。

返回 nums 构建的 最大二叉树 。

示例 1：
输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]

解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。

示例 2：
输入：nums = [3,2,1]
输出：[3,null,2,null,1]
 

提示：

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
nums 中的所有整数 互不相同

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

// 单调栈 容易理解的实现 😂其实不太好理解
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        vector<int> stk;
        vector<int> left(n, -1), right(n, -1);
        vector<TreeNode*> tree(n);
        for (int i = 0; i < n; ++i) {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.back()]) {
                right[stk.back()] = i;
                stk.pop_back();
            }
            if (!stk.empty()) {
                left[i] = stk.back();
            }
            stk.push_back(i);
        }

        TreeNode* root = nullptr;
        for (int i = 0; i < n; ++i) {
            if (left[i] == -1 && right[i] == -1) {
                root = tree[i];
            }
            else if (right[i] == -1 || (left[i] != -1 && nums[left[i]] < nums[right[i]])) {
                tree[left[i]]->right = tree[i];
            }
            else {
                tree[right[i]]->left = tree[i];
            }
        }
        return root;
    }
};

// 递归 优化后的代码
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }

    // 辅函数 在左闭右开区间[left, right) 构造二叉树
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) { // 遇到空节点，也就是数组区间为0，就终止了
            return nullptr;
        }

        // 分割点下标: maxValueIndex
        int maxValueIndex = left;
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > nums[maxValueIndex]) {
                maxValueIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        // 左闭右开: [left, maxValueIndex+1)
        root->left = traversal(nums, left, maxValueIndex);
        // 左闭右开: [maxValueIndex+1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
};

// 参考代码随想录 逻辑清晰
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) { // 遇到叶子节点就终止，因为空节点不会进入递归
            node->val = nums[0];
            return node;
        }
        // 找到数组中最大的值和对应的下标
        int maxValue = 0, maxValueIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;
        // 最大值所在的下标左区间 构造左子树
        if (maxValueIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }

        // 最大值所在下标右区间 构造右子树
        if (maxValueIndex < (nums.size()-1)) {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};

// 2022-08-20 first
/*
思路：按照题目给定的算法，递归构建最大二叉树。
注意左右子树为空情况的处理。
递归三部曲
1. 确定递归函数参数和返回值
2. 确定递归返回条件
3. 递归体

想要在主函数体内实现逻辑，但是怎么和辅函数连接起来呢？
*/
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(*max_element(nums.begin(), nums.end()));
        int Max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == *max_element(nums.begin(), nums.end())) {
                Max = i;
            }
        }
        return maxBinary(root, 0, Max-1)
    }

    // 辅函数
    TreeNode* maxBinary(TreeNode* root, int left, int right) {

    }
};

/**
 * @brief 参考代码随想录
 * 思路
最大二叉树的构建过程如下：

构造树一般采用的是前序遍历，因为先构造中间节点，
然后递归构造左子树和右子树。

1. 确定递归函数的参数和返回值
参数就是传入的是存放元素的数组，
返回该数组构造的二叉树的头结点，返回类型是指向节点的指针。

代码如下：
TreeNode* constructMaximumBinaryTree(vector<int>& nums)

2. 确定终止条件
题目中说了输入的数组大小一定是大于等于1的，所以我们不用考虑小于1的情况，
那么当递归遍历的时候，如果传入的数组大小为1，说明遍历到了叶子节点了。

那么应该定义一个新的节点，并把这个数组的数值赋给新的节点，
然后返回这个节点。 这表示一个数组大小是1的时候，构造了一个新的节点，并返回。

代码如下：

TreeNode* node = new TreeNode(0);
if (nums.size() == 1) {
    node->val = nums[0];
    return node;
}

3. 确定单层递归的逻辑
这里有三步工作

1. 先要找到数组中最大的值和对应的下标， 最大的值构造根节点，
下标用来下一步分割数组。
代码如下：

int maxValue = 0;
int maxValueIndex = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > maxValue) {
        maxValue = nums[i];
        maxValueIndex = i;
    }
}
TreeNode* node = new TreeNode(0);
node->val = maxValue;

2. 最大值所在的下标左区间 构造左子树
这里要判断maxValueIndex > 0，因为要保证左区间至少有一个数值。

代码如下：

if (maxValueIndex > 0) {
    vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
    node->left = constructMaximumBinaryTree(newVec);
}

3. 最大值所在的下标右区间 构造右子树
判断maxValueIndex < (nums.size() - 1)，确保右区间至少有一个数值。

代码如下：

if (maxValueIndex < (nums.size() - 1)) {
    vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
    node->right = constructMaximumBinaryTree(newVec);
}

这样我们就分析完了，整体代码如下

复杂度分析

时间复杂度：O(n^2)，其中n 是数组nums 的长度。
在最坏的情况下，数组严格递增或递减，需要递归n层，
第i (0≤i<n) 层需要遍历n−i 个元素以找出最大值，总时间复杂度为 O(n^2)。

空间复杂度：O(n)，即为最坏情况下需要使用的栈空间。

方法二：单调栈

思路与算法

我们可以将题目中构造树的过程等价转换为下面的构造过程：

- 初始时，我们只有一个根节点，其中存储了整个数组；

- 在每一步操作中，我们可以「任选」一个存储了超过一个数的节点，
找出其中的最大值并存储在该节点。最大值左侧的数组部分下放到该节点的左子节点，
右侧的数组部分下放到该节点的右子节点；

- 如果所有的节点都恰好存储了一个数，那么构造结束。

由于最终构造出的是一棵树，因此无需按照题目的要求「递归」地进行构造，
而是每次可以「任选」一个节点进行构造。
这里可以类比一棵树的「深度优先搜索」和「广度优先搜索」，
二者都可以起到遍历整棵树的效果。

既然可以任意进行选择，那么我们不妨每次选择数组中最大值最大的那个节点
进行构造。这样一来，我们就可以保证按照数组中元素降序排序的顺序依次
构造每个节点。因此：

当我们选择的节点中数组的最大值为nums[i] 时，
所有大于nums[i]的元素已经被构造过（即被单独放入某一个节点中），
所有小于nums[i] 的元素还没有被构造过。

这就说明：

在最终构造出的树上，以nums[i] 为根节点的子树，在原数组中对应的区间，
左边界为nums[i] 左侧第一个比它大的元素所在的位置，
右边界为nums[i] 右侧第一个比它大的元素所在的位置。左右边界均为开边界。

如果某一侧边界不存在，则那一侧边界为数组的边界。
如果两侧边界均不存在，说明其为最大值，即根节点。

并且：
nums[i]的父结点是两个边界中较小的那个元素对应的节点。

因此，我们的任务变为：找出每一个元素左侧和右侧第一个比它大的元素所在的位置。
这就是一个经典的单调栈问题了，可以参考 503. 下一个更大元素 II。
如果左侧的元素较小，那么该元素就是左侧元素的右子节点；
如果右侧的元素较小，那么该元素就是右侧元素的左子节点。

我们还可以把最后构造树的过程放进单调栈求解的步骤中，
省去用来存储左右边界的数组。
下面的代码理解起来较为困难，同一个节点的左右子树会被多次赋值，
读者可以仔细品味其妙处所在。




复杂度分析

时间复杂度：O(n)，其中n是数组 nums 的长度。
单调栈求解左右边界和构造树均需要O(n) 的时间。

空间复杂度：O(n)，即为单调栈和数组tree 需要使用的空间。
 */