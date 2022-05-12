#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 1008: [HNOI2008]越狱[简单题]
题意：监狱有连续编号为1…N的N个房间，每个房间关押一个犯人，
有M种宗教，每个犯人可能信仰其中一种。
如果相邻房间的犯人的宗教相同，就可能发生越狱，
求有多少种状态可能发生越狱？

题解:我们考虑用总的方案减掉不能越狱的方案。也就是相邻两个不同的方案数。

拓展：如果题目改为恰好使用M种宗教的话那么做法为二项式反演了，因为可以反演出至多用M种宗教的方案。

input
2 3

output
6

*/

// #define g getchar()
// #define met(a, b) memset(a, b, sizeof(a))
// #define rep(i, a, b) for(int i = a; i <= b; i++)
// #define per(i, a, b) for(int i = a; i >= b; i--)
// #define fi first
// #define se second

// const int maxn = 1e5 + 10;
// const int inf = 0x3f3f3f3f;
// const double eps = 1e-8;
const int mod = 100003;
 
// inline ll read() {
//     ll x = 0, f = 1;
//     char ch = g;
//     while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = g;}
//     while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = g;}
//     //cout << f * x << endl;
//     return f * x;
// }
 
ll qp(ll base, ll n) {
    ll res = 1;
    while(n) {
        if(n & 1) res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}

// 该实现不能处理多组测试案例，每次只能处理一个case
int main() {
    ll m, n;
    scanf("%lld %lld", &m, &n); // m代表信仰，n代表犯人房间编号
    // m = read(); n = read();
    printf("%lld\n", (qp(m, n) % mod - m * qp(m - 1, n - 1) % mod + mod) % mod);
    return 0;
}