/**
 * @file 1413.Minimum-Value-to-Get-Positive-Step-by-Step-Sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1413.逐步求和得到正数的最小值
 * 
给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。

你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。

请你在确保累加和始终大于等于 1 的前提下，
选出一个最小的 正数 作为 startValue 。

示例 1：
输入：nums = [-3,2,-3,4,2]
输出：5
解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
                累加求和
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2

示例 2：
输入：nums = [1,2]
输出：1
解释：最小的 startValue 需要是正数。

示例 3：
输入：nums = [1,-2,-3]
输出：5
 
提示：

1 <= nums.length <= 100
-100 <= nums[i] <= 100

 */

// 模拟
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int x = 1;
        while (true) {
            
            vector<int> preSum(n, 0);
            preSum[0] = nums[0] + x;
            for (int i = 1; i < n; ++i) {
                preSum[i] = preSum[i - 1] + nums[i];
            }
            bool condition = true;
            for (auto i : preSum) {
                if (i < 1) { 
                    condition = false;
                    continue;
                }
            }
            if (condition == false) {
                x++;
                continue;
            } else {
                break;
            }
        }
    }
    return x;
};

// 方法一：贪心
class Solution {
public:
    int minStartValue(vector<int>& nums) { 
        int accSum = 0, accSumMin = 0;
        for (int num : nums) {
            accSum += num;
            accSumMin = min(accSumMin, accSum);
        }
        return 1 - accSumMin;
    }
};

// 方法二：二分查找
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        if (m >= 0) {
            return 1;
        }

        int left = 1, right = -m * nums.size() + 1;
        while (left < right) {
            int medium = left + ((right - left) >> 1);
            if (valid(medium, nums)) {
                right = medium; // 右边界左移
            } else {
                left = medium + 1;
            }
        }
        return left; // left一定满足要求
    }

    bool valid(int startValue, vector<int>& nums) {
        for (int num : nums) {
            startValue += num;
            if (startValue <= 0) {
                return false;
            }
        }
        return true;
    }
};

/**
 * @brief 
 * 根据题意暴力模拟.
 * 首先构造一个大循环，以便于递增startValue。
 * 声明preSum数组，存储startValue累加nums数组的和；
 * 遍历preSum，看是否有元素小于1：
 * - 如果有元素小于1，说明startValue还需要累加，进入下一次循环遍历；
 * - 如果没有元素小于1，那么startValue即为返回值，break循环，返回结果。
 * 

执行用时：8 ms, 在所有 C++ 提交中击败了11.39%的用户
内存消耗：10.8 MB, 在所有 C++ 提交中击败了5.06%的用户
通过测试用例：
55 / 55

复杂度分析：
时间复杂度: O() 因为不确定startValue最终到多少，所以无法确定
空间复杂度: O(N)

leetcode官方题解：

方法一：贪心  
思路
要保证所有的累加和 accSum 满足accSum + startValue ≥ 1，
只需保证累加和的最小值 accSumMin 满足 accSumMin+startValue ≥ 1，
那么 startValue 的最小值即可取 −accSumMin + 1。

笑哭😂: 我最开始的思路就是贪心，但是没有写出来，于是就暴力模拟。
没写出来，是因为没有反应过来：startValue应该是 1- accSumMin

复杂度分析
时间复杂度：O(n)，其中 n 是数组 nums 的长度。
只需要遍历数组一次。
空间复杂度：O(1)。只需要使用常量空间。

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了23.73%的用户
通过测试用例：55 / 55


方法二：二分查找
思路
当 nums 所有元素均为非负数时，可以直接返回 1。
当有负数时，可以

当某个数字满足startValue 的要求时，比它大的数字肯定也都满足，
比它小的数字则不一定能满足，因此 startValue 的性质具有单调性，
此题可以用二分查找来解决。二分查找的左起始点为 1，
右起始点可以设为 nums 的最小值的相反数乘上长度后再加 1，
这样可以保证右端点一定满足 startValue 的要求。

判断某个数字是否满足 startValue 的要求时，
可以将 nums 的数字逐步加到这个数字上，判断是否一直为正即可。

复杂度分析

时间复杂度：O(n×log(mn))，其中 n 是数组 nums 的长度，
m 是数组最小值的绝对值。二分查找的次数是 O(log(mn))，
每次消耗 O(n)。
空间复杂度：O(1)O(1)。只需要使用常量空间。

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了83.54%的用户
通过测试用例：
55 / 55
 */