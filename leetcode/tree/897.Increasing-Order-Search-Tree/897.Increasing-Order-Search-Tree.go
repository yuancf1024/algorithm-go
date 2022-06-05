package leetcode

import "github.com/yuancf1024/algorithm-go/structures"

type TreeNode = structures.TreeNode

/* 897. 递增顺序搜索树
给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为
一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，
并且每个节点没有左子节点，只有一个右子节点。

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
示例 2：

	5
   / \
  1   7

=>
	1
	 \
	  5
	   \
	    7


输入：root = [5,1,7]
输出：[1,null,5,null,7]

提示：
树中节点数的取值范围是 [1, 100]
0 <= Node.val <= 1000

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 解法二 模拟
func increasingBST(root *TreeNode) *TreeNode {
	list := []int{}
	inorder(root, &list)
	if len(list) == 0 {
		return root
	}
	newRoot := &TreeNode{Val: list[0], Left: nil, Right: nil}
	cur := newRoot
	for index := 1; index < len(list); index++ {
		tmp := &TreeNode{Val: list[index], Left: nil, Right: nil}
		cur.Right = tmp // cur的右子树为tmp
		cur = tmp // cur更新到tmp结点
	}
	return newRoot
}

func inorder(root *TreeNode, output *[]int) {
	if root != nil {
		inorder(root.Left, output)
		*output = append(*output, root.Val)
		inorder(root.Right, output)
	}
}

// 链表思想 不太好理解
func increasingBST1(root *TreeNode) *TreeNode {
	var head = &TreeNode{}
	tail := head
	recBST(root, tail)
	return head.Right
}

func recBST(root, tail *TreeNode) *TreeNode {
	if root == nil {
		return tail
	}
	tail = recBST(root.Left, tail)
	root.Left = nil // 切断 root 与其Left的连接，避免形成环
	tail.Right, tail = root, root // 把root接上tail，并保持 tail指向尾部
	tail = recBST(root.Right, tail)
	return tail
}

/*
解题思路
- 给出一颗树，要求把树的所有孩子都排列到右子树上。
- 按照题意，可以先中根遍历原树，然后按照中根遍历的顺序，
把所有节点都放在右子树上。见解法二。

- 上一种解法会重新构造一颗新树，有没有办法可以直接更改原有的树呢？
节约存储空间。虽然平时软件开发过程中不建议更改原有的值，
但是算法题中追求空间和时间的最优，可以考虑一下。树可以看做是有多个孩子的
链表。这一题可以看成是链表的类似反转的操作。这一点想通以后，就好做了。
先找到左子树中最左边的节点，这个节点是新树的根节点。然后依次往回遍历，
不断的记录下上一次遍历的最后节点 tail，边遍历，边把后续节点串起来。
最终“反转”完成以后，就得到了题目要求的样子了。代码实现见解法一。
*/

