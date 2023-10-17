/**
 * @file 2652.Sum-Multiples.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2652. 倍数求和
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 给你一个正整数 n ，请你计算在 [1，n] 范围内能被 3、5、7 整除的所有整数之和。
返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。

示例 1：

输入：n = 7
输出：21
解释：在 [1, 7] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7 。数字之和为 21 。

示例 2：

输入：n = 10
输出：40
解释：在 [1, 10] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9、10 。数字之和为 40 。

示例 3：

输入：n = 9
输出：30

解释：在 [1, 9] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9 。数字之和为 30 。
 

提示：

1 <= n <= 10^3
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 实现思路和leetcode官方枚举法一致
    int sumOfMultiples(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
                ans += i;
            }
        }
        return ans;
    }

    // 方法2:容斥原理
    int f(int n, int m) {
        return (m + n / m * m) * (n / m) / 2;
    }
    int sumOfMultiples_v2(int n) {
        return f(n, 3) + f(n, 5) + f(n, 7) - f(n, 3*5) \
        - f(n, 3*7) - f(n, 5*7) + f(n, 3*5*7);
    }
};

int main() {
    int n = 9;
    int res = Solution().sumOfMultiples_v2(n);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 * 方法一：枚举
枚举 [1,n]范围内的所有整数，记当前枚举的数为 i，
如果 i mod 3=0或 i mod 5=0 或 i mod 7=0，
那么将 i 加到总和 res。

复杂度分析
时间复杂度：O(n)。
空间复杂度：O(1)。

方法二：容斥原理
考虑在区间 [1,n] 内能被数 m 整除的整数，
从小到大排序后成为一个等差数列，和为：

f(n,m)=(m+m×⌊n/m⌋)×⌊n/m⌋2 

根据 容斥原理，在区间 [1,n][内，
能被 3 、5 和7 整除的整数之和为：
f(n,3)+f(n,5)+f(n,7)−f(n,3×5)−f(n,3×7)−f(n,5×7)+f(n,3×5×7)

复杂度分析
时间复杂度：O(1)。
空间复杂度：O(1)。
 */