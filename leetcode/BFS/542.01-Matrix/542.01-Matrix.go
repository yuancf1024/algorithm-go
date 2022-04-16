package leetcode

// import "math"

/* 542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，
其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。
*/

/*
解题思路
给出一个二维数组，数组里面只有 0 和 1 。要求计算每个 1 距离最近的 0 的距离。
这一题有 3 种解法，

第一种解法最容易想到，BFS。先预处理一下棋盘，将每个 0 都处理为 -1 。
将 1 都处理为 0 。将每个 -1 (即原棋盘的 0)都入队，每次出队都将四周的 4 个位置都入队。
这就想一颗石头扔进了湖里，一圈一圈的波纹荡开，每一圈都是一层。
由于棋盘被我们初始化了，所有为 -1 的都是原来为 0 的，
所以波纹扫过来不需要处理这些 -1 的点。棋盘上为 0 的点都是原来为 1 的点，
这些点在波纹扫过来的时候就需要赋值更新 level。当下次波纹再次扫到原来为 1 
的点的时候，由于它已经被第一次到的波纹更新了值，所以这次不用再更新了。
(第一次波纹到的时候一定是最短的)

第二种解法是 DFS。先预处理，把周围没有 0 的 1 都重置为最大值。
当周围有 0 的 1，距离 0 的位置都是 1，这些点是不需要动的，
需要更新的点恰恰应该是那些周围没有 0 的点。当递归的步数 val 比点的值小
(这也就是为什么会先把 1 更新成最大值的原因)的时候，不断更新它。

第三种解法是 DP。由于有 4 个方向，每次处理 2 个方向，可以降低时间复杂度。
第一次循环从上到下，从左到右遍历，先处理上边和左边，
第二次循环从下到上，从右到左遍历，再处理右边和下边。
*/ 

// 解法1：BFS 广度优先搜索 halfrost大佬的解法（不易理解）
func updateMatrix(mat [][]int) [][]int {
	res := make([][]int, len(mat))
	if len(mat) == 0 || len(mat[0]) == 0 {
		return res
	}

	queue := make([][]int, 0)
	// 预处理棋盘，将每个 0 都处理为 -1 ；将 1 都处理为 0 
	// 将每个 -1 (即原棋盘的 0)都入队
	for i := range mat {
		res[i] = make([]int, len(mat[0]))
		for j := range res[i] {
			if mat[i][j] == 0 {
				res[i][j] = -1
				queue =append(queue, []int{i, j}) // 队列存储的是值为-1的坐标
			}
		}
	}
	level := 1
	for len(queue) > 0 {
		size := len(queue)
		for size > 0 {
			size--
			node := queue[0]
			queue = queue[1:]
			i, j := node[0], node[1]
			for _, direction := range [][]int{{-1, 0}, {1, 0}, {0, 1}, {0, -1}} { // 四个方向移动
				x := i + direction[0]
				y := j + direction[1]
				if x < 0 || x >= len(mat) || y < 0 || y >= len(mat[0]) ||
				res[x][y] < 0 || res[x][y] > 0 { // 移动超出棋盘，或者值为-1，或者已经更新过（最短），跳过当次循环
					// res[i][j] == 0 说明还没有遍历到，没有更新
					continue
				}
				res[x][y] = level // 否则，就更新level
				queue = append(queue, []int{x, y}) // 添加进队列，但是其值不会更新，是为了遍历到其周围还没有更新的点
			}
		}
		level++
	}

	// 恢复预处理，将-1复原为初始值
	for i, row := range res {
		for j, cell := range row {
			if cell == -1 {
				res[i][j] = 0
			}
		}
	}
	return res
}

// 参考：Sweetiee 的BFS 非常容易理解
// https://leetcode-cn.com/problems/01-matrix/solution/2chong-bfs-xiang-jie-dp-bi-xu-miao-dong-by-sweetie/

func updateMatrix_BFS(mat [][]int) [][]int {
	// mat 全为0的特殊case
	res := make([][]int, len(mat))
	if len(mat) == 0 || len(mat[0]) == 0 {
		return res
	}

	// 首先将所有的 0 都入队，并且将 1 的位置设置成 -1，表示该位置是 未被访问过的 1
	queue := make([][]int, 0)
	for i := range mat {
		res[i] = make([]int, len(mat[0]))
		for j := range res[i] {
			if mat[i][j] == 0 {
				queue =append(queue, []int{i, j}) // 队列存储的是值为0的坐标
			} else {
				res[i][j] = -1
			}
		}
	}

	var dir = [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}} // 上下左右四个方向
	for len(queue) > 0 { // 为0的队列不为空
		node := queue[0]
		queue = queue[1:] // 弹出队首元素
		x, y := node[0], node[1]
		// BFS 试探四个方向
		for i := 0; i < 4; i++ {
			newX := x + dir[i][0]
			newY := y + dir[i][1]
			// 如果四个邻域的点是-1，表示这个点是未被访问过的1
			// 所以这个点到0的距离就可以更新成res[x][y]+1
			if newX >= 0 && newX < len(mat) && newY >= 0 && newY < len(mat[0]) &&
			res[newX][newY] == -1 {
				res[newX][newY] = res[x][y] + 1 // 在试探元素之前的坐标的基础上加1
				queue = append(queue, []int{newX, newY}) // 将非0的坐标加入队列
			}
		}
	}
	return res
}
/*
思路：
● 首先把每个源点 0 入队，然后从各个 0 同时开始一圈一圈的向 1 扩散
（每个 1 都是被离它最近的 0 扩散到的 ），扩散的时候可以设置 int[][] dist 
来记录距离（即扩散的层次）并同时标志是否访问过。对于本题是可以直接修改
原数组 int[][] matrix 来记录距离和标志是否访问的，这里要注意先把 
matrix 数组中 1 的位置设置成 -1 （设成Integer.MAX_VALUE啦，m * n啦，
10000啦都行，只要是个无效的距离值来标志这个位置的 1 没有被访问过就行辣~）

复杂度分析：
● 每个点入队出队一次，所以时间复杂度：O(n * m)
● 虽然我们是直接原地修改的原输入数组来存储结果，但最差的情况下即全都是 0 
时，需要把 m * n个 0 都入队，因此空间复杂度是 O(n∗m)
*/

// 参考：Sweetiee 的DP
func updateMatrix_DP(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}
	if m == 0 || n == 0 {
		return dp
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ { // 这里错误的把j初始化为1，所以卡了半天bug
			if mat[i][j] == 1 {
				dp[i][j] = 10000
			}
		}
	}

	// 从左上角开始
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if (i - 1 >= 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1)
			}
			if (j - 1 >= 0) {
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 1)
			}
		}
	}

	// 从右下角开始
	for i := m-1; i >= 0; i-- {
		for j := n-1; j >= 0; j-- {
			if (i + 1 < m) {
				dp[i][j] = min(dp[i][j], dp[i+1][j] + 1)
			}
			if (j + 1 < n) {
				dp[i][j] = min(dp[i][j], dp[i][j+1] + 1)
			}
		}
	}
	return dp
}


func min (x, y int) int {
	if x < y {
		return x
	}
	return y
}


// 其他人的DP实现
func updateMatrix_DP1(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	out := make([][]int, m)
	for i := 0; i < m; i++ {
		out[i] = make([]int, n)
		for j := 0; j < n; j++ {
			if matrix[i][j] != 0 {
				out[i][j] = 10000
				if i != 0 {
					out[i][j] = min(out[i][j], out[i-1][j]+1)
				}
				if j != 0 {
					out[i][j] = min(out[i][j], out[i][j-1]+1)
				}
			} else {
				out[i][j] = 0
			}
		}
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if out[i][j] > 1 {
				if i < m-1 {
					out[i][j] = min(out[i][j], out[i+1][j]+1)
				}
				if j < n-1 {
					out[i][j] = min(out[i][j], out[i][j+1]+1)
				}
			}
		}
	}
	return out
}