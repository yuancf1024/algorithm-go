#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 大意：给定一个由N个小写英文字母组成的字符串S，
 * 返回其中每个字母出现偶数次的最长子串的长度。
 * 子字符串被定义为字符串的连续段。
 * 如果不存在这样的子字符串，则返回0
 */

/*
TestCase1:
bdaaadadb

> "aa" "adad" "daaada" "aaadad"

6

TestCase2:
abacb

0

TestCase3:
zthtzh

> "zthtzh"


6

*/

// 微软题目也提示比起性能会更加关注正确性
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isAllEven(string S) {
    
    // int n = S.size();
    // 先考虑特殊case 整个字符串每个字符出现偶数次
    unordered_map<char, int> map;
    for (auto& s : S) {
        map[s]++;
    }
    // 核心逻辑代码段
    // 整个字符串都满足题目要求的Case
    bool allEven = true;
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it->second % 2 == 0) { // 偶数
            continue;
        } else {
            allEven = false;
        }
    }
    return allEven;
}

int solution(string &S) {
    // write your code in C++ (C++14 (g++ 6.2.0))

    // bool flag;
    int n = S.size();
    int res = 0;
    for (int l = 0, r = n; l <= r; l++, r--) {
        string temp = S.substr(l, r);
        if (isAllEven(temp)) {
            res = temp.size();
            break;
        }

        string temp2 = S.substr(l+1, r);
        if (isAllEven(temp2)) {
            res = temp2.size();
            break;
        }

        string temp3 = S.substr(l, r-1);
        if (isAllEven(temp3)) {
            res = temp3.size();
            break;
        }
    } 
    return res;
}



int main() {
    // vector<vector<int>> A = {{2, 7, 5}, {3,1,1},{2,1,-7},{0,2,1},{1,6,8}};
    string S = "bdaaadadb";
    // string S = "zthtzh";
    // string S = "abacb"; 

    int res = solution(S);
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