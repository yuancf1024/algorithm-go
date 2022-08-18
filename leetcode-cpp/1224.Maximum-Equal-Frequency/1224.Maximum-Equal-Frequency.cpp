/**
 * @file 1224.Maximum-Equal-Frequency.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1224.最大相等频率
给你一个正整数数组 nums，请你帮忙从该数组中找出能满足
下面要求的 最长 前缀，并返回该前缀的长度：

- 从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
- 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的
出现次数（也就是 0 次）。


示例 1：
输入：nums = [2,2,1,1,5,3,3,5]
输出：7

解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，
如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，
里面每个数字都出现了两次。

示例 2：
输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
输出：13
 
提示：

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

 */

// 方法一：哈希表
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) { 
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count[nums[i]] > 0) { // 这个的作用: 出现次数为count[nums[i]]+1的频率后面会加1，那么对应count[nums[i]]的频率就会减少1
                freq[count[nums[i]]]--;
            }
            // 注意自增顺序：次数先自增，次数对应的频率再自增
            count[nums[i]]++; // 使用哈希表count 记录数x 出现的次数count[x]
            maxFreq = max(maxFreq, count[nums[i]]); // maxFreq 表示最大出现次数
            freq[count[nums[i]]]++; // freq 记录出现次数为f 的数的数目为freq[f]
            bool ok =
                maxFreq == 1 || // 最大出现次数maxFreq=1
                freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 || // 所有数的出现次数都是maxFreq 或 maxFreq−1，并且最大出现次数的数只有一个
                freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1; // 除开一个数，其他所有数的出现次数都是maxFreq，并且该数的出现次数为1
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
/**
freq[maxFreq] * maxFreq + 1 == i + 1
maxFreq 表示最大出现次数
freq[maxFreq] 表示最大出现次数的数字的频率
 */


/**
 * @brief 
 * 方法一：哈希表
使用哈希表count 记录数x 出现的次数count[x]，
freq 记录出现次数为f 的数的数目为freq[f]，maxFreq 表示最大出现次数。

依次遍历数组，假设当前访问的数为 nums[i]，对应地更新 count，
freq 以及 maxFreq。以 nums[i] 结尾的数组前缀符合要求的充要条件
为满足以下三个条件之一：

- 最大出现次数maxFreq=1：那么所有数的出现次数都是一次，
随意删除一个数既可符合要求。

- 所有数的出现次数都是maxFreq 或 maxFreq−1，并且最大出现次数的数
只有一个：删除一个最大出现次数的数，那么所有数的出现次数都是maxFreq−1。

- 除开一个数，其他所有数的出现次数都是maxFreq，并且该数的出现次数为1：
直接删除出现次数为1 的数，那么所有数的出现次数都是 maxFreq。

复杂度分析
时间复杂度：O(n)，其中n 是数组nums 的长度。遍历数组nums 需要O(n)。
空间复杂度：O(n)。保存两个哈希表需要O(n) 的空间。
 */