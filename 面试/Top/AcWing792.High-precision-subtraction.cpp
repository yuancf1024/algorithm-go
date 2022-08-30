/**
 * @file AcWing792.High-precision-subtraction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * AcWing792792.高精度减法
 * 
 * 给定两个正整数(不含前导0)，计算它们的差，计算结果可能为负数。
 * 
 * 输入格式
 * 共两行，每行包含一个整数。
 * 
 * 输出格式
 * 共一行，包含所求的差。
 * 
 * 数据范围
 * 1 <= 整数长度 <= 10^5
 * 
 * 输入样例
 * 32
 * 11
 * 
 * 输出样例
 * 21
 */

// yxc高精度减法模板
// C = A - B, 满足 A >= B, A>=0, B>=0

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 实现高精度的减法 单纯的处理正整数 而且结果只能为正
    // C = A - B, 满足A >= B, A >= 0, B >= 0
    vector<int> sub(vector<int>& A, vector<int>& B) { 
        vector<int> C;
        for (int i = 0, t = 0; i < A.size(); ++i) {
            t = A[i] - t;
            if (i < B.size()) {
                t -= B[i];
            }
            C.push_back((t + 10) % 10); // 防止求余取到负数
            if (t < 0) {
                t = 1;
            } else {
                t = 0;
            }
        }

        while (C.size() > 1 && C.back() == 0) {
            C.pop_back();
        }
        return C;
    }

    // 高精度加法
    // C = A + B, A >= 0, B >= 0
    vector<int> add(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) {
            return add(B, A); // 确保A的数位数高于B
        }
        vector<int> C;
        int t = 0;
        for (int i = 0; i < A.size(); ++i) {
            t += A[i];
            if (i < B.size()) {
                t += B[i];
            }
            C.push_back(t % 10);
            t /= 10; // 保留进位结果
        }

        if (t) { // 保证最后一个进位
            C.push_back(t);
        }
        return C;
    }

    // 高精度乘低精度
    // C = A*b, A >= 0, b >= 0
    vector<int> mul(vector<int>& A, int b) { 
        vector<int> C;

        int t = 0;
        for (int i = 0; i < A.size() || t; ++i) {
            if (i < A.size()) {
                t += A[i] * b;
                C.push_back(t % 10);
                t /= 10;
            }
            while (C.size() > 1 && C.back() == 0) {
                C.pop_back();
            }
            return C;
        }
    }

    // 高精度除以低精度
    // A / b = C ... r, A>= 0, b > 0
    vector<int> div(vector<int>& A, int b, int& r) { 
        vector<int> C;
        r = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            r = r * 10 + A[i];
            C.push_back(r / b);
            r %= b;
        }
        reverse(C.begin(), C.end());
        while (C.size() > 1 && C.back() == 0) {
            C.pop_back();
        }
        return C;
    }
};

class Solution1 {
public:
    // 实现高精度的减法 可正可负

    // 高精度加法
    vector<int> add(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) {
            return add(B, A); // 确保A的数位数高于B
        }
        vector<int> C;
        int t = 0;
        for (int i = 0; i < A.size(); ++i) {
            t += A[i];
            if (i < B.size()) {
                t += B[i];
            }
            C.push_back(t % 10);
            t /= 10; // 保留进位结果
        }

        if (t) { // 保证最后一个进位
            C.push_back(t);
        }
        return C;
    }

    // 高精度减法
    vector<int> sub(vector<int>& A, vector<int>& B) { 
        vector<int> C;
        for (int i = 0, t = 0; i < A.size(); ++i) {
            t = A[i] - t;
            if (i < B.size()) {
                t -= B[i];
            }
            C.push_back((t + 10) % 10); // 防止求余取到负数
            if (t < 0) {
                t = 1; // 用于借位
            } else {
                t = 0;
            }
        }

        while (C.size() > 1 && C.back() == 0) { // 清除高位的0
            C.pop_back();
        }
        return C;
    }

    /*
    * 拓展：加入输入的数有正有负
    * 
    * 转化：
    * 1. ++ 直接算 A-B
    * 2. +- 等价于 A+abs(B) (说明此处需要实现高精度加法)😂
    * 3. -+ 等价于 abs(A+B)
    * 4. -- 等价于 取(A-B)的相反数
    */
    // 可处理正负的减法
    pair<vector<int>, bool> subAll(vector<int>& A, vector<int>& B, bool stateA, bool stateB) {
        // state 记录结果的正负
        bool state = true;
        if (stateA && stateB) {  // + +
            return make_pair(sub(A, B), state);
        }

        if (!stateA && !stateB) { // - -
            return make_pair(sub(A, B), !state);
        }

        if (stateA && !stateB) {  // + -
            return make_pair(add(A, B), state);
        }

        if (!stateA && stateB) {  // - +
            return make_pair(add(A, B), !state);
        }
    }
};

/**
 * @brief 
 * 高精度减法的核心思路：(两个都是正数的情况)
 * 将两个大整数的各个数位，按照从低位到高位的顺序依次保存到数组A、B；
 * **遍历数组A**，借助临时变量t处理借位，t = A[i]-t
 * 如果当前遍历的数位没有超过B的范围，直接相减t -= B[i]；
 * 将t除10的正余数添加进结果数组
 * - 相同数位相减结果小于0，那么需要在A的高位借1，t=1
 * - 否则t=0
 * 
 * 结果数组的末尾代表结果的高位，当结果数组位数超过2且高位含0时，需要去掉0
 * 
 * 
 * 拓展：加入输入的数有正有负
 * 
 * 转化：
 * 1. ++ 直接算 A-B
 * 2. +- 等价于 A+abs(B) (说明此处需要实现高精度加法)😂
 * 3. -+ 等价于 abs(A+B)
 * 4. -- 等价于 取(A-B)的相反数
 * 
 * 取相反数的快速运算 num -> ~num+1
 */

int main() { 
    Solution1 s;
    
    // vector<int> A = {3, 2, 5, 6};
    // vector<int> B = {1, 1, 7, 4};

    // 假设从终端读入2个大整数(字符串形式) 6523 4711
    string A, B;
    cin >> A >> B;

    // 记录A B的正负
    bool stateA = true, stateB = true;
    if (A[0] == '-') {
        stateA = false;
        A.erase(0, A.find_first_not_of("-")); // 去掉头部负号
    }
    if (B[0] == '-') {
        stateB = false;
        B.erase(0, B.find_first_not_of("-")); // 去掉头部负号
    }
    vector<int> numsA;
    vector<int> numsB;
    for (int i = A.size()-1; i >= 0; --i) {
        numsA.push_back(A[i]-'0'); // 保存为 3 2 5 6
    }
    for (int i = B.size()-1; i >= 0; --i) {
        numsB.push_back(B[i]- '0'); // 保存为 1 1 7 4
    }
    // 调试
    // for (auto& i : numsA) {
    //     cout << i << " ";
    // }
    
    pair<vector<int>, bool> ans = s.subAll(numsA, numsB, stateA, stateB);
    // vector<int> res = s.sub(numsA, numsB);
    // cout << res << endl;
    // 倒序输出

    // 先输出符号
    if (!ans.second) {
        cout << '-';
    }
    for (int i = ans.first.size() - 1; i >= 0; --i) {
        cout << ans.first[i] << " ";
    } 
    return 0;
}

/*
// 单纯减法
TestCase1:
6523
4711

1812

// 可正可负
1111111111 11
1111111100

1111111111 -11
1111111122

-1111111111 -11
-1111111100

-1111111111 11
-1111111122
*/