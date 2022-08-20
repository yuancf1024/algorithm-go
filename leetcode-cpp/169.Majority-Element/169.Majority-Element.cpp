/**
 * @file 169.Majority-Element.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * leetcode-169.多数元素
给定一个大小为 n 的数组 nums ，
返回其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2
 

提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 */

// 2022-08-20 first
/*
思路：
1. 哈希表
用一个哈希表存储每个元素出现的次数，返回多数元素
unordered_map<int, int> key是nums元素，value是nums元素出现的次数
时间复杂度为 O(n)
空间复杂度为 O(n) 

2. 计数排序
用一个额外的vector vec来记录数组nums中的元素，
vec的下标为nums元素值，vec[i]代表元素出现次数。
然后返回vec[i] > nums.size()/2的下标i
*/

// 随机化
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums) {
                if (num == candidate) {
                    ++count;
                }
            }
            if (count > nums.size() / 2) {
                return candidate;
            }
        }
        return -1;
    }
};

// 计数排序 只能是排序的一种方法 做不到空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        vector<int> vec;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            vec[nums[i]]++;
        }
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] > n / 2) {
                res = i;
            }
        }
        return res;
    }
};

// 哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> umap;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            umap[nums[i]]++;
        }
        // unordered_map<int, int>::iterator
        for (auto it = umap.begin(); it != umap.end(); it++) {
            if (it->second > n / 2) {
                res = it->first;
            }
        }
        return res;
    }
};

/**
 * @brief 
 * 方法三：随机化
思路

因为超过⌊2/n⌋ 的数组下标被众数占据了，
这样我们随机挑选一个下标对应的元素并验证，有很大的概率能找到众数。

算法
由于一个给定的下标对应的数字很有可能是众数，我们随机挑选一个下标，
检查它是否是众数，如果是就返回，否则继续随机挑选。

复杂度分析
时间复杂度：理论上最坏情况下的时间复杂度为O(∞)，因为如果我们的运气很差，
这个算法会一直找不到众数，随机挑选无穷多次，所以最坏时间复杂度是没有上限的。
然而，运行的期望时间是线性的。为了更简单地分析，先说服你自己：
由于众数占据 超过 数组一半的位置，期望的随机次数会小于众数占据数组
恰好一半的情况。因此，我们可以计算随机的期望次数（下标为 prob 为原问题，
mod 为众数恰好占据数组一半数目的问题）：

E(iters_prob)≤E(iters_mod)= lim∑i⋅ (1/(2^i)) = 2
​
计算方法为：当众数恰好占据数组的一半时，第一次随机我们有1/2的概率找到众数，
如果没有找到，则第二次随机时，包含上一次我们有1/4的概率找到众数，
以此类推。因此期望的次数为 i * 1/{2^i}的和，可以计算出这个和为2，
说明期望的随机次数是常数。每一次随机后，我们需要O(n) 的时间判断这个数
是否为众数，因此期望的时间复杂度为O(n)。

空间复杂度：O(1)。随机方法只需要常数级别的额外空间。
 */