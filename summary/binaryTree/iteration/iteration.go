package binaryTree

import (
	"container/list"

	"github.com/yuancf1024/algorithm-go/structures"
)

type TreeNode = structures.TreeNode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// TODO: 不调用标准库实现的迭代法
// 非递归，用栈模拟递归过程
// 前序遍历+迭代法
func PreorderTraversal2(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}

	stack := []*TreeNode{}
	stack = append(stack, root)

	for len(stack) != 0 {
		l := len(stack)
		node := stack[l-1]
		stack = stack[:l-1] // 栈顶元素出栈,中结点先处理

		if node != nil {
			res = append(res, node.Val)
		}
		if node.Right != nil { // 右孩子入栈
			stack = append(stack, node.Right)
		}
		if node.Left != nil { // 左孩子入栈
			stack = append(stack, node.Left)
		}
	}
	return res
}

// 后续遍历, 用栈模拟递归过程
func PostorderTraversal2(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}

	stack := []*TreeNode{}      // 新建栈
	stack = append(stack, root) // 根节点入栈

	for len(stack) != 0 {
		l := len(stack)
		node := stack[l-1] // 栈顶出栈
		stack = stack[:l-1]
		// 后续遍历：左右中
		// 反转：中右左
		res = append(res, node.Val) // 当前节点值返回
		if node.Left != nil {
			stack = append(stack, node.Left)
		}

		if node.Right != nil {
			stack = append(stack, node.Right)
		}
	}
	// 反转res
	length := len(res)
	for i := 0; i < length/2; i++ {
		res[i], res[length-i-1] = res[length-i-1], res[i]
	}
	return res
}

// 中序遍历, 用栈模拟递归过程
// 单独用栈模拟递归实现中序遍历，稍微有点复杂
// 和前序、后序差别很大，不好理解
func InorderTraversal2(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}

	stack := []*TreeNode{} // 不能提前将root结点入栈
	cur := root

	for cur != nil || len(stack) > 0 {
		for cur != nil { // 先迭代访问最底层的左子树结点
			stack = append(stack, cur)
			cur = cur.Left
		}
		cur = stack[len(stack)-1] // 到达最左结点后处理栈顶结点
		stack = stack[:len(stack)-1]
		res = append(res, cur.Val)
		cur = cur.Right // 取栈顶元素右结点
	}
	return res
}

// Go语言实现加标记的迭代法遍历二叉树，不是特别方便，因此就理解上面三种迭代法遍历吧

// 迭代+标记
// 将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。
// 如何标记呢，就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。
// 中序遍历：左中右
// 压栈顺序：右中左
// func InorderTraversal3(root *TreeNode) []int {
// 	if root == nil {
// 		return nil
// 	}

// 	stack := []*TreeNode{} // 新建栈
// 	res :=[] int{} // 结果集
// 	stack = append(stack, root) // 根节点入栈
// 	var node *TreeNode
// 	for len(stack) > 0 {
// 		e := stack[len(stack)-1]
// 		stack = stack[:len(stack)-1] // 栈顶出栈
// 		if e.Val == nil { //如果为空，则表明是需要处理中间节点
// 			e = stack[len(stack)-1]
// 			stack = stack[:len(stack)-1]
// 			node =  e.Val.(*TreeNode)
// 		}
// 	}

// }

// NULL 方便添加测试数据
// var NULL = -1 << 63
/*###############调用标准库函数分割线###############*/

// 迭代法前序遍历
func PreorderTraversal_i(root *TreeNode) []int {
	ans := []int{}

	if root == nil {
		return ans
	}

	st := list.New()
	st.PushBack(root) // 根节点入栈

	for st.Len() > 0 {
		node := st.Remove(st.Back()).(*TreeNode) // 栈顶出栈

		ans = append(ans, node.Val)

		if node.Right != nil { // 右孩子入栈
			st.PushBack(node.Right)
		}

		if node.Left != nil { // 左孩子入栈
			st.PushBack(node.Left)
		}
	}
	return ans
}

// 迭代法后序遍历
func PostorderTraversal_i(root *TreeNode) []int {
	ans := []int{}

	if root == nil {
		return ans
	}

	st := list.New()
	st.PushBack(root) // 入栈

	for st.Len() > 0 {
		node := st.Remove(st.Back()).(*TreeNode) //

		ans = append(ans, node.Val)

		if node.Left != nil {
			st.PushBack(node.Left)
		}

		if node.Right != nil {
			st.PushBack(node.Right)
		}
	}
	Reverse(ans)

	return ans
}

func Reverse(a []int) {
	l, r := 0, len(a)-1
	for l < r {
		a[l], a[r] = a[r], a[l]
		l, r = l+1, r-1
	}
}

// 迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，
// 栈则用来处理节点上的元素。
func InorderTraversal_i(root *TreeNode) []int {
	ans := []int{}
	if root == nil {
		return ans
	}

	st := list.New()
	cur := root

	for cur != nil || st.Len() > 0 {
		if cur != nil { // 指针来访问节点，访问到最底层
			st.PushBack(cur) // 将访问的节点放进栈
			cur = cur.Left   // 遍历到左孩子
		} else {
			cur = st.Remove(st.Back()).(*TreeNode)
			// 栈顶出栈，从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
			ans = append(ans, cur.Val) // 中
			cur = cur.Right            // 右
			// 访问到最左叶子节点后，cur接着会指向两个null指针
		}
	}
	return ans
}

/**
type Element struct {
	// 元素保管的值
	Value interface{}
	// 内含隐藏或非导出字段
}
**/

// 统一风格的迭代法
// 中序遍历：迭代+标记法
// 中序遍历：左中右
// 压栈顺序：右中左
func InorderTraversal_im(root *TreeNode) []int {

	if root == nil {
		return nil
	}

	var st = list.New() // 栈
	res := []int{}      // 结果集
	st.PushBack(root)
	var node *TreeNode

	for st.Len() > 0 {
		e := st.Back()
		st.Remove(e)        // 弹出元素
		if e.Value == nil { // 如果为空，则表明是需要处理中间节点
			e = st.Back() // 弹出元素（即中间节点）
			st.Remove(e)  // 删除中间节点
			node = e.Value.(*TreeNode)
			res = append(res, node.Val) // 将中间节点加入到结果集中
			continue                    // 继续弹出栈中下一个节点
		}
		node = e.Value.(*TreeNode)
		// 压栈顺序：右中左
		if node.Right != nil {
			st.PushBack(node.Right)
		}
		st.PushBack(node) // 中间节点压栈后再压入nil作为中间节点的标志符
		st.PushBack(nil)
		if node.Left != nil {
			st.PushBack(node.Left)
		}
	}
	return res
}

// 前序遍历：迭代+标记法
// 前序遍历：中左右
// 压栈顺序：右左中
func PreorderTraversal_im(root *TreeNode) []int {

	if root == nil {
		return nil
	}

	var st = list.New() // 栈
	res := []int{}      // 结果集
	st.PushBack(root)
	var node *TreeNode

	for st.Len() > 0 {
		e := st.Back()
		st.Remove(e)        // 弹出元素
		if e.Value == nil { // 如果为空，则表明是需要处理中间节点
			e = st.Back() // 弹出元素（即中间节点）
			st.Remove(e)  // 删除中间节点
			node = e.Value.(*TreeNode)
			res = append(res, node.Val) // 将中间节点加入到结果集中
			continue                    // 继续弹出栈中下一个节点
		}
		node = e.Value.(*TreeNode)
		// 压栈顺序：右左中
		if node.Right != nil {
			st.PushBack(node.Right)
		}

		if node.Left != nil {
			st.PushBack(node.Left)
		}
		st.PushBack(node) // 中间节点压栈后再压入nil作为中间节点的标志符
		st.PushBack(nil)
	}
	return res
}

// 后序遍历：迭代+标记法
// 后序遍历：左右中
// 压栈顺序：中右左
func PostorderTraversal_im(root *TreeNode) []int {

	if root == nil {
		return nil
	}

	var st = list.New() // 栈
	res := []int{}      // 结果集
	st.PushBack(root)
	var node *TreeNode

	for st.Len() > 0 {
		e := st.Back()
		st.Remove(e)        // 弹出元素
		if e.Value == nil { // 如果为空，则表明是需要处理中间节点
			e = st.Back() // 弹出元素（即中间节点）
			st.Remove(e)  // 删除中间节点
			node = e.Value.(*TreeNode)
			res = append(res, node.Val) // 将中间节点加入到结果集中
			continue                    // 继续弹出栈中下一个节点
		}
		node = e.Value.(*TreeNode)
		// 压栈顺序：中右左
		st.PushBack(node) // 中间节点压栈后再压入nil作为中间节点的标志符
		st.PushBack(nil)
		if node.Right != nil {
			st.PushBack(node.Right)
		}

		if node.Left != nil {
			st.PushBack(node.Left)
		}
	}
	return res
}
