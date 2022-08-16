/**
 * @file 136.Single-Number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * leetcode-136.只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，
其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4

 */

// 方法1：位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int ret = 0;
        for (auto e : nums) {
            ret ^= e;
        }
        return ret;
    }
};

// 方法2：集合set
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        unordered_set<int> s;
        for (auto& num : nums) {
            if (!s.count(num)) {
                s.insert(num);
            } else {
                s.erase(num);
            }
        }
        return *s.begin();
    }
};

// 方法3：哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }
        for (auto& kv : m) {
            if (kv.second == 1) {
                res = kv.first;
            }
        }
        return res;
    }
};

// 方法4：使用集合存储数组中的所有元素
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int setSum = 0, numsSum = 0;
        unordered_set<int> s;
        for (auto& num : nums) {
            s.insert(num);
            numsSum += num;
        }
        for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            setSum += *it;
        }
        return 2 * (setSum)-numsSum;
    }
};

/**
 * @brief
 * 方法一：位运算
如果不考虑时间复杂度和空间复杂度的限制，这道题有很多种解法，
可能的解法有如下几种。

- 使用集合存储数字。遍历数组中的每个数字，如果集合中没有该数字，
则将该数字加入集合，如果集合中已经有该数字，则将该数字从集合中删除，
最后剩下的数字就是只出现一次的数字。

- 使用哈希表存储每个数字和该数字出现的次数。
遍历数组即可得到每个数字出现的次数，并更新哈希表，最后遍历哈希表，
得到只出现一次的数字。

- 使用集合存储数组中出现的所有数字，并计算数组中的元素之和。
由于集合保证元素无重复，因此计算集合中的所有元素之和的两倍，
即为每个元素出现两次的情况下的元素之和。由于数组中只有一个元素出现一次，
其余元素都出现两次，因此用集合中的元素之和的两倍减去数组中的元素之和，
剩下的数就是数组中只出现一次的数字。

上述三种解法都需要额外使用O(n) 的空间，其中n 是数组长度。

如何才能做到线性时间复杂度和常数空间复杂度呢？

答案是使用位运算。对于这道题，可使用异或运算⊕。异或运算有以下三个性质。

1. 任何数和0 做异或运算，结果仍然是原来的数，即 a⊕0=a。
2. 任何数和其自身做异或运算，结果是0，即 a⊕a=0。
3. 异或运算满足交换律和结合律，即a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

假设数组中有2m+1个数，其中有m个数各出现两次，一个数出现一次。
令a1、a2、…、am为出现两次的m 个数，am+1为出现一次的数。
根据性质3，数组中的全部元素的异或运算结果总是可以写成如下形式：

(a1⊕a1)⊕(a2⊕a2)⊕⋯⊕(am⊕am)⊕am+1
​
根据性质 2 和性质 1，上式可化简和计算得到如下结果：
0⊕0⊕⋯⊕0⊕am+1=am+1
​
因此，数组中的全部元素的异或运算结果即为数组中只出现一次的数字。

复杂度分析
时间复杂度：O(n)，其中n 是数组长度。只需要对数组遍历一次。
空间复杂度：O(1)。
 */