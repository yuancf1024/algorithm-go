/**
 * @file 4.Median-of-Two-Sorted-Arrays.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * leetcode-4.寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000

解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000

解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 
提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
 */

// 参考acwing 小呆呆
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0) { // 两个数组为偶数个数
            int left = find(nums1, 0, nums2, 0, total / 2);
            int right = find(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        } else { // 两个数组为奇数个数
            return find(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    // 辅函数 寻找第k小
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // 保证前一个数组大小比第二个数组小，[i, nums1.size()-1]表示数组1的长度
        // [j,nums2.size()-1]表示数组2的长度
        if (nums1.size() - i > nums2.size() - j) {
            return find(nums2, j, nums1, i, k);
        }
        // 如果第一个数组遍历结束，则返回第二个数组
        if (nums1.size() == i) {
            return nums2[j + k - 1];
        }
        // 当取出第1个元素
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int si = min((int)nums1.size(), i + k / 2), sj = j + k - k / 2;
        if (nums1[si-1] > nums2[sj-1]) {
            return find(nums1, i, nums2, sj, k - (sj - j));
        } else {
            return find(nums1, si, nums2, j, k - (si - i));
        }
    }
};
/**
 * @brief 
 * 算法分析
给定两个有序的数组，找中位数(n + m) / 2，
等价于找第k小的元素，k = (n + m) / 2

1、当一共有偶数个数时，找到第total / 2小left和
第total / 2 + 1小right，结果是(left + right / 2.0)
2、当一共有奇数个数时，找到第total / 2 + 1小，即为结果

如何找第k小？

si = i + k / 2

sj = j + k - k / 2

1、默认第一个数组比第二个数组的有效长度小
2、第一个数组的有效长度从i开始，
第二个数组的有效长度从j开始，
其中[i,si - 1]是第一个数组的前k / 2个元素，
[j, sj - 1]是第二个数组的前k - k / 2个元素

3、当nums1[si - 1] > nums2[sj - 1]时，
则表示第k小一定在[i,n]与[sj,m]中
4、当nums1[si - 1] <= nums2[sj - 1]时，
则表示第k小一定在[si,n]与[j,m]中

时间复杂度 Olog(n+m)

 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};

/**
 * @brief 
方法一：二分查找
给定两个有序数组，要求找到两个有序数组的中位数，最直观的思路有以下两种：

- 使用归并的方式，合并两个有序数组，得到一个大的有序数组。
大的有序数组的中间位置的元素，即为中位数。

- 不需要合并两个有序数组，只要找到中位数的位置即可。
由于两个数组的长度已知，因此中位数对应的两个数组的下标之和也是已知的。
维护两个指针，初始时分别指向两个数组的下标0 的位置，
每次将指向较小值的指针后移一位
（如果一个指针已经到达数组末尾，则只需要移动另一个数组的指针），
直到到达中位数的位置。

假设两个有序数组的长度分别为m 和n，上述两种思路的复杂度如何？

第一种思路的时间复杂度是O(m+n)，空间复杂度是O(m+n)。
第二种思路虽然可以将空间复杂度降到O(1)，
但是时间复杂度仍是O(m+n)。

如何把时间复杂度降低到O(log(m+n)) 呢？
如果对时间复杂度的要求有log，通常都需要用到二分查找，
这道题也可以通过二分查找实现。

根据中位数的定义，当 m+n 是奇数时，中位数是两个有序数组中的
第 (m+n)/2 个元素，当m+n 是偶数时，中位数是两个有序数组中的
第 (m+n)/2 个元素和第 (m+n)/2+1 个元素的平均值。
因此，这道题可以转化成寻找两个有序数组中的第k 小的数，
其中 k 为 (m+n)/2 或 (m+n)/2+1。

假设两个有序数组分别是A 和B。要找到第k 个元素，
我们可以比较 A[k/2−1] 和 B[k/2−1]，其中 / 表示整数除法。
由于A[k/2−1] 和B[k/2−1] 的前面分别有A[0..k/2−2] 和 B[0..k/2−2]，
即 k/2−1 个元素，对于A[k/2−1] 和 B[k/2−1] 中的较小值，
最多只会有(k/2−1)+(k/2−1)≤k−2 个元素比它小，
那么它就不能是第k 小的数了。

因此我们可以归纳出三种情况：

- 如果A[k/2−1]<B[k/2−1]，则比A[k/2−1] 小的数最多只有A的前k/2−1个数
和B 的前k/2−1 个数，即比A[k/2−1] 小的数最多只有k−2 个，
因此A[k/2−1] 不可能是第k 个数，A[0] 到A[k/2−1] 也都不可能是第 k 个数，
可以全部排除。

- 如果A[k/2−1]>B[k/2−1]，则可以排除B[0] 到 B[k/2−1]。

- 如果A[k/2−1]=B[k/2−1]，则可以归入第一种情况处理。

可以看到，比较A[k/2−1]和B[k/2−1] 之后，
可以排除k/2 个不可能是第k 小的数，查找范围缩小了一半。
同时，我们将在排除后的新数组上继续进行二分查找，
并且根据我们排除数的个数，减少k 的值，
这是因为我们排除的数都不大于第k 小的数。

有以下三种情况需要特殊处理：

- 如果A[k/2−1] 或者B[k/2−1] 越界，
那么我们可以选取对应数组中的最后一个元素。
在这种情况下，我们必须根据排除数的个数减少k 的值，
而不能直接将k减去k/2。

- 如果一个数组为空，说明该数组中的所有元素都被排除，
我们可以直接返回另一个数组中第kk小的元素。

如果k=1，我们只要返回两个数组首元素的最小值即可。

用一个例子说明上述算法。假设两个有序数组如下：

A: 1 3 4 9
B: 1 2 3 4 5 6 7 8 9
两个有序数组的长度分别是4 和9，长度之和是13，
中位数是两个有序数组中的第 7 个元素，因此需要找到第k=7 个元素。

比较两个有序数组中下标为 k/2−1=2 的数，即A[2] 和B[2]，如下面所示：

A: 1 3 4 9
       ↑
B: 1 2 3 4 5 6 7 8 9
       ↑
由于A[2]>B[2]，因此排除B[0] 到 B[2]，
即数组B 的下标偏移（offset）变为3，
同时更新 k 的值：k=k−k/2=4。

下一步寻找，比较两个有序数组中下标为k/2−1=1 的数，
即A[1] 和 B[4]，如下面所示，其中方括号部分表示已经被排除的数。

A: 1 3 4 9
     ↑
B: [1 2 3] 4 5 6 7 8 9
             ↑
由于A[1]<B[4]，因此排除 A[0] 到 A[1]，
即数组A 的下标偏移变为2，同时更新k 的值：k=k−k/2=2。

下一步寻找，比较两个有序数组中下标为k/2−1=0 的数，
即比较A[2] 和B[3]，如下面所示，其中方括号部分表示已经被排除的数。
A: [1 3] 4 9
         ↑
B: [1 2 3] 4 5 6 7 8 9
           ↑
由于A[2]=B[3]，根据之前的规则，排除A 中的元素，因此排除 A[2]，
即数组A 的下标偏移变为 3，同时更新 k 的值： k=k−k/2=1。

由于k 的值变成1，因此比较两个有序数组中的未排除下标范围内的第一个数，
其中较小的数即为第k个数，由于A[3]>B[3]，因此第k 个数是B[3]=4。


A: [1 3 4] 9
           ↑
B: [1 2 3] 4 5 6 7 8 9
           ↑
 */