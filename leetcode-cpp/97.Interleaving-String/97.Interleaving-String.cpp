/* 97. 交错字符串
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，
其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...

注意：a + b 意味着字符串 a 和 b 连接。

示例 1：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true

示例 2：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false

示例 3：
输入：s1 = "", s2 = "", s3 = ""
输出：true

提示：

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1、s2、和 s3 都由小写英文字母组成
 

进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它?
*/

// 参考leetcode官方题解
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector<vector<int>>(s1.size() + 1,
                                     vector<int>(s2.size() + 1, false));
        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n+m != t) {
            return false;
        }

        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[n][m];
    }
};
/*
解决这个问题的正确方法是动态规划。
首先如果 |s_1| + |s_2| != |s_3|，那 s_3必然不可能由 s_1和 s_2交错组成。
在 |s_1| + |s_2| = |s_3|时，我们可以用动态规划来求解。
我们定义 f(i,j) 表示 s_1的前 i 个元素和 s_2的前 j 个元素是否能交错组成 
s_3的前 i+j 个元素。

- 如果 s_1的第 i 个元素和 s_3的第 i+j 个元素相等，那么 s_1的前 i 个元素
和 s_2 的前 j 个元素是否能交错组成 s_3的前 i+j 个元素
取决于 s_1的前 i−1 个元素和 s_2的前 j 个元素是否能交错组成 s_3的
前 i+j−1 个元素，即此时 f(i,j) 取决于 f(i−1,j)，
在此情况下如果 f(i−1,j) 为真，f(i,j) 也为真。

- 同样的，如果 s_2的第 j 个元素和 s_3的第 i+j 个元素相等并且 f(i,j−1) 为真，
则 f(i,j) 也为真。于是我们可以推导出这样的动态规划转移方程：

f(i,j) = [f(i−1,j) and s1(i−1) = s3(p)] or 
[f(i,j−1) and s2(j−1) = s3(p)]

其中 p=i+j−1。边界条件为 f(0,0)=True。
至此，我们很容易可以给出这样一个实现：
不难看出这个实现的时间复杂度和空间复杂度都是 O(nm)。
*/

// 滚动数组优化版
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector<int>(s2.size() + 1, false);
        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[m];
    }
};
/*
使用滚动数组优化空间复杂度。 因为这里数组 f 的第 i 行只和第 i−1 行相关，
所以我们可以用滚动数组优化这个动态规划，
这样空间复杂度可以变成 O(m)。
*/