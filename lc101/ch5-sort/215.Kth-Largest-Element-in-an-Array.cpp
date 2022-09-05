/* 215.Kth-Largest-Element-in-an-Array
题目描述
在一个未排序的数组中，找到第k 大的数字。

输入输出样例
输入一个数组和一个目标值k，输出第k 大的数字。
题目默认一定有解。

Input: [3,2,1,5,6,4] and k = 2
Output: 5

*/

// 快速选择 参考leetcode101
class Solution {
public:
    // 主函数
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, target = nums.size() - k; // 找数组中第k大
        while (l < r) {
            int mid = quickSelection(nums, l, r);
            if (mid == target) {
                return nums[mid];
            }
            if (mid < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }

    // 辅函数 - 快速选择
    int quickSelection(vector<int>& nums, int l, int r) {
        int i = l + 1, j = r;
        while (true) {
            // 从前往后遍历，将比第一个大的移动到后面
            while (i < r && nums[i] <= nums[l]) {
                ++i;
            }
            // 从后往前遍历，将比第一个小的移动到前面
            while (l < j && nums[j] >= nums[l]) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]); // 对first>=last的补充
        return j;
    }
};

/*
快速选择一般用于求解k-th Element 问题，可以在O(n) 时间复杂度，O(1) 空间复杂度完成求
解工作。快速选择的实现和快速排序相似，不过只需要找到第k 大的枢（pivot）即可，不需要对
其左右再进行排序。与快速排序一样，快速选择一般需要先打乱数组，否则最坏情况下时间复杂
度为O(n^2)，我们这里为了方便省略掉了打乱的步骤。
*/

// 快速选择 参考leetcode官方题解
class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index)
                             : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l; // // 引入随机化，避免向n-1集中递归的情况
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) { 
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

/*
复杂度分析
- 时间复杂度：O(n)，如上文所述，证明过程可以参考
「《算法导论》9.2：期望为线性的选择算法」。
- 空间复杂度：O(logn)，递归使用栈空间的空间代价的期望为 O(logn)。
*/

// 堆排序+选择 参考leetcode官方题解
class Solution {
public:
    // 大顶堆堆化，以i当作根节点，调整其和其子树为最大堆 && 节点从0开始
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize); // 递归
        }
    }

    // 建堆，本质：从下往上，从右往左，将每个非叶子结点当作根节点，将其和子树调整成最大堆
    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) { 
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        // 将堆中前k-1个元素移到末尾，那么最后的堆顶即为所求topK元素
        for (int i = nums.size() - 1; i >= nums.size() - k + 1;--i) {
            swap(nums[0], nums[i]); // 将堆顶的元素和最后一个元素交换位置
            --heapSize; 
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

/*
思路和算法

我们也可以使用堆排序来解决这个问题——建立一个大根堆，
做 k−1 次删除操作后堆顶元素就是我们要找的答案。
在很多语言中，都有优先队列或者堆的的容器可以直接使用，但是在面试中，
面试官更倾向于让更面试者自己实现一个堆。所以建议读者掌握这里大根堆的实现方法，
在这道题中尤其要搞懂「建堆」、「调整」和「删除」的过程。

友情提醒：「堆排」在很多大公司的面试中都很常见，
不了解的同学建议参考《算法导论》或者大家的数据结构教材，
一定要学会这个知识点哦！^_^

复杂度分析
时间复杂度：O(nlogn)，建堆的时间代价是 O(n)，删除的总代价是 O(klogn)，
因为 k<n，故渐进时间复杂为 O(n+klogn)=O(nlogn)。
空间复杂度：O(logn)，即递归使用栈空间的空间代价。
*/

// 2022-08-03 复写 快速选择
// 奇怪：我和上面那位牛客大佬的写法思路一样，但是会有测试case过不了
// 所以应该是哪里的边界条件没有考虑到位
// 通过测试用例：13 / 39
// 哭死 int low, high = nums.size()-1, target = nums.size()-k; // 忘了初始化low 😂
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {          
        int low, high = nums.size()-1, target = nums.size()-k;
        while (low < high) {
            int mid = quickSelection(nums, low, high);
            if (mid == target) {
                return nums[mid];
            }
            if (mid < target) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return nums[low];
    }

    // 快排划分，左小右大，[low, high] 左闭右闭
    int quickSelection(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return -1;
        }
        int first = low;
        int last = high;
        int key = nums[first]; // 以第一个数作为标兵
        while (first < last) {
            // 从后往前遍历，将比第一个小的移动到前面
            while (first < last && nums[last] >= key) {
                last--;
            }
            nums[first] = nums[last];
            // 从前往后遍历，将比第一个大的移动到后面
            while (first < last && nums[first] <= key) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        return first;
    }
};

// 2022-08-03 Debug后 Pass 的实现
class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {          
        int low = 0, high = nums.size()-1, target = nums.size()-k;
        while (low < high) {
            int mid = quickSelection(nums, low, high);
            if (mid == target) {
                return nums[mid];
            }
            if (mid < target) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return nums[low];
    }

    int quickSelection(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return -1;
        }
        // int first = low;
        // int last = high;
        int key = nums[low]; // 以第一个数作为标兵
        while (low < high) {
            // 从后往前遍历，将比第一个小的移动到前面
            while (low < high && nums[high] >= key) {
                high--;
            }
            nums[low] = nums[high];
            // 从前往后遍历，将比第一个大的移动到后面
            while (low < high && nums[low] <= key) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = key;
        return low;
    }
};


// 复写，和快速排序保持一致的实现
class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {          
        int low = 0, high = nums.size()-1, target = nums.size()-k;
        while (low < high) {
            int mid = quickSelection(nums, low, high);
            if (mid == target) {
                return nums[mid];
            }
            if (mid < target) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return nums[low];
    }

    int quickSelection(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return -1;
        }
        int first = low;
        int last = high;
        int key = nums[first]; // 以第一个数作为标兵
        while (first < last) {
            // 从后往前遍历，将比第一个小的移动到前面
            while (first < last && nums[last] >= key) {
                last--;
            }
            nums[first] = nums[last];
            // 从前往后遍历，将比第一个大的移动到后面
            while (first < last && nums[first] <= key) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        return first;
    }
};

// 堆排序+借助优先队列的解法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> q;
        for (auto& num : nums) {
            if (q.size() < k) {
                q.push(num);
            } else if (q.top() < num) {
                q.pop();
                q.push(num);
            }
        }
        return q.top();
    }
};
/*
解题思路：维护一个长度为k的优先队列(小根堆)，使之前遍历过的最大的k个元素按照从小到大排列，
不断地更新，最后头元素即是第k大
*/