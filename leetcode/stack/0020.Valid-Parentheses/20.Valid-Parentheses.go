package leetcode

/* 20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，
判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/

func isValid(s string) bool {
	// 空字符串直接返回 true
	if len(s) == 0 {
		return true
	}
	stack := make([]rune, 0) // rune is an alias for int32 
	for _, v := range s {
		if (v == '[') || (v == '(') || (v == '{') {
			stack = append(stack, v) // 入栈
		} else if ((v == ']') && len(stack) > 0 && stack[len(stack)-1] == '[') ||
		((v == ')') && len(stack) > 0 && stack[len(stack)-1] == '(') ||
		((v == '{') && len(stack) > 0 && stack[len(stack)-1] == '{') {
			stack = stack[:len(stack)-1] // 栈顶元素出栈
		} else {
			return false
		}
	}
	return len(stack) == 0 // 最后栈里面没有元素，说明匹配有效
}

/*
解题思路
遇到左括号就进栈push，遇到右括号并且栈顶为与之对应的左括号，
就把栈顶元素出栈。最后看栈里面还有没有其他元素，如果为空，即匹配。

需要注意，空字符串是满足括号匹配的，即输出 true。
*/