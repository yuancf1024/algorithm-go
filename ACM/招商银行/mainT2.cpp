/* B 海滩网络
N(1≤N≤10^5) 位同学在海滩参加团建，
现在想要建立一个通讯网络供同学们沟通和交流。
第 i 个同学的位置以唯一的 (xi,yi) 来表示,
其中 0<= xi ≤10^6,0≤yi≤10 。
通信网络的架设成本为：(x_i- x_j)^ 2+(y_i-y_j)^2。
若两位同学间有一条链路（节点直接相连或链路由多个子连
接构成），那么这两位同学就可以正常通讯。
请计算出搭建一套能供所有同学正常通讯的网络所需的最小成本。

input：
10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0
output：
660
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 使用节点Node存储每位同学的坐标x、y
struct node {
    ll x, y;
};

node p[100005];
int t, n, m; // m 记录总边数

// 使用edge存储每位同学的的相邻距离平方和
struct edge {
    int u, v; // 节点序号
    ll w; // 坐标差的平方和
} a[10000015];

// cmp 按照节点x排序
bool cmp(const node &l, const node &r) {
    return l.x < r.x;
}

// cmp1 按照w排序
bool cmp1(const edge &l, const edge &r) {
    return l.w < r.w;
}

int fa[100005];

// 找到序号为x的边
int find_fa(int x) {
    return x == fa[x] ? x : fa[x]=find_fa(fa[x]);
}

void find_mst() {
    sort(a+1, a+m+1, cmp1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        int u = a[i].u;
        int v = a[i].v;
        int fu = find_fa(u);
        int fv = find_fa(v);
        if (fu == fv) continue;
        fa[fu] = fv;
        cnt++;
        ans += a[i].w;
        if (cnt == m - 1) break;
    }
    printf("%lld\n", ans);
}

int main() {
    scanf("%d", &n); // 读取第一行数字，N个节点
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &p[i].x, &p[i].y); // 分别读取N个坐标
    }

    sort(p+1, p+n+1, cmp); // 根据每组数据的x坐标按照从小到大排序
    edge e; // 定义边

    m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= i+100 && j <= n; j++) {
            ll w = (p[i].x - p[j].x) * (p[i].x - p[j].x) + \
            (p[i].y - p[j].y) * (p[i].y - p[j].y);
            e.w = w;
            e.u = i;
            e.v = j;
            a[++m] = e;
        }
    }

    find_mst();
    // system("pause");
    return 0;
}