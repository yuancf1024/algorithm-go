#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
#define x first
#define y second
typedef long long LL;
typedef pair<int, int> PII;
PII a[N];
int p[N];
int n, m;

struct Edge {
    int a, b;
    LL w;
    bool operator <(const Edge &E) const {
        return w < E.w;
    }
} e[N*25];

LL get_w(int x1, int y1, int x2, int y2) {
    LL dx = abs(x1-x2), dy = abs(y1-y2);
    return dx*dx + dy*dy;
}

int find(int x) {
    if (p[x] == x) return p[x];
    return p[x] = find(p[x]);
}

void kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(e+1, e+1+m);
    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        int x = find(e[i].a), y = find(e[i].b);
        if (x != y) {
            p[x] = y;
            ans += e[i].w;
        }
    }
    printf("%lld", ans);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= i+20 && j <= n; j++) {
            e[++m] = {i, j, get_w(a[i].x, a[i].y, a[j].x, a[j].y)};
        }
    }
    kruskal();
    return 0;
}