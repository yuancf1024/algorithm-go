package binaryTree

import "container/list"

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
			cur = cur.Left // 遍历到左孩子
		} else {
			cur = st.Remove(st.Back()).(*TreeNode) 
			// 栈顶出栈，从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
			ans = append(ans, cur.Val) // 中
			cur = cur.Right // 右
			// 访问到最左叶子节点后，cur接着会指向两个null指针
		}
	}
	return ans
}