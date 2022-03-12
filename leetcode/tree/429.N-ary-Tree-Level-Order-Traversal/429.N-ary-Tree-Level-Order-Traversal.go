package leetcode

// import "github.com/yuancf1024/algorithm-go/structures"

// type TreeNode = structures.TreeNode
/**
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
**/
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */
type Node struct {
	Val int
	Children []*Node
}

// leetocde 通过
func levelOrder(root *Node) [][]int {
    if root == nil {
        return [][]int{}
    }

    queue := []*Node{root} // 新建队列
    res := make([][]int, 0) // 结果集
    for len(queue) > 0 {
        l := len(queue) // 记录当前层的数量
        tmp := make([]int, 0, l)
        for i := 0 ; i < l; i++ {
            // 该层的每个元素：1、找到该元素的孩子节点，加入到队列中，为下一层做准备
            // 2、将该元素的Val添加到该层结果集（临时）
            for j := 0; j < len(queue[i].Children); j++ {
                if queue[i].Children != nil {
                    queue = append(queue, queue[i].Children[j])
                }
            }
            tmp = append(tmp, queue[i].Val)
        }
        queue = queue[l:]
        res = append(res, tmp)
    }
    return res
}

/**
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：4.1 MB, 在所有 Go 提交中击败了99.15%的用户
**/

// func levelOrder(root *Node) [][]int {
//     queue:=list.New()
//     res:=[][]int{}//结果集
//     if root==nil{
//         return res
//     }
//     queue.PushBack(root)
//     for queue.Len()>0{
//         length:=queue.Len()//记录当前层的数量
//         var tmp []int
//         for T:=0;T<length;T++{//该层的每个元素：一添加到该层的结果集中；二找到该元素的下层元素加入到队列中，方便下次使用
//             myNode:=queue.Remove(queue.Front()).(*Node)
//             tmp=append(tmp,myNode.Val)
//             for i:=0;i<len(myNode.Children);i++{
//                 queue.PushBack(myNode.Children[i])
//             }
//         }
//         res=append(res,tmp)
//     }
//     return res
// }

/*
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：4.5 MB, 在所有 Go 提交中击败了24.31%的用户
*/