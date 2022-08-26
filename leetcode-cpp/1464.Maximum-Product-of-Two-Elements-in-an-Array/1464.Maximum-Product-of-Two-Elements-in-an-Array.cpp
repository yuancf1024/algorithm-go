/**
 * @file 1464.Maximum-Product-of-Two-Elements-in-an-Array.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1464.数组中两元素的最大乘积
 * 
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，
使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。


示例 1：

输入：nums = [3,4,5,2]
输出：12 
解释：如果选择下标 i=1 和 j=2（下标从 0 开始），
则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
示例 2：

输入：nums = [1,5,4,5]
输出：16
解释：选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
示例 3：

输入：nums = [3,7]
输出：12
 

提示：

2 <= nums.length <= 500
1 <= nums[i] <= 10^3

 */

// 自己AC的代码
// 暴力搜索
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                res = max(res, (nums[i]-1)*(nums[j]-1));
            }
        }
        return res;
    }
};

// 方法1：排序
// 参考官方题解
class Solution {
public:
    int maxProduct(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        return (nums.back() - 1) * (nums[nums.size() - 2] - 1);
    }
};

// 排序的另一种解法
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 1, nums.end(), greater<>()); // 从大到小排序
        return (nums[0] - 1) * (nums[1] - 1);
    }
};

// 方法二：一次遍历，维护最大和次大值
class Solution {
public:
    int maxProduct(vector<int>& nums) { 
        int a = nums[0], b = nums[1];
        if (a < b) {
            swap(a, b);
        }
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
            } else if (nums[i] > b) {
                b = nums[i];
            }
        }
        return (b - 1) * (a - 1);
    }
};
/**
 * @brief
 *
方法1：排序
题目给定字符串nums，我们需要找到两个在数组不同位置的数减一后的乘积最大。
因为nums中的每一个元素都为正整数，所以为了使减一后的乘积最大，
我们选择数组中的两个最大的元素即可。
那么我们先对数组进行排序，然后选择两个最大的元素即可。

复杂度分析

时间复杂度：O(nlogn)，其中n为数组nums的长度，主要为数组排序的时间复杂度。
空间复杂度：O(1)，仅使用常量空间。


方法二：一次遍历，维护最大和次大值
思路与算法
因为我们只需要得到数组中两个最大的元素，
我们可以在从左到右遍历的过程中维护两个变量a,b
来表示遍历过程中的最大和次大元素，
那么一次遍历就可以得到数组中两个最大的元素。

复杂度分析
时间复杂度：O(n)，其中n为数组nums的长度，需要遍历一遍数组。
空间复杂度：O(1)，仅使用常量空间。
 */