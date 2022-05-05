/* T4 The most of zero multiplication

The most of zero multiplication

Description

"ZERO" means the number of 0 at the end of a number. 
For example, the "ZERO" value of 200 is 2 and the "ZERO" value of 3000 is 3.

Give you a sequence of lengthnand ask you to choose the number of k 
from it , so that the product of these selected numbers has the 
maximum "ZERO" value.

Input

The first line includes two positive integers n and k, 
1 <= n <= 200, 1 <= k <= n.

The second line includes n blank separated numbers,
a1,a2,...,an (1 <= ai <= 10^18).

Output

Output an integer, which is the maximum "ZERO" value of the number 
ofkselected and the product.

Sample Input 1 

3 2
50 4 20

Sample Output 1

3

Sample Input 2 

3 3
9 77 13

Sample Output 2

0

Hint

In the first example, there are three selection methods. 
The product of [50,4] is 200 and the "ZERO" value is 2. 
The product of [4,20] is 80 and the "ZERO" value is 1. 
The product of [50,20] is 1000 and the "ZERO" value is 3.


题解: 给定一组数据,长度为n,从里面任意找出k个数,相乘得到res,
判断res的 "ZERO" value.

比赛Golang实现思路: 回溯+多个条件判断
从一个数组中找出k个数,需要组合得到,里面涉及到很多情况,需要回溯或者枚举.
核心思想是要减少for循环的遍历次数.
边界条件, n等于k时,直接对数组求和,然后判断"ZERO" value.

如果k < n, 先从数组中找到所有k个数的乘积,并存入数组res;
遍历res,判断"ZERO" value;
判断方式: 将num转化为字符串,求其长度,然后for遍历其长度,
如果num除10取余为0,则zero++,
否则num/10,除去最后一位.继续判断

推荐思路: 大佬 @iphelf 的思路

DFS深度优先搜索

*/
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 200 + 2;

int N, K;
int a[MaxN];
int b[MaxN];

int getFactor(long long x, int f) {
    int cnt = 0;
    while (x > 0 && x % f == 0) {
        ++cnt;
        x /= f;
    }
    return cnt;
}

int ans;
int currA;
int remainA[MaxN];
int currMaxA[MaxN][MaxN];
int currB;
int remainB[MaxN];
int currMaxB[MaxN][MaxN];

void dfs(int i, int k) {
    if (k == 0) {
        int curr = min(currA, currB);
        if (curr > ans) {
            ans = curr;
        }
        return;
    }
    if (N - i < k) return;
    if (currA + remainA[i] < ans || currB + remainB[i] < ans) return;
    if (currMaxA[i][k] >= currA && currMaxB[i][k] >= currB) return;
    if (currA >= currMaxA[i][k] && currB >= currMaxB[i][k]) {
        currMaxA[i][k] = currA;
        currMaxB[i][k] = currB;
    }
    { // choose
        currA += a[i];
        currB += b[i];
        dfs(i+1, k-1);
        currA -= a[i];
        currB -= b[i];
    }
    { // not choose
        dfs(i+1, k);
    }
}

int main() {
    while (~scanf("%d%d", &N, &K)) {
        long long x;
        for (int i = 0; i < N; i++) {
            scanf("%lld", &x);
            a[i] = getFactor(x, 2);
            b[i] = getFactor(x, 5);
        }
        remainA[N - 1] = a[N - 1];
        remainB[N - 1] = b[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            remainA[i] = remainA[i + 1] + a[i];
            remainB[i] = remainB[i + 1] + b[i];
        }
        currA = currB = 0;
        memset(currMaxA, -1, sizeof currMaxA);
        memset(currMaxB, -1, sizeof currMaxB);
        ans = -1;
        dfs(0, K);
        printf("%d\n", ans);
    }
    return 0;
}