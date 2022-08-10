/**
 * @file 839.Similar-String-Groups.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * leetcode-839.相似字符串组

如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，
那么称 X 和 Y 两个字符串相似。

如果这两个字符串本身是相等的，那它们也是相似的。

例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； 
"rats" 和 "arts" 也是相似的，
但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。

总之，它们通过相似性形成了两个关联组：
{"tars", "rats", "arts"} 和 {"star"}。
注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。
形式上，对每个组而言，要确定一个单词在组中，只需要这个词和
该组中至少一个单词相似。

给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的
一个字母异位词。请问 strs 中有多少个相似字符串组？

示例 1：

输入：strs = ["tars","rats","arts","star"]
输出：2

示例 2：
输入：strs = ["omv","ovm"]
输出：1
 
提示：

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] 只包含小写字母。
strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。

 */

// 方法一：并查集

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> f;

    int find(int x) { 
        return f[x] == x ? x : f[x] = find(f[x]); 
    }

    bool check(const string& a, const string& b, int len) { 
        int num = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) { 
        int n = strs.size();
        int m = strs[0].length();
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int fi = find(i), fj = find(j);
                if (fi == fj) {
                    continue;
                }
                if (check(strs[i], strs[j], m)) {
                    f[fi] = fj;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i] == i) { // 这里只写了一个= 找了半天bug
                ret++;
            }
        }
        return ret;
    }
};

int main() { 

    vector<string> strs = {"tars", "rats", "arts", "star"};
    Solution solution;

    int res = solution.numSimilarGroups(strs);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 * 方法一：并查集
思路及解法
我们把每一个字符串看作点，字符串之间是否相似看作边，
那么可以发现本题询问的是给定的图中有多少连通分量。
于是可以想到使用并查集维护节点间的连通性。

我们枚举给定序列中的任意一对字符串，检查其是否具有相似性，
如果相似，那么我们就将这对字符串相连。

在实际代码中，我们可以首先判断当前这对字符串是否已经连通，
如果没有连通，我们再检查它们是否具有相似性，
可以优化一定的时间复杂度的常数。
复杂度分析

时间复杂度：O(n^2*m+nlogn))，其中 n 是字符串的数量。
我们需要 O(n^2)地枚举任意一对字符串之间的关系，
对于任意一对字符串，我们需要 O(m) 的时间检查字符串是否相同。
在最坏情况下我们需要对并查集执行 O(n) 次合并，
合并的均摊时间复杂度 O(logn)。
综上，总的时间复杂度为 O(n^2*m + nlogn))。

空间复杂度：O(n)，其中 n 是字符串的数量。
并查集需要 O(n) 的空间。
 */