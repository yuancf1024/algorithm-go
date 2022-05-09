/* 216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，
组合可以以任何顺序返回。

示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
示例 3:

输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，
因为10 > 1，没有有效的组合。
*/

// 回溯
class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    // targetSum：目标和，也就是条件的结果
    // k：题目中要求k个数的集合
    // sum：已经收集的元素的总和，也就是path里元素的总和
    // startIndex：下一层for循环搜索的起始位置
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1); // 注意i+1调整startIndex
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear(); // 可以不加
        backtracking(n, k, 0, 1);
        return result;
    }
};

// 回溯 + 剪枝
class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    // targetSum：目标和，也就是条件的结果
    // k：题目中要求k个数的集合
    // sum：已经收集的元素的总和，也就是path里元素的总和
    // startIndex：下一层for循环搜索的起始位置
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        // 剪枝操作
        if (sum > targetSum) {
            return;
        }
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }

        for (int i = startIndex; i <= 9-(k-path.size())+1; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1); // 注意i+1调整startIndex
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear(); // 可以不加
        backtracking(n, k, 0, 1);
        return result;
    }
};