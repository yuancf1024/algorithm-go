/**
 * @file 466.Count-The-Repetitions.cpp
 * @author your name (you@domain.com)
 * @brief leetcode466.Count-The-Repetitions
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 定义 str = [s, n] 表示 str 由 n 个字符串 s 连接构成。

例如，str == ["abc", 3] =="abcabcabc" 。
如果可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。

例如，根据定义，s1 = "abc" 可以从 s2 = "abdbec" 获得，仅需要删除加粗且用斜体标识的字符。
现在给你两个字符串 s1 和 s2 和两个整数 n1 和 n2 。由此构造得到两个字符串，其中 str1 = [s1, n1]、str2 = [s2, n2] 。

请你找出一个最大整数 m ，以满足 str = [str2, m] 可以从 str1 获得。

 

示例 1：

输入：s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
输出：2
示例 2：

输入：s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
输出：1
 

提示：

1 <= s1.length, s2.length <= 100
s1 和 s2 由小写英文字母组成
1 <= n1, n2 <= 106
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(), n = s2.size();
        vector<pair<int, int>> d;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1[k] == s2[j]) {
                    if (++j == n) {
                        ++cnt;
                        j = 0;
                    }
                }
            }
            d.emplace_back(cnt, j);
        }
        int ans = 0;
        for (int j = 0; n1; --n1) {
            ans += d[j].first;
            j = d[j].second;
        }
        return ans / n2;
    }
};


int main() {
    string s1 = "abc", s2 = "ab";
    int n1 = 4, n2 = 2;
    int res = Solution().getMaxRepetitions(s1, n1, s2, n2);
    cout << res << endl;
    return 0;
}

/**
 * @brief 参考大佬@ylb
 * 方法一：预处理 + 递推

我们预处理出以字符串 s2s2s2 的每个位置 iii 开始匹配一个完整的 s1s1s1 后，下一个位置 jjj 以及经过了多少个 s2s2s2，即 d[i]=(cnt,j)d[i] = (cnt, j)d[i]=(cnt,j)，其中 cntcntcnt 表示匹配了多少个 s2s2s2，而 jjj 表示字符串 s2s2s2 的下一个位置。

接下来，我们初始化 j=0j=0j=0，然后循环 n1n1n1 次，每一次将 d[j][0]d[j][0]d[j][0] 加到答案中，然后更新 j=d[j][1]j=d[j][1]j=d[j][1]。

最后得到的答案就是 n1n1n1 个 s1s1s1 所能匹配的 s2s2s2 的个数，除以 n2n2n2 即可得到答案。

 * 
 */