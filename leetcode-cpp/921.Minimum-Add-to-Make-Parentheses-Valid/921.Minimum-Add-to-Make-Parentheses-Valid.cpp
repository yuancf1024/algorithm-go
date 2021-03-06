/* 921. 使括号有效的最少添加
只有满足下面几点之一，括号字符串才是有效的：

- 它是一个空字符串，或者
- 它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
- 它可以被写作 (A)，其中 A 是有效字符串。

给定一个括号字符串 s ，移动N次，你就可以在字符串的任何位置插入一个括号。

- 例如，如果 s = "()))" ，你可以插入一个开始括号为 "(()))" 
或结束括号为 "())))" 。
返回 为使结果字符串 s 有效而必须添加的最少括号数。

示例 1：
输入：s = "())"
输出：1

示例 2：
输入：s = "((("
输出：3

提示：
1 <= s.length <= 1000
s 只包含 '(' 和 ')' 字符。
通过次数32,151提交次数43,071
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        // res 记录插入次数
        int res = 0;
        // need 变量记录右括号的需求量
        int need = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // 对右括号的需求数 + 1
                need++;
            }
            if (s[i] == ')') {
                // 对右括号的需求-1
                need--;

                if (need == -1) {
                    need = 0;
                    // 需插入一个左括号
                    res++;
                }
            }
        }

        return res + need;
    }
};

/*
核心思路是以左括号为基准，通过维护对右括号的需求数 need，
来计算最小的插入次数。需要注意两个地方：

1、当 need == -1 的时候意味着什么？

因为只有遇到右括号 ) 的时候才会 need--，need == -1 
意味着右括号太多了，所以需要插入左括号。

比如说 s = "))" 这种情况，需要插入 2 个左括号，
使得 s 变成 "()()"，才是一个有效括号串。

2、算法为什么返回 res + need？

因为 res 记录的左括号的插入次数，need 记录了右括号的需求，
当 for 循环结束后，若 need 不为 0，那么就意味着右括号还不够，需要插入。

比如说 s = "))(" 这种情况，插入 2 个左括号之后，
还要再插入 1 个右括号，使得 s 变成 "()()()"，
才是一个有效括号串。
*/