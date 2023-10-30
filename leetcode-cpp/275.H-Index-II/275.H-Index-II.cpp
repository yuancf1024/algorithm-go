/**
 * @file 275.H-Index-II.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-275.H指数II C++ 二分
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，
 * citations 已经按照 升序排列 。计算并返回该研究者的 h 指数。

h 指数的定义：h 代表“高引用次数”（high citations），
一名科研人员的 h 指数是指他（她）的 （n 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。

请你设计并实现对数时间复杂度的算法解决此问题。

示例 1：
输入：citations = [0,1,3,5,6]
输出：3
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有3篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。

示例 2：
输入：citations = [1,2,100]
输出：2
 

提示：

n == citations.length
1 <= n <= 10^5
0 <= citations[i] <= 1000
citations 按 升序排列
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 参考灵茶山艾府的写法
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (citations[n - mid] >= mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
    vector<int> citations = {0,1,3,5,6};
    int res = Solution().hIndex(citations);
    cout << res << endl;
    return 0;
}

/**
 * @brief 复杂度分析
 * 时间复杂度：O(log⁡n)，其中 n 为 citations 的长度。
 * 每次循环，都会将二分范围减少一半，所以循环会执行 O(log⁡n)次，
 * 所以时间复杂度为 O(log⁡n)。
空间复杂度：O(1)。仅用到若干额外变量。

 */