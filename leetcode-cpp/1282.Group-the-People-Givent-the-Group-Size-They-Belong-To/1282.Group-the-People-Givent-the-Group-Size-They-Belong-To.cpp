/**
 * @file 1282.Group-the-People-Givent-the-Group-Size-They-Belong-To.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1282.用户分组

有 n 个人被分成数量未知的组。
每个人都被标记为一个从 0 到 n - 1 的唯一ID 。

给定一个整数数组 groupSizes ，
其中 groupSizes[i] 是第 i 个人所在的组的大小。
例如，如果 groupSizes[1] = 3 ，则第 1 个人必须位于大小为 3 的组中。

返回一个组列表，使每个人 i 都在一个大小为 groupSizes[i] 的组中。

每个人应该 恰好只 出现在 一个组 中，并且每个人必须在一个组中。
如果有多个答案，返回其中 任何 一个。
可以 保证 给定输入 至少有一个 有效的解。

示例 1：
输入：groupSizes = [3,3,3,3,3,1,3]
输出：[[5],[0,1,2],[3,4,6]]

解释：
第一组是 [5]，大小为 1，groupSizes[5] = 1。
第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。 
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。

示例 2：
输入：groupSizes = [2,1,3,3,3,2]

输出：[[1],[0,5],[2,3,4]]
 
提示：

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n

 */

// 参考leetcode官方题解
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        int n = groupSizes.size();
        for (int i = 0; i < n; ++i) {
            int size = groupSizes[i];
            groups[size].emplace_back(i); // 使用哈希表记录每个组的大小对应的所有人的编号
        }
        vector<vector<int>> groupList;
        for (auto &[size, people] : groups) {
            int groupCount = people.size() / size;
            for (int i = 0; i < groupCount; ++i) {
                vector<int> group;
                int start = i * size;
                for (int j = 0; j < size; ++j) {
                    group.emplace_back(people[start + j]);
                }
                groupList.emplace_back(group);
            }
        }
        return groupList;
    }
};

// 大佬的精简解法
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> dict;
        for (int i{}; auto& v : groupSizes) {
            dict[v].push_back(i++);
            if (dict[v].size() == v) {
                ans.push_back(exchange(dict[v], {}));
                // exchange( T& obj, U&& new_value)
                // 使用new_value替换obj的值，并返回obj的旧值
            }
        }
        return ans;
    }
};

/**
 * @brief 
 * 方法一：哈希表
由于给定的输入一定存在有效的解，因此对于数组groupSizes 中的每个元素 x，
当 x 在数组中出现 y 次时，y 一定能被 x 整除，且大小为 x 的组有y/x个。

首先将每个人的编号按照组的大小划分，
使用哈希表记录每个组的大小对应的所有人的编号。
然后遍历哈希表，对于大小为 x 的组，
得到对应的所有人编号列表，将列表的大小记为 y，
则 y 一定能被 x 整除，将列表分成y/x个大小为 x 的组，
并将每个组添加到答案中。遍历结束之后，即完成分组。

考虑示例 1 的分组。

1. 根据数组groupSizes 得到每个组的大小对应的所有人的编号：
大小为 1 的组对应的编号列表是[5]，大小为 3 的组对应的编号列表是
[0,1,2,3,4,6]。

2. 将每个组的大小对应的编号列表分成特定大小的列表。
- 大小为 1 的组对应的编号列表的长度是 1，因此有 1 个大小为 1 的组：[5]。
- 大小为 3 的组对应的编号列表的长度是 6，因此有 2 个大小为 3 的组：[0,1,2],[3,4,6]。
最终分组情况是[[5],[0,1,2],[3,4,6]。

复杂度分析
时间复杂度：O(n)，其中 n 是数组 groupSize 的长度。
需要遍历数组一次得到每个组的大小对应的所有人的编号，
然后需要遍历所有元素完成分组。

空间复杂度：O(n)，其中 n 是数组 groupSize 的长度。
空间复杂度主要取决于哈希表，哈希表需要 O(n) 的空间
记录每个组的大小对应的所有人的编号。

 */