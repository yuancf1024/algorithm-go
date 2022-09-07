/**
 * @file 179.Largest-Number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022
 * 
 * leetcode-179.最大数
 * 
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）
使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

示例 1：
输入：nums = [10,2]
输出："210"

示例 2：
输入：nums = [3,30,34,5,9]
输出："9534330"

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 109

 */

// 自定义排序
class Solution {
public:
    /*
    static bool cmp(string& a, string& b) {
        return a + b > b + a;
    }
    */
    string largestNumber(vector<int>& nums) { 
        vector<string> cpy;
        for (auto& x : nums) {
            cpy.push_back(to_string(x));
        }
        // sort(cpy.begin(), cpy.end(), cmp);
        // 使用lambda表达式
        sort(cpy.begin(), cpy.end(),
             [](const string& a, const string& b) { 
                return a + b > b + a; // 降序排序
        });
        string ans;
        bool start = 1;
        for (auto& x : cpy) {
            if (start) {
                if (x == "0") { // 考虑没有元素的数组 
                    continue;
                }
                else {
                    start = 0;
                }
            }
            ans += x;
        }
        return ans.size() ? ans : "0";
    }
};

// 自定义排序 简洁版
class Solution {
public:
    string largestNumber(vector<int>& nums) { 
        vector<string> cpy;
        for (auto& x : nums) cpy.push_back(to_string(x));
        sort(cpy.begin(), cpy.end(),
             [](const string& a, const string& b) { return a + b > b + a; });
        if (cpy[0] == "0") return "0"; // 因为根据排序不会出现比0还小的在0后面，所以第一个为零就是全零 后面直接这样写就行
        string ans;
        for (auto& x : cpy) ans += x;
        return ans;
    }
};

// 参考leetcode官方题解 使用lambda表达式实现了一个巧妙的函数
// 比较两个数不同的拼接顺序的结果
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) { 
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x; // 这里的处理技巧很棒前面是xy连接，后面是yx连接
        });

        if (nums[0] == 0) {
            return "0";
        }
        string ret;
        for (auto& x : nums) {
            ret += to_string(x);
        }
        return ret;
    }
};

/**
 * @brief 
 * 方法一：排序
思路与算法

要想组成最大的整数，一种直观的想法是把数值大的数放在高位。
于是我们可以比较输入数组的每个元素的最高位，最高位相同的时候比较次高位，
以此类推，完成排序，然后把它们拼接起来。
这种排序方式对于输入数组 没有相同数字开头 的时候是有效的，
例如 [45, 56, 81, 76, 123]。

下面考虑输入数组 有相同数字开头 的情况，
例如[4,42] 和[4,45]。

对于[4,42]，比较442>424，需要把 4 放在前面；
对于[4,45]，比较445<454，需要把 45 放在前面。

因此我们需要比较两个数不同的拼接顺序的结果，
进而决定它们在结果中的排列顺序。

由于需要拼接以后才能决定两个数在结果中的先后顺序，
N 个数就有N! 种拼接的可能，我们是不是需要先得到N 个数的全排列以后，
再选出最大的呢？答案是没有必要。
上述排序规则满足传递性，两个元素比较就可以确定它们在排序以后的相对位置关系。
下面证明这种排序规则的必要性和充分性。

证明

定义一种非负整数集合上的二元运算，记作⊕，它表示将两个数拼接后的结果。

具体地，我们令s(x)表示大于非负整数x的最小的十的整次幂
（即当x>0 时 s(x)=10^{log_{10}x + 1}，
特别地，s(0)=10），那么 x⊕y=x×s(y)+y。
显然这样的运算不满足交换律，但是满足结合律。

然后我们定义一个非负整数集合上的二元关系，记作Θ。
当一个数x排在数y前面更优时（即x⊕y≥y⊕x），我们认为xΘy。

我们知道，一个序列要能够正确地自定义排序，
需要这种排序规则满足传递性（如果aΘb 且bΘc 则 aΘc）
和完全性（即aΘb或bΘa必满足其一）。
只要证明了传递性和完全性，即可证明该排序规则的必要性，完全性很容易证明，
传递性证明如下：

由aΘb且bΘc 可知：

a×s(b)+b≥b×s(a)+a
b×s(c)+c≥c×s(b)+b
移项整理得：

a×(s(b)−1)≥b×(s(a)−1)
b×(s(c)−1)≥c×(s(b)−1)

两式的左右两边均非负，因此由两式相乘可得：
a×b×(s(b)−1)×(s(c)−1)≥b×c×(s(a)−1)×(s(b)−1)

不等式两边都有b，根据b是否为0分类讨论：

当b=0时：
将b=0代入bΘc 可知：c≥c×10，即 c=0；

当c=0时，有a×s(c)+c≥c×s(a)+a，恰符合aΘc 的定义。

当b>0 时：
b×(s(b)−1))>0；

不等式两边同时除以 b×(s(b)−1))，化简得：
a×(s(c)−1)≥c×(s(a)−1)，恰符合aΘc的定义。

综上，有aΘc。

最后我们证明该排序规则的充分性：假设存在一个最优序列不满足该排序规则，
那么必然存在至少一对相邻数字a与b，我们将a与b交换后新序列的值必然增加，
与假设矛盾。因此，满足该排序规则是该序列最优的充分条件。

复杂度分析
时间复杂度：O(nlogn logm)，其中n是给定序列的长度，m 是32位整数的最大值，
每个数转化为字符串后的长度是O(logm) 的数量级。

排序比较函数的时间复杂度为O(logm)，共需要进行O(nlogn) 次比较。
同时我们需要对字符串序列进行拼接，时间复杂度为 O(nlogm)，
在渐进意义上小于O(nlognlogm)。

我们也可以对排序比较函数进行优化，
如预处理出数组每一个数的大于它的最小的十的整次幂，
这样可用将时间复杂度降低到O(nlogn)，但这样会使得空间复杂度上升到O(n)。

我们也可以使用数学方法加速计算整次幂，如二分计算等，但这种优化常数较大，
最终耗时不一定更短。

空间复杂度：O(logn)，排序需要O(logn) 的栈空间。

 */

