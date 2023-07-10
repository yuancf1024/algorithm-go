/**
 * @file 16.3Sum-Closest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-10
 * 
 * @copyright Copyright (c) 2023
 * 
 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
示例 2：

输入：nums = [0,0,0], target = 1
输出：0
 

提示：

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        // 根据差值的绝对值来更新答案
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        // 枚举a
        for (int i = 0; i < n; ++i) {
            // 保证和上一次枚举的元素不相等
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            // 使用双指针枚举b和c
            int j = i+1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // 如果和为target 直接返回答案
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum > target) {
                    // 如果和大于target，移动c对应的指针
                    int k0 = k - 1;
                    // 移动到下一个不相等的元素
                    while (j < k0 && nums[k0] == nums[k]) {
                        --k0;
                    }
                    k = k0;
                } else {
                    // 如果和小于target，移动b对应的指针
                    int j0 = j + 1;
                    // 移动到下一个不相等的元素
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++j0;
                    }
                    j = j0;
                }
            }
        }
        return best;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int res = Solution().threeSumClosest(nums, target);

    cout << res << endl;

    return 0;
}

/**
 * @brief 参考leetcode官方题解
 * 
方法一：排序 + 双指针
思路与算法

题目要求找到与目标值target最接近的三元组，
这里的「最接近」即为差值的绝对值最小。
我们可以考虑直接使用三重循环枚举三元组，
找出与目标值最接近的作为答案，时间复杂度为O(N^3)
。然而本题的N最大为1000，会超出时间限制。

那么如何进行优化呢？我们首先考虑枚举第一个元素a，
对于剩下的两个元素b和c，我们希望它们的和最接近
target−a。对于b和c，如果它们在原数组中枚举的范围
（既包括下标的范围，也包括元素值的范围）没有任何规律可言，
那么我们还是只能使用两重循环来枚举所有的可能情况。
因此，我们可以考虑对整个数组进行升序排序，这样一来：

- 假设数组的长度为n，我们先枚举a，它在数组中的位置为i；

- 为了防止重复枚举，我们在位置[i+1,n) 的范围内枚举b和c。

当我们知道了b和c可以枚举的下标范围，并且知道这一范围
对应的数组元素是有序（升序）的，那么我们是否可以
对枚举的过程进行优化呢？

答案是可以的。借助双指针，我们就可以对枚举的过程进行优化。
我们用p_b和p_c分别表示指向b和c的指针，初始时，
p_b指向位置i+1，即左边界；p_c指向位置n−1，即右边界。
在每一步枚举的过程中，我们用a+b+c来更新答案，并且：

- 如果 a+b+c≥target，那么就将p_c向左移动一个位置；

- 如果 a+b+c<target，那么就将p_b向右移动一个位置。

这是为什么呢？我们对 a+b+c≥target的情况进行一个详细的分析：

> 如果 a+b+c≥target，并且我们知道p_b到p_c这个范围内
的所有数是按照升序排序的，那么如果p_c不变而p_b向右移动，
那么a+b+c的值就会不断地增加，显然就不会成为最接近 target的值了。
因此，我们可以知道在固定了p_c的情况下，此时的p_b
就可以得到一个最接近target的值，那么我们以后就
不用再考虑p_c了，就可以将p_c向左移动一个位置。

同样地，在 a+b+c<target时：

> 如果 a+b+c<target，并且我们知道p_b到p_c这个范围内的
所有数是按照升序排序的，那么如果p_b不变而p_c向左移动，
那么a+b+c的值就会不断地减小，显然就不会成为最接近 target 的值了。
因此，我们可以知道在固定了p_b的情况下，此时的p_c就可以得到
一个最接近target的值，那么我们以后就不用再考虑p_b了，
就可以将p_b向右移动一个位置。

实际上，p_b和p_c就表示了我们当前可以选择的数的范围，
而每一次枚举的过程中，我们尝试边界上的两个元素，
根据它们与target的值的关系，选择「抛弃」左边界的元素
还是右边界的元素，从而减少了枚举的范围。
这种思路与 11.盛最多水的容器 中的双指针解法
也是类似的。

小优化

本题也有一些可以减少运行时间（但不会减少时间复杂度）
的小优化。当我们枚举到恰好等于target的a+b+c作为答案，
因为不会有再比这个更接近的值了。

另一个优化与 15.三数之和的官方题解 中提到的类似。
当我们枚举a,b,c中任意元素并移动指针时，
可以直接将其移动到下一个与这次枚举到的不相同的元素，
减少枚举的次数。

 */