package leetcode

import "sort"

/* 1465. 切割后面积最大的蛋糕
矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 
和 verticalCuts，其中：
horizontalCuts[i] 是从矩形蛋糕顶部到第  i 个水平切口的距离
verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离

请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，
请你找出 面积最大 的那份蛋糕，并返回其 面积 。
由于答案可能是一个很大的数字，因此需要将结果 对 10^9 + 7 取余 后返回。

输入：h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
输出：4 
解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色的那份蛋糕面积最大。
*/

func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
	sort.Ints(horizontalCuts) // 水平切口排序
	sort.Ints(verticalCuts) // 垂直切口排序
	maxw, maxl := horizontalCuts[0], verticalCuts[0] // 假设第一条水平切口为最大切口值
	for i, c := range horizontalCuts[1:] { // 更新maxw
		if c - horizontalCuts[i] > maxw {
			maxw = c - horizontalCuts[i]
		}
	}
	if h - horizontalCuts[len(horizontalCuts)-1] > maxw { // 考虑蛋糕底部边界
		maxw = h - horizontalCuts[len(horizontalCuts)-1]
	}
	for i, c := range verticalCuts[1:] { // 假设第一条垂直切口为最大切口值
		if c - verticalCuts[i] > maxl { // 更新maxl
			maxl = c - verticalCuts[i]
		}
	}
	if w - verticalCuts[len(verticalCuts)-1] > maxl { // 考虑蛋糕右侧边界
		maxl = w - verticalCuts[len(verticalCuts)-1]
	}
	return (maxw * maxl) % (1000000007)
}

/*
解题思路
读完题比较容易想到解题思路。找到水平切口最大的差值和竖直切口最大的差值，
这 4 条边构成的矩形即为最大矩形。不过有特殊情况需要判断，
切口除了题目给的切口坐标以外，默认还有 4 个切口，即蛋糕原始的 4 条边。
如下图二，最大的矩形其实在切口之外。
**所以找水平切口最大差值和竖直切口最大差值需要考虑到蛋糕原始的 4 条边。**
*/