/**
 * @file 2208.Minimum-Operations-to-Halve-Array-Sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-25
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个正整数数组nums。每一次操作中，你可以从
nums 中选择 任意 一个数并将它减小到 恰好 一半。
（注意，在后续操作中你可以对减半过的数继续执行操作）

请你返回将 nums 数组和 至少 减少一半的 最少 操作数。

示例 1：
输入：nums = [5,19,8,1]
输出：3
解释：初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
以下是将数组和减少至少一半的一种方法：
选择数字 19 并减小为 9.5 。
选择数字 9.5 并减小为 4.75 。
选择数字 8 并减小为 4 。
最终数组为 [5, 4.75, 4, 1] ，
和为 5 + 4.75 + 4 + 1 = 14.75 。
nums 的和减小了 33 - 14.75 = 18.25 ，
减小的部分超过了初始数组和的一半，18.25 >= 33/2 = 16.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。

示例 2：
输入：nums = [3,8,20]
输出：3
解释：初始 nums 的和为 3 + 8 + 20 = 31 。
以下是将数组和减少至少一半的一种方法：
选择数字 20 并减小为 10 。
选择数字 10 并减小为 5 。
选择数字 3 并减小为 1.5 。
最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
nums 的和减小了 31 - 14.5 = 16.5 ，
减小的部分超过了初始数组和的一半， 16.5 >= 31/2 = 16.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。
 
提示：

1 <= nums.length <= 105
1 <= nums[i] <= 107

 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        int res = 0;
        double sum = accumulate(nums.begin(), nums.end(), 0.0), sum2 = 0.0;
        while (sum2 < sum / 2) {
            double x = pq.top();
            pq.pop();
            sum2 += x / 2;
            pq.push(x / 2);
            res++;
        }
        return res;
    }
};

int main() {
    // vector<int> nums = {5, 19, 8, 1};
    vector <int> nums;
    nums.push_back(5);
    nums.push_back(19);
    nums.push_back(8);
    nums.push_back(1);

    int res = Solution().halveArray(nums);

    cout << res << endl;

    return 0;
}

/**
 * @brief 官方题解
 * 方法一：贪心 + 优先队列
基于贪心的思想，将数组和减半的操作次数最小化的做法为：
每次操作都选择当前数组的最大值进行减半操作。

证明：
假设某一种做法（该做法操作次数最小）的某一步操作
没有选择对最大值x进行操作，而是选择对y进行操作，
那么有两种情况：
1.后续的操作都没有选择对 x 进行操作，
那么我们将后续（包括当前操作）所有对y 的操作替换
成对 x 的操作，操作次数不变；
2.后续的某一步操作选择对x进行操作，
那么我们可以交换这两步操作，操作次数不变。

将数组所有元素都放入一个浮点数优先队列（最大堆）中，
使用sum记录初始数组和，sum2记录减少和，当 
sum2<sum/2时，重复以下步骤：

1)从优先队列中取出最大元素x；
2)令sum2=sum2+x/2;
3)将x/2放入优先队列中。
返回执行步骤次数即可。
复杂度分析

时间复杂度：O(nlogn)，其中n是数组nums的长度。
将数组和减半最多不超过n 次操作，每次操作需要O(logn)。

空间复杂度：
O(n)。保存优先队列需要 O(n) 的空间。
 */