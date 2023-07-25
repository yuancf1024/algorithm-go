#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 嘤嘤的新平衡树 30分
 * 
 * 给定一颗二叉树，二叉树的每个结点只有0或2个孩子。
 * 你需要对每个结点赋值一个正整数，
 * 使得每个结点的左右子树权值相等。
 * 你需要返回所有结点的最小权值和对10^9+7取模的结果。
 * 二叉树结点个数不超过10^5.
 * 
 * 
示例1：
{0,0,0}

3


 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tree TreeNode类 
     * @return int整型
     */
    int getTreeSum(TreeNode* tree) {
        // write code here
    }
};

int main() { 
    
    return 0; 
}