#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 题目大意：太复杂了😂
 * 一条直线上N个点，数组索引代表点号，元素值为坐标；
 * 对于给定的整数M，如果子集中任意两个点之间的距离可被
 * M整除，则称这些点的子集是M对齐的。
 * 找到给定N个点集合中对齐M的最大子集数目
 * 直接上TestCase
 */

/*
TestCase1:
[-3,-2,1,0,8,7,1]
3

4

TestCase2:
[7,1,11,8,4,10]
8

1

*/


// 微软题目也提示比起性能会更加关注正确性
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int M) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int res = 0;
    int n = A.size();
    map<int,int> map; // 针对Case1
    unordered_set<int> set; // 针对Case2
    // 针对Case1：只要两点之间的距离能整除M，加入集合
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(A[i]-A[j]) % M == 0) { // 无法保证set所有点互相距离都能整除M // 用map就可
                map[i]++;
                map[j]++;
            }
        }
    }
    // 遍历map
    unordered_set<int> setF;
    for (auto it = map.begin(); it != map.end(); it++) {
        setF.insert(it->second);
        // if (it->second % 2 == 0) {
        //     set.insert(it->first);
        // }
    }
    int idx = *max_element(setF.begin(), setF.end());
    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->second == idx) {
            set.insert(it->first);
        }
    }
    res = set.size();

    // 针对case2 考虑单个元素是否能整除M
    if (res != 0) {
        return res;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (A[i] % M == 0) {
                set.insert(i);
            }
        }
        return set.size();
    }
}

int main() {
    vector<int> A = {-3,-2,1,0,8,7,1};
    int M = 3;

    // vector<int> A = {7,1,11,8,4,10};
    // int M = 8;

    int res = solution(A, M);
    cout << res << endl;
    return 0;
}

/*
Test output

Run tests
Example test: example

Test result: OK

Example test: example2

Test result: OK
*/