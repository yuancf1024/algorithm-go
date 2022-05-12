#include <bits/stdc++.h>

using namespace std;

#define inf 1000000
#define N 30100
#define M 150100

int n, m, a[N], val[N];

struct Edge {
    int from, to, nex;
    bool sign;
}edge[M<<1];

int head[N], edgenum;

void add(int u, int v) {
    Edge E={u, v, head[u], false};
    edge[edgenum]= E;
    head[u] = edgenum++;
}

int DFN[N], Low[N], Stack[N], top, Time;
int taj;
int Belong[N];
bool Instack[N];
vector<int> bcc[N];

void tarjan(int u, int fa) {
    DFN[u] = Low[u] = ++ Time;
    Stack[top++] = u;
    Instack[u] = 1;

    for (int i = head[u]; ~i; i = edge[i].nex) {
        int v = edge[i].to;
        if (DFN[v] == -1) {
            tarjan(v, u);
            Low[u] = min(Low[u], Low[v]);
            if (DFN[u] < Low[v]) {
                edge[i].sign = 1;
            }
        }
        else if (Instack[v]) Low[u] = min(Low[u], DFN[v]);
    }
    if (Low[u] == DFN[u]) {
        int now;
        taj++;
        bcc[taj].clear();
        do{
            now = Stack[--top];
            Instack[now] = 0;
            Belong[now] = taj;
            bcc[taj].push_back(now);
        } while(now != u);
    }
}

void tarjan_init(int all) {
    memset(DFN, -1, sizeof(DFN));
    memset(Instack, 0, sizeof(Instack));
    top = Time = taj = 0;
    for (int i = 0; i < all; i++) {
        if (DFN[i] == -1)
            tarjan(i, i);
    }
}

vector<int>G[N];
int du[N];
void suodian() {
    memset(val, 0, sizeof(val));
    for (int i = 1; i <= taj; i++) {
        for (int j = 0; j < bcc[i].size(); j++) {
            if (a[bcc[i][j]]>0) val[i] += a[bcc[i][j]];
        }
    }
    memset(du, 0, sizeof(du));
    for (int i = 1; i <= taj; i++) {
        G[i].clear();
    }
    for (int i = 0; i < edgenum; i++) {
        int u = Belong[edge[i].from], v = Belong[edge[i].to];
        if (u != v) {
            G[u].push_back(v), du[v]++;
        }
    }
}

int D[N];
bool inq[N];
int spfa() {
    memset(inq, 0, sizeof(inq));
    queue<int>q;
    G[0].clear();
    q.push(0);
    D[0] = 0;
    val[0] = 0;
    for (int i = 1; i <= taj; i++) {
        if (du[i] == 0) {
            G[0].push_back(i);
            D[i] = -inf;
        }
    }
    int ans = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (D[v] < D[u] + val[v]) {
                D[v] = D[u] + val[v];
                ans = max(ans, D[v]);
                if (inq[v] == 0) inq[v]=1, q.push(v);
            }
        }
    }
    return ans;
}

int main() {
    int u, v, i, j;
    while(~scanf("%d %d", &n, &m)) {
        memset(head, -1, sizeof(head));
        edgenum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        while(m--) {
            scanf("%d %d", &u, &v), add(u, v);
        }
        tarjan_init(n);
        suodian();
        printf("%d\n", spfa());
    }
    return 0;
}

/*
2 2
1 1
1 2
2 1

2 2
14
21
0 1
1 0
*/