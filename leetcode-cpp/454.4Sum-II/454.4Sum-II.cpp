/* 454. 四数相加 II

给你四个整数数组 nums1、nums2、nums3 和 nums4 ，
数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n

nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 
示例 1：

输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2

解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

示例 2：

输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
 

提示：

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28

*/

// 参考代码随想录 哈希
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap; // key: a+b的数值，value: a+b数值出现的次数
        // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0; // 统计a+b+c+d = 0 出现的次数
        // 在遍历大C和大D数组，找到如果0-(c+d)在map中出现过的话，就把map中key对应的value也就是出现次数统计出来
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - (c+d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

/*
思路

本题咋眼一看好像和0015.三数之和 ，0018.四数之和 差不多，其实差很多。

本题是使用哈希法的经典题目，而0015.三数之和 ，0018.四数之和 并不合适使用哈希法，
因为三数之和和四数之和这两道题目使用哈希法在不超时的情况下做到对结果去重是很困难的，
很有多细节需要处理。

而这道题目是四个独立的数组，只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，
不用考虑有重复的四个元素相加等于0的情况，所以相对于题目18. 四数之和，题目15.三数之和，还是简单了不少！

如果本题想难度升级：就是给出一个数组（而不是四个数组），
在这里找出四个元素相加等于0，答案中不可以包含重复的四元组，
大家可以思考一下，后续的文章我也会讲到的。

本题解题步骤：

1. 首先定义 一个unordered_map，key放a和b两数之和，
value 放a和b两数之和出现的次数。

2. 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。

3. 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。

4. 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，
就用count把map中key对应的value也就是出现次数统计出来。

5. 最后返回统计值 count 就可以了
*/