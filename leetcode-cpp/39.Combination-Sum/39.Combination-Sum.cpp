/* 39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。
如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]

解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。

示例 2：
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]

示例 3：
输入: candidates = [2], target = 1
输出: []

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都 互不相同
1 <= target <= 500

*/

// 原始版本
class Solution {
private
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) { // sum等于target的时候，需要收集结果
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 关键点: 不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i]; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

// 剪枝优化版本
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        // if (sum > target) {
        //     return;
        // }
        if (sum == target) { // sum等于target的时候，需要收集结果
            result.push_back(path);
            return;
        }

        // 如果sum+candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum+candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 关键点: 不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i]; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        // 剪枝优化版本需要对candidates排序
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

/*
思路

题目中的无限制重复被选取，吓得我赶紧想想 出现0 可咋办，
然后看到下面提示：1 <= candidates[i] <= 200，我就放心了。

本题和77.组合，216.组合总和III
的区别是：本题没有数量要求，可以无限重复，但是有总和的限制，
所以间接的也是有个数的限制。

注意图中叶子节点的返回条件，因为本题没有组合数量要求，仅仅是总和的限制，
所以递归没有层数的限制，只要选取的元素总和超过target，就返回！

而在77.组合 和216.组合总和III 中都可以知道要递归K层，
因为要取k个元素的组合

回溯三部曲

1. 递归函数参数

这里依然是定义两个全局变量，二维数组result存放结果集，
数组path存放符合条件的结果。（这两个变量可以作为函数参数传入）

首先是题目中给出的参数，集合candidates, 和目标值target。
此外我还定义了int型的sum变量来统计单一结果path里的总和，
其实这个sum也可以不用，用target做相应的减法就可以了，
最后如何target==0就说明找到符合的结果了，
但为了代码逻辑清晰，我依然用了sum。

本题还需要startIndex来控制for循环的起始位置，对于组合问题，
什么时候需要startIndex呢？

我举过例子，如果是一个集合来求组合的话，就需要startIndex，
例如：77.组合 ，216.组合总和III 。

如果是多个集合取组合，各个集合之间相互不影响，那么就不用startIndex，
例如：17.电话号码的字母组合

注意以上我只是说求组合的情况，如果是排列问题，又是另一套分析的套路，
后面我再讲解排列的时候就重点介绍。

代码如下：
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& candidates, int target, int sum, int startIndex)

2. 递归终止条件

在如下树形结构中：
从叶子节点可以清晰看到，终止只有两种情况，sum大于target和sum等于target。

sum等于target的时候，需要收集结果，代码如下：

if (sum > target) {
    return;
}
if (sum == target) {
    result.push_back(path);
    return;
}

3. 单层搜索的逻辑

单层for循环依然是从startIndex开始，搜索candidates集合。

注意本题和77.组合 、216.组合总和III 的一个区别是：
本题元素为可重复选取的。

如何重复选取呢，看代码，注释部分：

for (int i = startIndex; i < candidates.size(); i++) {
    sum += candidates[i];
    path.push_back(candidates[i]);
    backtracking(candidates, target, sum, i); // 关键点:不用i+1了，表示可以重复读取当前的数
    sum -= candidates[i];   // 回溯
    path.pop_back();        // 回溯
}

*/

// 2022-07-31复写 
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

// 剪枝优化版
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 如果 sum+candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

/*
以及上面的版本一的代码大家可以看到，对于sum已经大于target的情况，
其实是依然进入了下一层递归，只是下一层递归结束判断的时候，
会判断sum > target的话就返回。

其实如果已经知道下一层的sum会大于target，就没有必要进入下一层递归了。

那么可以在for循环的搜索范围上做做文章了。

对总集合排序之后，如果下一层的sum（就是本层的 sum + candidates[i]）
已经大于target，就可以结束本轮for循环的遍历。

for循环剪枝代码如下：

for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)

如图：
*/