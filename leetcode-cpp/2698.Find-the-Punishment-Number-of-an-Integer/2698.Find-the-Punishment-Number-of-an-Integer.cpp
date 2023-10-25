/**
 * @file 2698.Find-the-Punishment-Number-of-an-Integer.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2698.求一个整数的惩罚数
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 给你一个正整数 n ，请你返回 n 的 惩罚数 。

n 的 惩罚数 定义为所有满足以下条件 i 的数的平方和：

1 <= i <= n
i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i 。
 

示例 1：
输入：n = 10
输出：182
解释：总共有 3 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
因此，10 的惩罚数为 1 + 81 + 100 = 182

示例 2：
输入：n = 37
输出：1478
解释：总共有 4 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
- 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6 。
因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478
 
提示：

1 <= n <= 1000
 */

#include <bits/stdc++.h>

using namespace std;

inline bool check1(int t, int x) {
    if (t == x) return true;
    int d = 10;
    while (t >= d && t % d <= x) {
        if (check1(t / d, x - (t % d))) return true;
        d *= 10;
    }
    return false;
}

int f[1010];
int _ = []() {
    for (int i = 1; i < 1010; i++) {
        f[i] = f[i-1];
        if (check1(i * i, i)) f[i] += i * i;
    }
    return 0;
}();
class Solution {
public:
    // 方法1:递归
    bool check(int t, int x) {
        if (t == x) return true;
        int d = 10;
        while (t >= d && t % d <= x) {
            if (check(t / d, x - (t % d))) return true;
            d *= 10;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i * i, i)) ans += i * i;
        }
        return ans;
    }

    // 打表
    int punishmentNumber_v2(int n) {
        return f[n];
    }
};

int main() {
    int n = 37;
    int res = Solution().punishmentNumber_v2(n);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 * 方法1:递归
 * 一个朴素的做法是遍历 [1,i]，若当前数值 i 满足要求，
 * 则将 i×i累加到答案中。

问题关键转为：如何判定 i×i是否能够分割成多个整数，使其累加值为 i。

简单做法是通过递归来做：每次从当前值的低位开始截取，
通过「取余」和「地板除」操作，得到截取部分和剩余部分，
再继续递归处理。

时间复杂度：O(nlog⁡n^2)
空间复杂度：O(log⁡n^2)

方法2: 打表

更进一步，对于 [1,x] 范围内的惩罚数必然包含了 [1,y]（其中 y<x）中的惩罚数。

即多个样例之间必然存在重复计算，我们可通过「打表」进行预处理：
定义 f[i]为 n=i时的答案（惩罚数），
对于 f[i] 而言，起始为 f[i−1]，
若数值 i 本身满足要求，则将 i×i累加到 f[i] 当中。

时间复杂度：O(1)
空间复杂度：O(C)，其中 C=1000

 */