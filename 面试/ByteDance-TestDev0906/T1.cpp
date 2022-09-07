/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * 字节测开一面手撕算法题
 * 
 * 题目大意：一个整型数组，里面的每个数可以任意排列；
 * 求能够排列成的最大数字(可能会超过表示范围，用字符串存储)
 * 然后输出。
 * 注意：自己处理输入输出。
TestCase1:
9 16 32

93216

TestCase2：
10 36 18 9 20

936201810
 */

/*
面试时的思路：实际上就是排序，但是并不是数字本身直接排序，
而是按照每个数的最高位进行排序，如果最高位相同，再比较次高位
如：9>81, 36 > 350

2022-09-06复盘
面试时自己也知道光比较高位是不行的，因为当有多位数字时，这样就失效了；
看着我的这种思路，面试官也提醒我并指出问题，
但可能是面试时自己太紧张了，还是没有想出正确并AC。
只好放弃。

这一题实际上就是leetcode179&剑指offer45
没有做到原题😂哭死

思路：
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

反思总结：
这一题实际上思路还是非常常规和正常的，也很容易想到，
事实上自己思考的时候也是这样想的，
之所以没有实现出来，是因为:
1. 对字符串的处理还不熟练，字符串拼接(+),转换(to_string)
2. 没有深入理解sort函数，特别是第三个参数cmp，cmp函数可自行实现
3. 对于lambda表达式不熟练
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) { 
        vector<string> cpy;
        for (auto& x : nums) {
            cpy.push_back(to_string(x));
        }
        // 排序 比较两个数不同拼接顺序的结果 降序保存
        sort(cpy.begin(), cpy.end(),
             [](const string& a, const string& b) { 
                return a + b > b + a; 
        });

        string ans;
        if (cpy[0] == "0") {
            return "0";
        }
        for (auto& x : cpy) {
            ans += x;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, 9, 11, 23, 233, 911};
    // int n; // 数组多少个数
    // cin >> n;
    // int t;
    // while (n>0) {
    //     cin >> t;
    //     nums.push_back(t);
    //     n--;
    // }

    // 核心代码
    Solution s;
    // string res;
    string res = s.largestNumber(nums);
    cout << res << endl;

    return 0;
}