package _6_linkedlist

/*
思路1：开一个栈存放链表前半段
时间复杂度：O(N)
空间复杂度：O(N)
*/
func isPalindrome1(l *LinkedList) bool {
	lLen := l.length
	if lLen == 0 {
		return false
	}
	if lLen == 1 {
		return true
	}

	s := make([]string, 0, lLen/2)
	cur := l.head
	for i := uint(1); i <= lLen; i++ {
		cur = cur.next // l.head.next 代表链表第一个节点
		if lLen%2 != 0 && i == (lLen/2+1) {
			// 如果链表有奇数个节点，中间的直接忽略
			continue
		}
		if i <= lLen/2 {
			// 前一半入栈
			s = append(s, cur.GetValue().(string))
		} else {
			// 后一半与前一半进行对比
			if s[lLen-i] != cur.GetValue().(string) {
				return false
			}
		}
	}
	return true
}

/*
思路2
找到链表中间节点，将前半部分转置，再从中间向左右遍历对比
时间复杂度：O(N)
*/
func isPalindrome2(l *LinkedList) bool {
	lLen := l.length
	if lLen == 0 {
		return false
	}
	if lLen == 1 {
		return true
	}

	var isPalindrome = true
	step := lLen / 2 // 13/2 = 6
	var pre *ListNode = nil
	cur := l.head.next // l.head.next 代表的是整个链表的头节点
	next := l.head.next.next // 链表头节点的下一个节点
	for i := uint(1); i <= step; i++ {
		tmp := cur.GetNext()
		cur.next = pre
		pre = cur
		cur = tmp
		next = cur.GetNext()
	}
	mid := cur

	var left, right *ListNode = pre, nil
	if lLen%2 != 0 { // 奇数情况，cur定位到正中间的数字了
		right = mid.GetNext()
	} else { // 偶数情况，cur定位到右边部分的第一个数字了
		right = mid
	}

	for nil != left && nil != right {
		if left.GetValue().(string) != right.GetValue().(string) {
			isPalindrome = false
			break
		}
		left = left.GetNext()
		right = right.GetNext()
	}

	// 复原链表
	cur = pre
	pre = mid
	for nil != cur {
		next = cur.GetNext()
		cur.next = pre
		pre = cur
		cur = next
	}
	l.head.next = pre

	return isPalindrome
}