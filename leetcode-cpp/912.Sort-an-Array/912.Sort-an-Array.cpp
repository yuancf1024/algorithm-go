/**
 * @file 912.Sort-an-Array.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * leetcode-912.排序数组
 * 
给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= nums.length <= 5 * 10^4
-5 * 104 <= nums[i] <= 5 * 10^4
 */

/*
复写的是双路快排，pivot选的是数组第一个元素，
当数组是升序排列时，时间复杂度退化到O(n^2).
因此，还需要对pivot进行优化，可使用随机选择来对齐优化

*/

// 快速排序复写 2022-08-10 + 引入随机化，避免向n-1集中递归的情况
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>&nums, int low, int high) {
        if (low >= high) {
            return;
        }
        // 加入面试官对于极端case的性能有要求，那么引入随机化避免向n-1集中递归的情况
        int r = rand() % (high - low + 1) + low;
        swap(nums[r], nums[low]);

        int first = low;
        int last = high;
        int key = nums[first];
        while (first < last) {
            // 从后往前，将比第一个小的移动到前面
            while (first < last && nums[last] >= key) {
                last--;
            }
            nums[first] = nums[last];
            // 从前往后，将比第一个大的移到后面
            while (first < last && nums[first] <= key) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        quickSort(nums, low, first-1);
        quickSort(nums, first+1, high);
    }
};

// 快速排序复写 2022-08-10
// 结果超时 😂
// 哪里有bug？
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>&nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int first = low;
        int last = high;
        int key = nums[first];
        while (first < last) {
            // 从后往前，将比第一个小的移动到前面
            while (first < last && nums[last] >= key) {
                last--;
            }
            nums[first] = nums[last];
            // 从前往后，将比第一个大的移到后面
            while (first < last && nums[first] <= key) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        quickSort(nums, low, first-1);
        quickSort(nums, first+1, high);
    }
};


// class Solution {
//     int partition(vector<int>& nums, int l, int r) {
//         int pivot = nums[r];
//         int i = l - 1;
//         for (int j = l; j <= r - 1; ++j) {
//             if (nums[j] <= pivot) {
//                 i = i + 1;
//                 swap(nums[i], nums[j]);
//             }
//         }
//         swap(nums[i + 1], nums[r]);
//         return i + 1;
//     }
//     int randomized_partition(vector<int>& nums, int l, int r) {
//         int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
//         swap(nums[r], nums[i]);
//         return partition(nums, l, r);
//     }
//     void randomized_quicksort(vector<int>& nums, int l, int r) {
//         if (l < r) {
//             int pos = randomized_partition(nums, l, r);
//             randomized_quicksort(nums, l, pos - 1);
//             randomized_quicksort(nums, pos + 1, r);
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         srand((unsigned)time(NULL));
//         randomized_quicksort(nums, 0, (int)nums.size() - 1);
//         return nums;
//     }
// };

// 堆排序
/*
堆排序

堆
思路和算法
堆排序的思想就是先将待排序的序列建成大根堆，
使得每个父节点的元素大于等于它的子节点。
此时整个序列最大值即为堆顶元素，我们将其与末尾元素交换，
使末尾元素为最大值，然后再调整堆顶元素使得剩下的 n−1 个元素仍为大根堆，
再重复执行以上操作我们即能得到一个有序的序列。

复杂度分析

时间复杂度：O(nlogn)。初始化建堆的时间复杂度为 O(n)，
建完堆以后需要进行n−1 次调整，一次调整（即 maxHeapify）
的时间复杂度为 O(logn)，那么 n−1 次调整即需要 O(nlogn) 的时间复杂度。
因此，总时间复杂度为 O(n+nlogn)=O(nlogn)。

空间复杂度：O(1)。只需要常数的空间存放若干变量。
*/

class Solution {
    void maxHeapify(vector<int>& nums, int i, int len) { 
        while (i*2+1 <= len) {
            int lson = (i * 2) + 1;
            int rson = (i * 2) + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            } else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            } else {
                break;
            }
        }
     }
    void buildMaxHeap(vector<int>& nums, int len) {
        for (int i = len / 2; i >= 0; --i) {
            maxHeapify(nums, i, len);
        }
    }
    void heapSort(vector<int>& nums) { 
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for (int i = len; i >= 1; --i) {
            swap(nums[i], nums[0]);
            len--;
            maxHeapify(nums, 0, len);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) { 
        heapSort(nums);
        return nums;
    }
};