#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 字符串操作 30分
 * 
 * 给定一个只包含小写字母字符串，
 * 每次可以选择两个相同的字符删除，
 * 并在字符结尾新增任意一个小写字母。
 * 请问最少多少次操作后，所有的字母都不相同？
 *
 * 备注：字符串长度不超过1000
示例1：
"abab"

2

 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    
    int minOperations(string str) {
        // write code here
        int cnt;
        int top = 0;
        for (auto& x : str) {
            if (top == 0 || str[top-1] != x) {
                str[top++] = x;
                cnt++;
            } else {
                top--;
            }
        }
        str.resize(top);
        return cnt;
        // 思路：求最少操作，感觉是dp
        // 用栈模拟
        // deque<char> queue;
        // vector<int> nums(26);
        // for (char s : str) {
        //     nums[int(s - 'a')]++;
        //     queue.push_back(s);
        // }

        // stack<char> stk;
        // stk.push(str[0]);
        // while (!stk.empty()) {
            
        // }
    }
};

int main() {
    string str;
    cin >> str;

    Solution s;
    int res = s.minOperations(str);

    cout << res << endl;
    return 0;
}