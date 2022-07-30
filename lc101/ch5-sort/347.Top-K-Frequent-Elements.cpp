/* 347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，
请你返回其中出现频率前 k 高的元素。
你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]
 
提示：
1 <= nums.length <= 10^5
k 的取值范围是 [1, 数组中不相同的元素的个数]

题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
*/

// 方法1：堆排序
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>&n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
/*
思路与算法
首先遍历整个数组，并使用哈希表记录每个数字出现的次数，
并形成一个「出现次数数组」。找出原数组的前 k 个高频元素，
就相当于找出「出现次数数组」的前 k 大的值。

最简单的做法是给「出现次数数组」排序。
但由于可能有 O(N) 个不同的出现次数（其中 N 为原数组长度），
故总的算法复杂度会达到 O(NlogN)，不满足题目的要求。

在这里，我们可以利用堆的思想：建立一个小顶堆，然后遍历「出现次数数组」：
- 如果堆的元素个数小于 k，就可以直接插入堆中。
- 如果堆的元素个数等于 k，则检查堆顶与当前出现次数的大小。
    - 如果堆顶更大，说明至少有 k 个数字的出现次数比当前值大，故舍弃当前值；
    - 否则，就弹出堆顶，并将当前值插入堆中。
遍历完成后，堆中的元素就代表了「出现次数数组」中前 k 大的值。
*/

// 方法2：桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts; // first 数组值，second 频次
        int max_count = 0; // 记录最大频次
        for (const int& num : nums) { // 遍历数组，使用map记录频次
            max_count = max(max_count, ++counts[num]);
        }

        vector<vector<int>> buckets(max_count + 1);
        for (const auto & p : counts) { // 遍历map
            buckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i) {
            for (const int & num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};
/*
顾名思义，桶排序的意思是为每个值设立一个桶，桶内记录这个值出现的次数（或其它属性），
然后对桶进行排序。针对样例来说，我们先通过桶排序得到三个桶[1,2,3,4]，
它们的值分别为[4,2,1,1]，表示每个数字出现的次数。
紧接着，我们对桶的频次进行排序，前k 大个桶即是前k 个频繁的数。
这里我们可以使用各种排序算法，甚至可以再进行一次桶排序，
把每个旧桶根据频次放在不同的新桶内。针对样例来说，
因为目前最大的频次是4，我们建立[1,2,3,4] 四个新桶，
它们分别放入的旧桶为[[3,4],[2],[],[1]]，
表示不同数字出现的频率。最后，我们从后往前遍历，直到找到k 个旧桶。
*/

