/*
思路：
求感染二叉树需要的总时间

这一题思路很简单，关键是具体实现。
涉及到的节点，分两路走，一边向下，一边向上，统计最后一次碰到
叶子节点的时间，两路时间取max。
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
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        
    }
};