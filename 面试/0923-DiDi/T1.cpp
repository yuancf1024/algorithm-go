/*

题目1自然数n,请求出分解自然数之和最小的一个

题目：一个自然数可以分解为若干个自然数相乘，对于指定自然数n,
请求出每种分解自然数之和最小的一个（不考虑1，若是素数，则是它本身）


示例1:
12
2*6 2+6=8
2*2*3 2+2+3=7

7

18
3*6 9
2*9 11
3*2*3 8

8
*/

/*
2022-09-23滴滴一面的题
就是简单的模拟，真的哭死
面试时写了一个bug，这里不用去将所有分解的自然数相乘
求和存起来，直接从小到大去遍历，判断是否被整除即可，
所得结果就满足分解自然数之和最小。
*/

#include <bits/stdc++.h>

using namespace std;

int getMinSum(int n) { 
    int i = 2;
    int sum = 0;
    int t = n;
    while (t != 1) {
        if (t % i == 0) {
            sum += i;
            t /= i;
            i = 2;
        }
        else {
            ++i;
        }
    }
    return sum;
}

int main() { 
    int n;
    cin >> n;

    int res = getMinSum(n);
    cout << res << endl;
}