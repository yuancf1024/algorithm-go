package leetcode

/* 1047. 删除字符串中的所有相邻重复项
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：
输入："abbaca"
输出："ca"

解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，
这是此时唯一可以执行删除操作的重复项。
之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，
所以最后的字符串为 "ca"。

提示：

1 <= S.length <= 20000
S 仅由小写英文字母组成。

*/

func removeDuplicates1047(s string) string {
	stack := []rune{}
	for _, s := range s {
		// 栈顶为空 or 栈不为空且栈顶元素不等于s -> 入栈
		if len(stack) == 0 || len(stack) > 0 && stack[len(stack)-1] != s {
			stack = append(stack, s)
		} else { // 新来的字符和栈顶的字符一样的话 -> 出栈
			stack = stack[:len(stack)-1]
		}
	}
	return string(stack)
}

/* 解题思路
用栈模拟，类似“对对碰”，一旦新来的字符和栈顶的字符一样的话，
就弹出栈顶字符，直至扫完整个字符串。
栈中剩下的字符串就是最终要输出的结果。
*/