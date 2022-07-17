/* 22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，
用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]

提示：
1 <= n <= 8
*/

// 暴力法 参考leetcode
class Solution {
private:
    bool valid(const string& str) { 
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) { 
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};

/*
为了生成所有序列，我们可以使用递归。长度为 n 的序列就是在长度为 n−1 
的序列前加一个 ‘(’ 或 ‘)’。

为了检查序列是否有效，我们遍历这个序列，并使用一个变量 balance 表示
左括号的数量减去右括号的数量。如果在遍历过程中 balance 的值小于零，
或者结束时 balance 的值不为零，那么该序列就是无效的，
否则它是有效的。
*/

/*
/参考labuladong 算法

1. 回溯框架
result = []
def backtrack(路径,选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径，选择列表)
        撤销选择

2. 伪代码
void backtrack(int n, int i, string& track) {
    // i 代表当前的位置，共2n 个位置
    // 穷举到最后一个位置了，得到一个长度为2n组合
    if (i == 2 * n) {
        print(track);
        return;
    }

    // 对于每个位置可以是左括号或者右括号两种选择
    for choice in ['(', ')'] {
        track.push(choice); // 做选择
        // 穷举下一个位置
        backtrack(n, i + 1, track);
        track.pop(choice); // 撤销选择
    }
}
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {};
        // 记录所有合法的括号组合
        vector<string> res;
        // 回溯过程中的路径
        string track;
        // 可用的左括号和右括号数量初始化为n
        backtrack(n, n, track, res);
        return res;
    }

    // 可用的左括号数量为left个，可用的右括号数量为right个
    void backtrack(int left, int right, string& track, vector<string>& res) {
        // 若左括号剩下的多，说明不合法
        if (right < left)
            return;
        // 数量小于0 肯定是不合法
        if (left < 0 || right < 0)
            return;
        // 当所有括号都恰好用完时，得到一个合法的括号组合
        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        // 尝试放一个左括号
        track.push_back('('); // 选择
        backtrack(left - 1, right, track, res);
        track.pop_back(); // 撤销选择

        // 尝试放一个右括号
        track.push_back(')'); // 选择
        backtrack(left, right - 1, track, res);
        track.pop_back(); // 撤销选择
    }
};


/*
对于 2n 个位置，必然有 n 个左括号，n 个右括号，
所以我们不是简单的记录穷举位置 i，而是用 left 记录还可以使用多少个左括号，
用 right 记录还可以使用多少个右括号
*/