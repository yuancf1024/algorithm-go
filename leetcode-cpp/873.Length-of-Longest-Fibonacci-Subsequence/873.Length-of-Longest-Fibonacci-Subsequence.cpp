/* 873. 最长的斐波那契子序列的长度
如果序列 X_1, X_2, ..., X_n 满足下列条件，
就说它是 斐波那契式 的：

- n >= 3
- 对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列 arr ，
找到 arr 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。

（回想一下，子序列是从原序列 arr 中派生出来的，
它从 arr 中删掉任意数量的元素（也可以不删），
而不改变其余元素的顺序。例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列）

示例 1：
输入: arr = [1,2,3,4,5,6,7,8]
输出: 5
解释: 最长的斐波那契式子序列为 [1,2,3,5,8] 。

示例 2：
输入: arr = [1,3,7,11,12,14,18]

输出: 3
解释: 最长的斐波那契式子序列有 [1,11,12]、[3,11,14] 以及 [7,11,18] 。

提示：
3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 10^9

*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<int, int> intMap;
        for (int i = 0; i < n; i++) {
            intMap[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = 2;
            }
        }
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = arr[j] - arr[i];
                if (intMap.count(diff)) { // diff在intMap中存在
                    int index = intMap[diff];
                    if (index < i) {
                        dp[i][j] = max(dp[i][j], dp[index][i] + 1);
                    }
                }
                MAX = max(MAX, dp[i][j]);
            }
        }
        return MAX > 2 ? MAX : 0;
    }
};

/*
状态定义
dp[i][j]：表示以A[i],A[j]结尾的斐波那契数列的最大长度

dp[i][j]=Len(......,A[i],A[j])

状态转移
这里我们考虑在A[i]之前有某个数字A[k]，
那么是不是应该满足如下式子

A[k] + A[i] == A[j]

那么我们就可以写出来状态转移方程

dp[i][j]= {A[k]+A[i]==A[j]} max(dp[k][i]+1)

代码编写
根据状态转移方程我们很快就能写出来代码，
但是Time Limit Error,这里我想了好久，
最终在大佬的题解中才发现，这里我们在寻找k的时候，
不需要再一次遍历（严格递增），所以为了提高效率，
建立intMap是值到索引的映射。

intMap

value intMap -> key
*/