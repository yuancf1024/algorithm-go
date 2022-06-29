package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/*285.二叉搜索树中的中序后继
给定一棵二叉搜索树和其中的一个节点 p ，找到该节点在树中的中序后继。
如果节点没有中序后继，请返回 null 。

节点 p 的后继是值比 p.val 大的节点中键值最小的节点，
即按中序遍历的顺序节点 p 的下一个节点。

示例 1：

	2
   / \
  1   3

输入：root = [2,1,3], p = 1
输出：2
解释：这里 1 的中序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。

示例 2：

		5
	   / \
	  3   6
	 / \
	2   4
   /
  1

输入：root = [5,3,6,2,4,null,null,1], p = 6
输出：null
解释：因为给出的节点没有中序后继，所以答案就返回 null 了。
 
提示：

树中节点的数目在范围 [1, 10^4] 内。
-10^5 <= Node.val <= 10^5
树中各节点的值均保证唯一。

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 方法1: 中序遍历
func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
    st := []*TreeNode{}
	var pre, cur *TreeNode = nil, root
	for len(st) > 0 || cur != nil {
		for cur != nil {
			st = append(st, cur)
			cur = cur.Left
		}
		cur = st[len(st)-1]
		st = st[:len(st)-1]
		if pre == p {
			return cur
		}
		pre = cur
		cur = cur.Right
	}
	return nil
}

/*
方法一：中序遍历
为了找到二叉搜索树中的节点 p 的中序后继，
最直观的方法是中序遍历。由于只需要找到节点 p 的中序后继，
因此不需要维护完整的中序遍历序列，只需要在中序遍历的过程中维护上一个
访问的节点和当前访问的节点。如果上一个访问的节点是节点 p，
则当前访问的节点即为节点 p 的中序后继。

如果节点 p 是最后被访问的节点，则不存在节点 p 的中序后继，
返回 null。

复杂度分析
- 时间复杂度：O(n)，其中 n 是二叉搜索树的节点数。
中序遍历最多需要访问二叉搜索树中的每个节点一次。

- 空间复杂度：O(n)，其中 n 是二叉搜索树的节点数。
空间复杂度取决于栈深度，平均情况是 O(logn)，最坏情况是 O(n)。
*/

// 方法二：利用二叉搜索树的性质
func inorderSuccessor1(root *TreeNode, p *TreeNode) *TreeNode {
	var successor *TreeNode
	if p.Right != nil { // 节点 p 的右子树不为空
		successor = p.Right // 节点 p 的中序后继在其右子树中
		for successor.Left != nil {
			successor = successor.Left
		}
		return successor
	}
	node := root
	for node != nil { // 节点 p 的右子树为空,从根节点开始遍历寻找节点 p 的祖先节点
		if node.Val > p.Val {
			successor = node
			node = node.Left
		} else {
			node = node.Right
		}
	}
	return successor
}

/*
二叉搜索树的一个性质是中序遍历序列单调递增，因此二叉搜索树中的节点 p 的
中序后继满足以下条件：

- 中序后继的节点值大于 p 的节点值；
- 中序后继是节点值大于 p 的节点值的所有节点中节点值最小的一个节点。

利用二叉搜索树的性质，可以在不做中序遍历的情况下找到节点 p 的中序后继。
- 如果节点 p 的右子树不为空，则节点 p 的中序后继在其右子树中，
在其右子树中定位到最左边的节点，即为节点 p 的中序后继。
- 如果节点 p 的右子树为空，则需要从根节点开始遍历寻找节点 p 的祖先节点。

将答案初始化为 null。用 node 表示遍历到的节点，初始时node=root。
每次比较 node 的节点值和 p 的节点值，执行相应操作：

- 如果 node 的节点值大于 p 的节点值，则 p 的中序后继可能是 node 
或者在 node 的左子树中，因此用 node 更新答案，并将 node 移动到其左子节点继续遍历；
- 如果 node 的节点值小于或等于 p 的节点值，则 p 的中序后继可能在 
node 的右子树中，因此将 node 移动到其右子节点继续遍历。

由于在遍历过程中，当且仅当 node 的节点值大于 p 的节点值的情况下，
才会用 node 更新答案，因此当节点 p 有中序后继时一定可以找到中序后继，
当节点 p 没有中序后继时答案一定为 null。

复杂度分析
- 时间复杂度：O(n)，其中 n 是二叉搜索树的节点数。
遍历的节点数不超过二叉搜索树的高度，平均情况是 O(logn)，
最坏情况是 O(n)。
- 空间复杂度：O(1)。
*/