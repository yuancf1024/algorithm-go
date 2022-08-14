/**
 * @file 6151.count-special-integers.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6151.统计特殊整数

如果一个正整数每一个数位都是 互不相同 的，
我们称它是 特殊整数 。

给你一个 正 整数 n ，
请你返回区间 [1, n] 之间特殊整数的数目。


示例 1：
输入：n = 20
输出：19
解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。

示例 2：
输入：n = 5
输出：5
解释：1 到 5 所有整数都是特殊整数。

示例 3：
输入：n = 135
输出：110
解释：从 1 到 135 总共有 110 个整数是特殊整数。
不特殊的部分数字为：22 ，114 和 131 。

提示：

1 <= n <= 2 * 109

 */

// 分类讨论 + 迭代
// 同样也不好理解
int f[11]{1}, fas[11]{0};
auto init = [] { 
    for (int i = 1; i < 11; ++i) {
        f[i] = f[i - 1] * i;
    }
    for (int i = 1; i < 10; ++i) {
        fas[i + 1] = fas[i] + 9 * f[9] / f[10 - i];
    }
    return 1;
}();
class Solution {
public:
    int countSpecialNumbers(int n) { 
        auto s = to_string(n);
        int mask = 0, k = s.size(), ans = 0;
        for (int q = 0; q < k; ++q) {
            int t = f[9 - q] / f[10 - k];
            if (q == 0 && (~mask & 1)) {
                ans -= t;
            }
            ans += t * __builtin_popcount(((1 << (s[q] - '0')) - 1) & ~mask);
            if (mask >> (s[q] - '0') & 1) {
                ans -= 1;
                break;
            }
            mask |= 1 << (s[q] - '0');
        }
        return ans + fas[k] + 1;
    }
};

/**
 * @brief @梦璃夜·天星
 * 分类讨论+迭代

- 对于位数与n相等的情况

从高位开始考虑。

1. 如果比n的对应位大，必然无解
2. 如果比n的对应位小，后续位可以任意填写（不重复即可），
可以直接全排列（这里预处理阶乘O(1) 求出。
而比n小的位有多少种情况，简单可以遍历 [0,s[i]) 统计出，
这样需要O(∣Σ∣)。 采用位运算，用标记位代表已经选择的数字，
可以通过__builtin_popcount(x) O(1) 求出。
3. 如果相等
    3.1. 如果这个数字未被使用，标记这个数字为已使用，
    考虑次高位，重复1~3步。
    3.2. 如果这个数字已被使用，那么证明不存在这种情况，
    并且不存在等于n的解，--ans并退出
注意到，这个过程中我们是没有考虑完全等于n 的情况的，
最后要把这个情况加上（+1）
如果相等不可行，在3退出时就已经减去了。

- 对于位数小于n的情况
对于每种长度分别计算全排列即可

注意最高位不能为0，因此最高位有9种可能，

次高位至末尾为9∗8∗...=f[9]/f[10−i] 其中 i 为总位数, 
f[i] 为!=i∗(i−1)∗...∗1

注意到，这部分同样可以预处理求出

时间复杂度：O(log10^n) 遍历十进制的每一位
空间复杂度：O(log10^n) 储存十进制的每一位
理论上空间这里可以优化到 O(1)O(1) ? 逐位取十进制最高位能O(1)做到吗 。
话说逆阶乘的复杂度有什么表示吗，应该到不了O(1) 至少也要存阶乘
 */

// 数位DP 好难理解
class Solution {
public:
    int countSpecialNumbers(int n) { 
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> f =
            [&](int i, int mask, bool isLimit, bool isNum) -> int {
            if (i == m)
                return isNum;
            if (!isLimit && isNum && dp[i][mask] >= 0)
                return dp[i][mask];
            int res = 0;
            if (!isNum)
                res = f(i + 1, mask, false, false); // 可以跳过当前数位
            for (int d = 1 - isNum, up = isLimit ? s[i] - '0' : 9; d <= up; ++d) {
                if ((mask >> d & 1) == 0) // d不在mask中
                    res += f(i + 1, mask | (1 << d), isLimit && d == up, true);
                if (!isLimit && isNum)
                    dp[i][mask] = res;
            }
            return res;
        };
        return f(0, 0, true, false);
    }
};

/**
 * @brief 
 * 参考大佬 @灵茶山艾府
本节讲了一种适用性很好的数位 DP 模板，以及如何使用该模板秒杀相关困难题目。
讲完题目后还讲了一些上分的训练技巧。

提供一个一般化的数位 DP 模板。

将 n 转换成字符串 s，定义f(i,mask,isLimit,isNum) 
表示从构造 n 从高到低第 i 位及其之后位的方案数，
其余参数的含义为：

- mask 表示前面选过的数字集合，换句话说，
第 i 位要选的数字不能在 mask 中。
- isLimit 表示当前是否受到了 n 的约束。
若为真，则第 i 位填入的数字至多为 s[i]，否则可以是 9。
- isNum 表示 i 前面的位数是否填了数字。
若为假，则当前位可以跳过（不填数字），
或者要填入的数字至少为 1；
若为真，则要填入的数字可以从 0 开始。
枚举要填入的数字，具体实现逻辑见代码。

 */

// 自己写的
// 哪里有bug 一直运行不出正确结果
class Solution {
public:
    int countSpecialNumbers(int n) { 
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i >= 1 && i <= 19) {
                res++;
            } else if (isAllEqual(i)) {
                res++;
            }
        }
        return res;
    }

    // 辅函数
    bool isAllEqual(int num) {
        bool flag = true;
        int one = 0;
        unordered_set<int> numSet;
        while (true) {
            one = num % 10; // 取个位数
            num = num / 10;
            if (numSet.count(one) >= 2) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

/*
思路：模拟
从1遍历到n，对每个数字的各个数位进行判断：
- 如果每一个数位都是 互不相同 的，res++
- 否则，跳出循环，遍历下一个数
*/