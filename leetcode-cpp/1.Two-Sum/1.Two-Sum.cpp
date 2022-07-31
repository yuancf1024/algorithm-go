// Source : https://leetcode-cn.com/problems/two-sum/
// Author : Hao Chen
// Date   : 2014-06-17

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/

/*
    *   The easy solution is O(n^2) run-time complexity.
    *   ```
    *       foreach(item1 in array) {
    *           foreach(item2 in array){
    *               if (item1 + item2 == target) {
    *                   return result
    *               }
    *           }
    *   ```
    *   
    *   We can see the nested loop just for searching, 
    *   So, we can use a hashmap to reduce the searching time complexity from O(n) to O(1)
    *   (the map's `key` is the number, the `value` is the position)
    *   
    *   But be careful, if there are duplication numbers in array, 
    *   how the map store the positions for all of same numbers?
    *
    */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // The implementation as below is bit tricky. but not difficult to understand
    //
    //  1) Traverse the array one by one
    //  2) just put the `target - num[i]`(not `num[i]`) into the map
    //     so, when we checking the next num[i], if we found it existed in the map,
    //     it means we found the second one.
    //

    // we also can store nums[i] into map, and find target - nums[i]
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) == m.end()) { // 没有找到 target - nums[i]
                m[nums[i]] = i;
            } else {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
        }
        return result;
    }
};

/* 1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，
并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里
不能重复出现。

你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
 
提示：

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
只会存在一个有效答案

进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/

// 参考代码随想录
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // 数组中的元素作为key, 下标当作value
        for (int i = 0; i < nums.size(); i++) {
            // 遍历当前元素,并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) { // 找到了
                return {iter->second, i};
            }
            // 如果没有找到匹配对,就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

/*
思路

242. 有效的字母异位词 这道题目是用数组作为哈希表来解决哈希问题，
349. 两个数组的交集 这道题目是通过set作为哈希表来解决哈希问题。

首先我在强调一下 什么时候使用哈希法，当我们需要查询一个元素是否出现过，
或者一个元素是否在集合里的时候，就要第一时间想到哈希法。

本题呢，我就需要一个集合来存放我们遍历过的元素，然后在遍历数组的时候
去询问这个集合，某元素是否遍历过，也就是 是否出现在这个集合。

那么我们就应该想到使用哈希法了。

因为本地，我们不仅要知道元素有没有遍历过，还有知道这个元素对应的下标，
需要使用 key value结构来存放，key来存元素，value来存下标，
那么使用map正合适。

再来看一下使用数组和set来做哈希法的局限。

- 数组的大小是受限制的，而且如果元素很少，而哈希值太大会造成内存空间的浪费。
- set是一个集合，里面放的元素只能是一个key，而两数之和这道题目，
不仅要判断y是否存在而且还要记录y的下标位置，因为要返回x 和 y的下标。所以set 也不能用。

此时就要选择另一种数据结构：map ，map是一种key value的存储结构，
可以用key保存数值，用value在保存数值所在的下标。

std::unordered_map 底层实现为哈希表，
std::map 和std::multimap 的底层实现是红黑树。

同理，std::map 和std::multimap 的key也是有序的
（这个问题也经常作为面试题，考察对语言容器底层的理解）。

这道题目中并不需要key有序，选择std::unordered_map 效率更高！ 
使用其他语言的录友注意了解一下自己所用语言的数据结构就行。

接下来需要明确两点：

- map用来做什么
- map中key和value分别表示什么

map目的用来存放我们访问过的元素，因为遍历数组的时候，需要记录我们之前
遍历过哪些元素和对应的下标，这样才能找到与当前元素相匹配的（也就是相加等于target）

接下来是map中key和value分别表示什么。

这道题 我们需要 给出一个元素，判断这个元素是否出现过，如果出现过，返回这个元素的下标。

那么判断元素是否出现，这个元素就要作为key，所以数组中的元素作为key，
有key对应的就是value，value用来存下标。

所以 map中的存储结构为 {key：数据元素，value：数组元素对应的下表}。

在遍历数组的时候，只需要向map去查询是否有和目前遍历元素比配的数值，
如果有，就找到的匹配对，如果没有，就把目前遍历的元素放进map中，
因为map存放的就是我们访问过的元素。

*/