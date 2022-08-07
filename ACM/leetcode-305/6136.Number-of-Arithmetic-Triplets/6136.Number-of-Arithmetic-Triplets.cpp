/**
 * @file 6136.Number-of-Arithmetic-Triplets.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6136. 算术三元组的数目
 * 
给你一个下标从 0 开始、严格递增 的整数数组 nums 和一个正整数 diff 。
如果满足下述全部条件，则三元组 (i, j, k) 就是一个 算术三元组 ：

- i < j < k ，
- nums[j] - nums[i] == diff 且
- nums[k] - nums[j] == diff
返回不同 算术三元组 的数目。


示例 1：
输入：nums = [0,1,4,6,7,10], diff = 3
输出：2
解释：
(1, 2, 4) 是算术三元组：7 - 4 == 3 且 4 - 1 == 3 。
(2, 4, 5) 是算术三元组：10 - 7 == 3 且 7 - 4 == 3 。

示例 2：
输入：nums = [4,5,6,7,8,9], diff = 2
输出：2
解释：
(0, 2, 4) 是算术三元组：8 - 6 == 2 且 6 - 4 == 2 。
(1, 3, 5) 是算术三元组：9 - 7 == 2 且 7 - 5 == 2 。
 
提示：

3 <= nums.length <= 200
0 <= nums[i] <= 200
1 <= diff <= 50
nums 严格 递增

 */

//  2022-08-07 自己的糟糕表现 第一次周赛
// 暴力搜索
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        // int i, j, k;
        // 暴力搜索直接超时
        for (int i = 0; i < nums.size()-2; ++i) {
            for (int j = i+1; j < nums.size()-1; ++j) {
                if (nums[j]-nums[i] < diff) {
                    continue;
                }
                for (int k = j+1; j < nums.size(); ++k) {
                    if (nums[k] - nums[j] < diff) {
                        continue;
                    }
                    if (nums[j]-nums[i] == diff && nums[k]-nums[j] == diff) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

// 方法一：哈希表
// 类比两数之和
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) { 
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int x : nums) {
            // 枚举每一个nums[j]，查nums[i]=nums[j]-diff、nums[k]=nums[j]+diff是否在数组中即可
            if (s.count(x-diff) && s.count(x+diff)) {
                res++;
            }
        }
        return res;
    }
};

// 方法一：哈希表 + 1次遍历
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i]-diff) && s.count(nums[i]-2*diff)) {
                res++;
            }
            s.insert(nums[i]);
        }
        return res;
    }
};

// 方法二：三指针
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        int i = 0, j = 1;
        for (int k = 2; k < nums.size(); ++k) {
            while (nums[j]+diff<nums[k]) {
                j++;
            }
            if (nums[j]+diff > nums[k]) { // 其实我自己在优化暴力搜索的过程中就有三指针思路思想，可惜太菜了没有实现
                continue;
            }
            // 下面就是默认nums[j]+diff == nums[k] 的情况
            while (nums[i]+2*diff < nums[k]) {
                i++;
            }
            if (nums[i]+2*diff == nums[k]) {
                res++;
            }
        }
        return res;
    }
};

/**
 * @brief 参考大佬 @灵茶山艾府
 * 两种 O(n) 做法：哈希表 / 三指针
 * 
方法一：哈希表
用哈希表记录每个元素，然后遍历 nums，看 nums[j]−diff 和 nums[j]+diff 是否都在哈希表中。

复杂度分析
- 时间复杂度：O(n)，其中 n 为 nums 的长度。
- 空间复杂度：O(n)。

哈希表另解：一次遍历
改为遍历 nums[k]，这样加入哈希表的的同时可以顺带求出算术三元组，
从而做到一次遍历。

方法二：三指针
由于 nums 是严格递增的，遍历 nums[k] 时，i 和 j 只增不减，
因此可以用三个指针来实现判断逻辑。

复杂度分析
- 时间复杂度：O(n)，其中 n 为 nums 的长度。
- 空间复杂度：O(1)。仅需要几个额外的变量。
 */