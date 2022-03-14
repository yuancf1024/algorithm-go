package leetcode

type Node struct {
	Val int
	Children []*Node
}

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

// 给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。
// n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

// 输入：root = [1,null,3,2,4,null,5,6]
// 输出：[5,6,3,2,4,1]
// 后序遍历：左右中

// 方法1：递归
func postorder(root *Node) []int {
    res := make([]int, 0)
    postorderdfs(root, &res)
    return res
}

func postorderdfs(root *Node, res *[]int) {
    if root == nil {
        return
    }
    
    for i := 0; i < len(root.Children); i++ {
        postorderdfs(root.Children[i], res)
    }
    *res = append(*res, root.Val)
}

// 方法2：迭代法
// 后序遍历：左右中
// 入栈：中右左
func postorder1(root *Node) []int {
    res := []int{}
    if root == nil {
        return res
    }

    stack := []*Node{root}

    for len(stack) > 0 {
        l := len(stack)
        node := stack[l-1]
        stack = stack[:l-1]
        res = append(res, node.Val)
        tmp := []*Node{}
        for _, v := range node.Children {
            tmp = append(tmp, []*Node{v}...)
        }
        stack = append(stack, tmp...)
    }
    // 中右左
    // 倒序输出
    length := len(res)
    for i := 0; i < length / 2; i++ {
        res[i], res[length-i-1] = res[length-i-1], res[i]
    }
    return res
}


