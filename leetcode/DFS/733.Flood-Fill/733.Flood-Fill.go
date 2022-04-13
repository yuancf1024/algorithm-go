package leetcode

/* 733. 图像渲染
有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 
表示该图画的像素值大小。

你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 
开始对图像进行 上色填充 。

为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 
像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点
与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。
将所有有记录的像素点的颜色值改为 newColor 。

最后返回 经过上色渲染后的图像 。

注意:

image 和 image[0] 的长度在范围 [1, 50] 内。
给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。
*/

var dir = [][]int {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	color := image[sr][sc]
	if newColor == color {
		return image
	}

	dfs733(image, sr, sc, newColor)
	return image
}

func dfs733(image [][]int, x, y int, newColor int) {
	if image[x][y] == newColor {
		return
	}
	oldColor := image[x][y]
	image[x][y] = newColor
	for i := 0; i < 4; i++ {
		if (x+dir[i][0] >= 0 && x+dir[i][0] < len(image)) && 
		(y+dir[i][1] >= 0 && y+dir[i][1] < len(image[0]) && 
		image[x+dir[i][0]][y+dir[i][1]] == oldColor) {
			dfs733(image, x+dir[i][0], y+dir[i][1], newColor)
		}
	}
}

/* 解题思路
给出一个二维的图片点阵，每个点阵都有一个数字。
给出一个起点坐标，要求从这个起点坐标开始，把所有与这个起点连通的点都
染色成 newColor。
这一题是标准的 Flood Fill 算法。可以用 DFS 也可以用 BFS 。
*/