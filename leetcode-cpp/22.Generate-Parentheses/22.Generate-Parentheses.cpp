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

// 暴力法
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


