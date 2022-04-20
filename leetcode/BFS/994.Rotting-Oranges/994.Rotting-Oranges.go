package leeetcode

func orangesRotting(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    queue := make([][]int, 0) // 记录腐烂橘子的坐标

    count := 0 // 记录新鲜橘子的数量
    for r := 0; r < m; r++ {
        for c := 0; c < n; c++ {
            if grid[r][c] == 1 { // 1代表新鲜橘子
                count++
            } else if grid[r][c] == 2 { // 2 代表腐烂橘子
                queue = append(queue, []int{r, c})
            }
        }
    }

    round := 0 // round 表示腐烂的轮数，或者分钟数
    for count > 0 && len(queue) != 0 {
        round++
        length := len(queue)
        for i := 0; i < length; i++ {
            orange := queue[0] // 队头出队
            queue = queue[1:]
            r, c := orange[0], orange[1]
            if r-1 >= 0 && grid[r-1][c] == 1 {
                grid[r-1][c] = 2
                count--
                queue = append(queue, []int{r-1, c})
            }
            if r+1 < m && grid[r+1][c] == 1 {
                grid[r+1][c] = 2
                count--
                queue = append(queue, []int{r+1, c})
            }
            if c-1 >= 0 && grid[r][c-1] == 1 {
                grid[r][c-1] = 2
                count--
                queue = append(queue, []int{r, c-1})
            }
            if c+1 < n && grid[r][c+1] == 1 {
                grid[r][c+1] = 2
                count--
                queue = append(queue, []int{r, c+1})
            }
        }
    }
    if count > 0 {
        return -1
    } else {
        return round
    }
}