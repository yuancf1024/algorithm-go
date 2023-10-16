/**
 * @file 260.Single-Number-III.cpp
 * @author your name (you@domain.com)
 * @brief 260. 只出现一次的数字 III
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 * 给你一个整数数组 nums，其中恰好有两个元素只出现一次，
 * 其余所有元素均出现两次。 找出只出现一次的那两个元素。
 * 你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。

示例 2：

输入：nums = [-1,0]
输出：[-1,0]

示例 3：

输入：nums = [0,1]
输出：[1,0]
 
提示：

2 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
除两个只出现一次的整数外，nums 中的其他数字都出现两次
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 方法一：哈希表
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        // for (const auto& [num, occ] : freq) {
        //     if (occ == 1) {
        //         ans.push_back(num);
        //     }
        // }
        // 遍历哈希表
        for (auto & num : freq) {
            if (num.second == 1) {
                ans.push_back(num.first);
            }
        } 
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> res = Solution().singleNumber(nums);
    // 打印结果
    for (auto& num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/**
 * @brief leetcode官方题解
 * 方法一：哈希表
思路与算法

我们可以使用一个哈希映射统计数组中每一个元素出现的次数。

在统计完成后，我们对哈希映射进行遍历，将所有只出现了一次的数放入答案中。

复杂度分析

时间复杂度：O(n)，其中 n 是数组 nums 的长度。

空间复杂度：O(n)，即为哈希映射需要使用的空间。



 */