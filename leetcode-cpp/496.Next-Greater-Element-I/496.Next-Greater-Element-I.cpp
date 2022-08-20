/**
 * @file 496.Next-Greater-Element-I.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * leetcode-496.下一个更大元素 I
 * 
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 
第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，
下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，
找出满足 nums1[i] == nums2[j] 的下标 j ，
并且在 nums2 确定 nums2[j] 的 下一个更大元素 。
如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，
满足 ans[i] 是如上所述的 下一个更大元素 。

 
示例 1：
输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]

解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。

示例 2：
输入：nums1 = [2,4], nums2 = [1,2,3,4].
输出：[3,-1]

解释：nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。

提示：

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中
 

进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length)
的解决方案吗？

 */

// 单调栈 详细版
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res(nums1.size(), -1);
        if (nums1.size() == 0) {
            return res;
        }

        unordered_map<int, int> umap; // key: 下标元素，value: 下标
        for (int i = 0; i < nums1.size(); ++i) {
            umap[nums1[i]] = i;
        }
        st.push(0);
        for (int i = 1; i < nums2.size(); ++i) {
            if (nums2[i] < nums2[st.top()]) { // 情况1
                st.push(i);
            }
            else if (nums2[i] == nums2[st.top()]) { // 情况2
                st.push(i);
            } else { // 情况3
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    if (umap.count(nums2[st.top()]) > 0) { // 看map里是否存在这个元素
                        int index = umap[nums2[st.top()]]; // 根据map找到nums2[st.top()]在nums1中的下标
                        res[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

// 单调栈 精简版
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res(nums1.size(), -1);
        if (nums1.size() == 0) {
            return res;
        }

        unordered_map<int, int> umap; // key: 小标元素，value: 下标
        for (int i = 0; i < nums1.size(); ++i) {
            umap[nums1[i]] = i;
        }
        st.push(0);
        for (int i = 1; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                if (umap.count(nums2[st.top()]) > 0) { // 看map里是否存在这个元素
                    int index = umap[nums2[st.top()]]; // 根据map找到nums2[st.top()]在nums1中的下标
                    res[index] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

/**
 * @brief 
 * 思路
做本题之前，建议先做一下739. 每日温度

在739. 每日温度中是求每个元素下一个比当前元素大的元素的位置。

本题则是说nums1 是 nums2的子集，找nums1中的元素
在nums2中下一个比当前元素大的元素。

看上去和739. 每日温度 就如出一辙了。

几乎是一样的，但是这么绕了一下，其实还上升了一点难度。

需要对单调栈使用的更熟练一些，才能顺利的把本题写出来。

从题目示例中我们可以看出最后是要求nums1的每个元素
在nums2中下一个比当前元素大的元素，
那么就要定义一个和nums1一样大小的数组result来存放结果。

一些同学可能看到两个数组都已经懵了，
不知道要定一个一个多大的result数组来存放结果了。

这么定义这个result数组初始化应该为多少呢？

题目说如果不存在对应位置就输出 -1 ，所以result数组如果某位置没有被赋值，
那么就应该是是-1，所以就初始化为-1。

在遍历nums2的过程中，我们要判断nums2[i]是否在nums1中出现过，
因为最后是要根据nums1元素的下标来更新result数组。

注意题目中说是两个没有重复元素 的数组 nums1 和 nums2。

没有重复元素，我们就可以用map来做映射了。
根据数值快速找到下标，还可以判断nums2[i]是否在nums1中出现过。

C++中，当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，
因为它的查询和增删效率是最优的。我在关于哈希表，你该了解这些！中也做了详细的解释。

那么预处理代码如下:

unordered_map<int, int> umap; // key:下标元素，value：下标
for (int i = 0; i < nums1.size(); i++) {
    umap[nums1[i]] = i;
}
使用单调栈，首先要想单调栈是从大到小还是从小到大。

本题和739. 每日温度是一样的。

栈头到栈底的顺序，要从小到大，也就是保持栈里的元素为递增顺序。
只要保持递增，才能找到右边第一个比自己大的元素。

可能这里有一些同学不理解，那么可以自己尝试一下用递减栈，能不能求出来。
其实递减栈就是求右边第一个比自己小的元素了。

接下来就要分析如下三种情况，一定要分析清楚。

情况一：当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况
此时满足递增栈（栈头到栈底的顺序），所以直接入栈。

情况二：当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况
如果相等的话，依然直接入栈，因为我们要求的是右边第一个比自己大的元素，
而不是大于等于！

情况三：当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况
此时如果入栈就不满足递增栈了，这也是找到右边第一个比自己大的元素的时候。

判断栈顶元素是否在nums1里出现过，（注意栈里的元素是nums2的元素），
如果出现过，开始记录结果。

记录结果这块逻辑有一点小绕，要清楚，此时栈顶元素在nums2中右面
第一个大的元素是nums2[i]即当前遍历元素。

代码如下：
 */