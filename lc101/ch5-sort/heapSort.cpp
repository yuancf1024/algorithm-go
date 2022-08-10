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