/**
 * @file 2678.Number-of-Senior-Citizens.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2678.老人的数目
 * @version 0.1
 * @date 2023-10-23
 * 
 * @copyright Copyright (c) 2023
 * 给你一个下标从 0 开始的字符串 details 。
 * details 中每个元素都是一位乘客的信息，
 * 信息用长度为 15 的字符串表示，表示方式如下：

- 前十个字符是乘客的手机号码。
- 接下来的一个字符是乘客的性别。
- 接下来两个字符是乘客的年龄。
- 最后两个字符是乘客的座位号。
- 请你返回乘客中年龄 严格大于 60 岁 的人数。

示例 1：
输入：details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
输出：2
解释：下标为 0 ，1 和 2 的乘客年龄分别为 75 ，92 和 40 。所以有 2 人年龄大于 60 岁。

示例 2：
输入：details = ["1313579440F2036","2921522980M5644"]
输出：0
解释：没有乘客的年龄大于 60 岁。
 
提示：

1 <= details.length <= 100
details[i].length == 15
details[i] 中的数字只包含 '0' 到 '9' 。
details[i][10] 是 'M' ，'F' 或者 'O' 之一。
所有乘客的手机号码和座位号互不相同。
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto s: details) {
            int num1 = 10;
            int num2 = 0;
            int sum = 0;
            num1 *= ((s[11]) - '0');
            num2 += s[12] - '0';
            if ((num1 + num2) > 60) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    int res = Solution().countSeniors(details);
    cout << res << endl;
    return 0;
}
