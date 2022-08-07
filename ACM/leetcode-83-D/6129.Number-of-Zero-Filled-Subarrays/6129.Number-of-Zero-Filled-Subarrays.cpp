/* 6129. 全 0 子数组的数目
给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。

子数组 是一个数组中一段连续非空元素组成的序列。

示例 1：
输入：nums = [1,3,0,0,2,0,0,4]
输出：6
解释：
子数组 [0] 出现了 4 次。
子数组 [0,0] 出现了 2 次。
不存在长度大于 2 的全 0 子数组，所以我们返回 6 。

示例 2：
输入：nums = [0,0,0,2,0,0]
输出：9
解释：
子数组 [0] 出现了 5 次。
子数组 [0,0] 出现了 3 次。
子数组 [0,0,0] 出现了 1 次。
不存在长度大于 3 的全 0 子数组，所以我们返回 9 。

示例 3：
输入：nums = [2,10,2019]
输出：0
解释：没有全 0 子数组，所以我们返回 0 。
 
提示：

1 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) { 
        long ans = 0L;
        int c = 0;
        for (int num : nums) { // 遍历数组nums
            if (num) // 如果num不为0，将c置为0
                c = 0;
            else
                ans += ++c; // 记录该段右端点为0的连续子数组中0的个数
        }
        return ans;
    }
};

/*
解题思路：
- 思路1(参考@灵茶山艾府)：统计连续0组成的长度c，每个c可以贡献c个子数组。

> 这思路也太巧妙了。

子数组：知道左右端点，即可确定子数组。
直接枚举所有右端点，看以右端点结束的子数组的个数，即可求出。

case: 1 3 0 0 0 2 0 0 4

枚举到右端点index = 4时，统计到有几个0，那么以index=4的0为右端点的
子数组就有多少个。
*/


// 主函数
int main() { 
    // 在这里定义好函数中的测试数据
    int a[] = {0,0,0,2,0,0};
    vector<int> cost(a, a + sizeof(a) / sizeof(int));

    Solution solution;
    // 输出leetcode中的主函数
    cout << solution.zeroFilledSubarray(cost) << endl;
}