#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 大意：给定两个数组vector<int> A = {3,2,1,6,5};
    vector<int> B = {4,2,1,3,3};
    构建一个新数组，新数组nums[i]取max(A[i],B[i])
    返回不在nums出现的最小值

Case1：
[1,2,4,3]
[1,3,2,3]

2

Case2：
[3,2,1,6,5]
[4,2,1,3,3]

3

Case3：注意这个特殊Case
[1,2]
[1,2]

3
 */


// 微软题目也提示比起性能会更加关注正确性
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++ (C++14 (g++ 6.2.0))

    // 新建一个哈希表
    unordered_set<int> set;
    int n = A.size();
    vector<int> nums;
    // for (int i = 0; i < n; ++i) {
    //     if (!set.count(A[i])) {
    //         set.insert(A[i]);
    //     }
    //     if (!set.count(B[i])) {
    //         set.insert(B[i]);
    //     }
    // }
    for (int i = 0; i < n; ++i) {
        if (A[i] == B[i]) {
            nums.push_back(A[i]);
        } else if (A[i] > B[i]) {
            nums.push_back(A[i]);
            set.insert(B[i]);
        } else {
            nums.push_back(B[i]);
            set.insert(A[i]);
        }
    }

    if (set.empty()) {
        return *max_element(A.begin(), A.end()) + 1;
    }
    int res = *min_element(set.begin(), set.end());
    return res;
}

int main() {
    vector<int> A = {3,2,1,6,5};
    vector<int> B = {4,2,1,3,3};

    int res = solution(A, B);
    cout << res << endl;
    return 0;
}

/*
Example test: example1

Test result: OK

Example test: example2

Test result: OK

Example test: example3

Test result: OK
*/