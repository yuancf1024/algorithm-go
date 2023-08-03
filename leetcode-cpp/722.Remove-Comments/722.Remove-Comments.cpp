/**
 * @file 722.Remove-Comments.cpp
 * @author your name (you@domain.com)
 * @brief 722. 删除注释
 * @version 0.1
 * @date 2023-08-03
 * 
 * @copyright Copyright (c) 2023
 * https://leetcode.cn/problems/remove-comments/
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string new_line = "";
        bool in_block = false;
        for (auto& line : source) {
            for (int i = 0; i < line.size(); i++) {
                if (in_block) {
                    if (i + 1 < line.size() && line[i] == '*' && line[i+1] == '/') {
                        in_block = false;
                        i++;
                    } 
                } else {
                    if (i + 1 < line.size() && line[i] == '/' && line[i+1] == '*') {
                        in_block = true;
                        i++;
                    } else if (i + 1 < line.size() && line[i] == '/' && line[i+1] == '/') {
                        break;
                    } else {
                        new_line += line[i];
                    }
                }
            }
            if (!in_block && new_line != "") {
                ans.push_back(new_line);
                new_line = "";
            }
        }
        return ans;
    }
};

int main() {
    vector<string> source = {"/*Test program */", "int main()", 
        "{ ", "  // variable declaration ", "int a, b, c;", 
        "/* This is a test", "   multiline  ", "   comment for ", 
        "   testing */", "a = b + c;", "}"
        };
    vector<string> res = Solution().removeComments(source);

    for (auto & x : res) {
        cout << x << endl;
    }

    return 0;
}

/**
 * @brief leetcode官方题解
方法一：模拟
思路与算法

我们需要逐行分析源代码。每个字符有两种情况，
要么在一个注释内要么不在。因此我们用 in_block
变量来标记状态，该变量为 true 表示在注释内，
反之则不在。

假设此刻不在注释块内：

- 遇到 ‘/*’\，则将状态改为在注释块内，
继续遍历后面第三个字符。
- 遇到 ‘//’，则直接忽略该行后面的部分。
- 遇到其他字符，将该字符记录到 new_line 中。

假设此刻在注释块内，遇到 '* /'，则将状态改为
不在注释块内，继续遍历后面第三个字符。

我们用new_line记录新的一行，当遍历到每行的末尾时，
如果不在注释块内并且 new_line不为空，
就把它放入答案中。

复杂度分析

时间复杂度：O(nm)，其中 n 是 source 的长度，
m是 source[i] 的最大长度。

空间复杂度：O(nm)。在极端情况下，
每一行的隐式换行符都被块注释删除，
new_line的长度将会达到O(nm)。
 * 
 */