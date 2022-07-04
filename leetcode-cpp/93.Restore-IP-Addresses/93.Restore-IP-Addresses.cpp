/* 93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，
且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，
但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 
是 无效 IP 地址。

给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，
返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]

示例 2：
输入：s = "0000"
输出：["0.0.0.0"]

示例 3：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

提示：

1 <= s.length <= 20
s 仅由数字组成
*/

class Solution {
private:
    vector<string> result; // 记录结果
    // startIndex: 搜索的起始位置, pointNum: 添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result
            if (isValid(s, startIndex, s.size()-1)) {
                result.push_back(s);
            }
            return;
        }

        // 递归&回溯
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // 判断[startIndex, i]这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum); // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--; // 回溯
                s.erase(s.begin() + i + 1); // 回溯删掉逗点
            } else {
                break; // 不合法，直接结束本层循环
            }
        }
    }

    // 判断字符串s在左闭右开区间[start, end]所组成的数字是否合法
        bool isValid(const string& s, int start, int end) {
            if (start > end) {
                return false;
            }
            if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
            }
            int num = 0;
            for (int i = start; i <= end; i++) {
                if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                    return false;
                }
                num = num * 10 + (s[i] - '0');
                if (num > 255) { // 如果大于255了不合法
                    return false;
                }
            }
            return true;
        }

public:
    vector<string> restoreIpAddresses(string s) { 
        result.clear();
        if (s.size() < 4 || s.size() > 12)
            return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
};

/*
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}



*/
