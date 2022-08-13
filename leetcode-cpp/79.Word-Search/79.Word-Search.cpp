/**
 * @file 79.Word-Search.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * leetcode-79.单词搜索
给定一个 m x n 二维字符网格 board 和
一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；
否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true

示例 3：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
 
提示：

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board 和 word 仅由大小写英文字母组成
 

进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 */

// 复写2022-08-13
/*
思路：回溯+DFS
我们可以从网格中的任意一个位置出发寻找单词，
如果找到则返回 true，否则以下一个位置为起点继续寻找。

对于任一开始位置，寻找的过程都是一个回溯过程，
需要使用递归求解

1. 递归函数含义：bool dfs(int x, int y, string& word, int u) 
表示当前位置 (x,y) 和 word 中的第 u 个字母是否匹配，
如果匹配则返回 true 否则返回 false。

2. 递归出口条件：如果 g[x][y]!=word[u] 
说明当前位置上的字符与答案不匹配直接返回 false，
否则说明匹配且当 u==word.size()−1 所有字母都匹配成功，
即找到了单词则返回 true。

3. 单层递归逻辑：
设置当前位置已经访问过 st[x][y]=true
从当前位置开始判断四个方向上的字母是否与 word 中的下一个字母匹配
且这个位置之前没有走过，如果匹配则走到下一个位置，
否则如果所有方向都不能匹配则回溯到当前位置的上一个位置继续寻找。
状态回溯 st[x][y]=false

时间复杂度
O(2^n)，不是精确值，但回溯一般都是指数级别复杂度
空间复杂度
O(nm)，n 是行，m 是列（代码中的实现）。
*/

class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    // 辅函数
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int k) {
        // 回溯终止条件
        if (word[k] != board[i][j]) {
            return false;
        }
        if (k == word.size()-1) {
            return true;
        }
        visited[i][j] = true; // word[i][j] == board[i][j]
        // 回溯搜索遍历
        for (int a = 0; a < 4; ++a) {
            int x = i + direction[a], y = j + direction[a + 1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y]) {
                if (dfs(board, visited, x, y, word, k+1)) {
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
};

// 回溯
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
    // 辅函数
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length()-1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir : directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};

/**
 * @brief 
 * 方法1：回溯
思路与算法
设函数 check(i,j,k) 表示判断以网格的 (i,j) 位置出发，
能否搜索到单词 word[k..]，其中 word[k..] 表示字符串 word 从第 k 个字符开始的后缀子串。
如果能搜索到，则返回 true，反之返回 false。

函数 check(i,j,k) 的执行步骤如下：

- 如果 board[i][j] != s[k]，当前字符不匹配，直接返回 false。
- 如果当前已经访问到字符串的末尾，且对应字符依然匹配，
此时直接返回 true。
- 否则，遍历当前位置的所有相邻位置。如果从某个相邻位置出发，
能够搜索到子串 word[k+1..]，则返回 true，否则返回 false。

这样，我们对每一个位置 (i,j) 都调用函数 check(i,j,0) 进行检查：
只要有一处返回 true，就说明网格中能够找到相应的单词，否则说明不能找到。

为了防止重复遍历相同的位置，需要额外维护一个与 board 等大的 visited 数组，
用于标识每个位置是否被访问过。每次遍历相邻位置时，需要跳过已经被访问的位置。

复杂度分析

时间复杂度：一个非常宽松的上界为O(MN⋅3^L)，
其中M,N 为网格的长度与宽度，L 为字符串 word 的长度。
在每次调用函数 check 时，除了第一次可以进入 4 个分支以外，
其余时间我们最多会进入3 个分支（因为每个位置只能使用一次，所以走过来的分支没法走回去）。
由于单词长为 L，故 check(i,j,0) 的时间复杂度为O(3^L)，
而我们要执行O(MN) 次检查。
然而，由于剪枝的存在，我们在遇到不匹配或已访问的字符时会提前退出，
终止递归流程。
因此，实际的时间复杂度会远远小于 Θ(MN⋅3^L)。

空间复杂度：O(MN)。我们额外开辟了 O(MN) 的 visited 数组，
同时栈的深度最大为O(min(L,MN))。

 */