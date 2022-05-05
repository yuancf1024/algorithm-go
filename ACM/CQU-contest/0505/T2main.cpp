/* T2 Knowledge competition 知识竞赛

Description

Doncic took part in a knowledge competition. 
There are three types of questions in the competition, 
including 0.5 points for question A, 1 point for question B and 
2 points for question C. Suppose the numbers of these three questions 
are a, b and c, respectively.
Please help him to calculate how many solutions there are to 
get the score n.


Input

The first line contains four integers —n,a,b,c
(1<=n<=100001<=n<=10000,0<=a,b,c<=50000<=a,b,c<=5000).


Output

Print the unique number — the solution to the problem. 
If it is impossible to getthe target score, print0.


Sample Input 1 

10 5 5 5

Sample Output 1

9

Sample Input 2 

3 0 0 2

Sample Output 2

0

题解: 给定3种数量分别为a,b,c的三类题,每题得分为0.5,1,2,求能组成总分n的方式?

比赛Golang实现思路: 首先判断无解的边界情况,那就是所有题的得分都小于n;
然后三层for循环依次遍历题目a,b,c的数量.注意a题得分为0.5,因此以2递增.

推荐思路: 大佬 @iphelf 的思路
动态规划 + 01背包问题

*/

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2e4 + 10;

typedef long long ll;

ll dp[4][MaxN];
int c[4]; // 记录a,b,c题目的数量
const int w[4] = {0, 1, 2, 4}; // 对应每题分数的2倍

int main() {
    int n;
    while (~scanf("%d%d%d%d", &n, c+1, c+2, c+3)) { // 当没有输入,那么返回-1,按位取反结果是0,于是跳出循环
        n *= 2; // 0.5分不好计算,于是就全部扩大2倍
        memset(dp, 0, sizeof dp); // dp数组全部置为0,memset将内存的前n个字节设置为特定的值
        dp[0][0] = 1;
        for (int k = 1; k <= 3; k++) { // k控制题目类型a,b,c
            for (int i = 0; i <= n; i++) { // i控制总分
                dp[k][i] = dp[k-1][i];
                for (int j = 1; j <= c[k]; j++) { // j控制题型c[k]的数量
                    if (j * w[k] > i) break; // j道k类型的习题分数如果超过i直接退出
                    dp[k][i] += dp[k-1][i-j*w[k]];
                }
            }
        }
        printf("%lld\n", dp[3][n]);
    }
    return 0;
}

