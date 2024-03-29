# 2022-08-24中兴笔试复盘

## 笔试细节

- 20道选择题，6道多选题。
- 2道编程题，基本上是leetcode原题，分别是lcZ 字形变换和lc198打家劫舍。

选择题基本上考察的是Java相关的知识点，OOP、小程序、操作系统、计网、内存对齐之类的题目。

> T1: leetcode-6.Z字形变换, 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。


## 编程题目：第一题
自己想要手动模拟，先构建二维矩阵，然后模拟实现N字形的布置.
但是我没有找到N自行布置的周期：

> 当我们在矩阵上填写字符时，会向下填写r 个字符，然后向右上继续填写 r−2 个字符，最后回到第一行.

因为对于布置r行而言，r在没有输入之前未知，我想每行构造1个for循环来根据下标填入相应的字符；
实际上，正确的思路应该是竖直向下，按照原字符串的顺序来依次布置字符，考虑周期性，一个for循环即可解决。

**本题难点：找到Z字形变换的周期，然后处理每个周期内的字符，同时向下和右上移动的技巧**

```cpp
// 方法一：利用二维矩阵模拟
class Solution {
public:
    string convert(string s, int numRows) { 
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) { // 考虑边界情况
            return s;
        }
        int t = r * 2 - 2; // Z 字形变换的周期
        int c = (n + t - 1) / t * (r - 1); // 一共会有多少列
        vector<string> mat(r, string(c, 0));

        for (int i = 0, x = 0, y = 0; i < n; ++i) {
            mat[x][y] = s[i];
            if (i % t < r-1) {
                ++x; // 向下移动
            } else {
                --x;
                ++y; // 向右上移动
            }
        }
        string ans;
        for (auto& row : mat) {
            for (char& ch : row) {
                if (ch) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};
```


## 编程题目：第二题 向前冲，求能拿到的最小金币数. 

实际上就是打家劫舍的改编，相邻数组的元素不能取，问如何才能取到最大值？

> 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
> 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

本题自己做过，印象虽然不深刻，但是也知道是用DP

DP公式也写对了: dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

但是部分测试案例没有通过，于此同时中兴的笔试平台看不到测试结果及返回信息，所以不知道是边界测试出错还是递推的逻辑出错。

事实上，是我没有单独考虑数组只有1个元素和2个元素的case，导致部分TestCase未通过。

> Update: 经过Debug验证发现，不是没有考虑特殊Case，而是我处理输入数据不当导致出现bug，因为部分案例不能通过。

**含右bug的代码**
```cpp
// 读取数据会有问题
// 按照字符串的格式输入数据
string s;
cin >> s;
// 这样处理字符串会有一个毛病：不能正常解析2位数的数字
for (int i = 0; i < s.size(); ++i) {
    if (i % 2 == 0) {
        nums.push_back(int(s[i] - '0'));
    }
}
// TestCase1 1,2,3,1 正常读入
// TestCase2 1,5,3,1,1,10 会把10读成 1

```


**正确代码**
```cpp
// 读取逗号分隔的数字
// 如 1,5,3,1,1,10
vector<int> nums;
int temp;
while (cin >> temp) {
    nums.push_back(temp);
    if (cin.get() == '\n'){
        break;
    }
}

// 打家劫舍核心代码
int rob(vector<int>& nums) {
    if (nums.size() == 0) // 输入数组没有元素
        return 0;
    if (nums.size() == 1) // 输入数组仅有一个元素的case
        return nums[0];
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
}
```


## 总结

笔试基本上是leetcode的拓展或者非常灵活的原创题,平时的训练基本都有涵盖,
掌握好Hot100+剑指offer以及Top300,应付简单的笔试问题不大,近期加快复习节奏,
从容应对企业笔试,与此同时,也要尽快熟悉ACM格式的处理输入输出,特别是链表, 二叉树, 图等
复杂数据结构.