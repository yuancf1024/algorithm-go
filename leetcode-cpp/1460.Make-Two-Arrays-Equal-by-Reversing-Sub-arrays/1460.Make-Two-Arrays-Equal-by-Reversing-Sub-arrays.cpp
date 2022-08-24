/**
 * @file 1460.Make-Two-Arrays-Equal-by-Reversing-Sub-arrays.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1460.通过翻转子数组使两个数组相等
 * 
给你两个长度相同的整数数组 target 和 arr 。
每一步中，你可以选择 arr 的任意 非空子数组 并将它翻转。
你可以执行此过程任意次。

如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。

示例 1：
输入：target = [1,2,3,4], arr = [2,4,1,3]
输出：true

解释：你可以按照如下步骤使 arr 变成 target：
1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。

示例 2：
输入：target = [7], arr = [7]
输出：true
解释：arr 不需要做任何翻转已经与 target 相等。

示例 3：
输入：target = [3,7,9], arr = [3,7,11]
输出：false
解释：arr 没有数字 9 ，所以无论如何也无法变成 target 。
 
提示：

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000

 */

// 方法一：哈希表判断数组元素是否相同
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> counts1, counts2;
        for (int num : target) {
            counts1[num]++;
        }
        for (int num : arr) {
            counts2[num]++;
        }
        if (counts1.size() != counts2.size()) {
            return false;
        }
        for (auto& [key, value] : counts1) {
            if (!counts2.count(key) || counts2[key] != value) {
                return false;
            }
            return true;
        }
    }
};

// 方法二：排序判断数组元素是否相同
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr){
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
}; 


    /**
     * @brief 参考leetcode题解
     * 方法一：哈希表判断数组元素是否相同
    思路

    如果arr 长度是1，那么只需判断arr 和target 是否相同即可。
    因为此时翻转非空子数组的过程并不会改变数组，
    只需判断原数组是否相同即可。

    如果arr长度大于1，那么首先证明通过一次或二次翻转过程，
    可以实现数组arr 中任意两个元素交换位置并且保持其他元素不动。
    如果想要交换两个相邻元素的位置，那么翻转这两个元素组成的子数组即可。
    如果想要交换两个非相邻元素的位置，
    那么首先翻转这两个元素及其中间所有元素组成的子数组，
    再翻转这两个元素中间的元素组成的子数组即可。
    这样下来，通过一次或二次翻转过程，即可交换数组中任意两个元素的位置。
    一旦一个数组中任意两个元素可以交换位置，那么这个数组就能实现任意重排。
    只需要arr 和target 元素相同，}arr 就能通过若干次操作变成target。

    复杂度分析
    时间复杂度：O(n)，其中n 是输入数组的长度，
    统计并判断频次是否相同消耗O(n)。
    空间复杂度：O(n)，哈希表最多消耗O(n) 空间。


    方法二：排序判断数组元素是否相同
    思路

    与方法一类似，但是判断元素是否相同时，
    可以将两个数组分别排序，再判断排完序的数组是否相同即可。

    复杂度分析
    时间复杂度：O(n×logn)，其中n 是输入数组的长度。
    排序消耗O(n×logn) 复杂度，判断是否相同消耗O(n) 复杂度。

    空间复杂度：O(logn)，快速排序递归深度平均为O(logn)。

     */