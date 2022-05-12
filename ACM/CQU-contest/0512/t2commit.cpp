#include<bits/stdc++.h>
using namespace std;

#define inf 1000000
#define N 30100 //N为点数
#define M 150100 //M为边数

int n, m, a[N], val[N];

/*
POJ 3160 求有向图(点权)遍历的最大权值 强连通缩点+最长路 
题意：给定n个点 m条有向边的图，每个点的点权

问：遍历一遍图能得到的最大点权（对于经过的点，可以选择是否获得该点点权，
但每个点只能被获得一次）。起点可以任意。

思路：我们把有向图缩点为有向的缩点树，则某一强连通块的权值
就是该连通块下的所有正点权值和；
这样我们就可以得到一个有向无环图，显然我们选择的起点是入度为0 的点，
因为所有入度不为0的点 都能从别的点走过来。
因此我们建立虚根连接所有入度为0的点，然后跑一遍最长路spfa。

测试案例：

input
2 2
1 1
1 2
2 1

output
2
参考：https://blog.csdn.net/acmmmm/article/details/18367575

*/

struct Edge{
	int from, to, nex;
	bool sign;//是否为桥
}edge[M<<1];

int head[N], edgenum;

void add(int u, int v){
	Edge E={u, v, head[u], false};
	edge[edgenum] = E;
	head[u] = edgenum++;
}
 
int DFN[N], Low[N], Stack[N], top, Time;
int taj;//连通分支标号，从1开始
int Belong[N];//Belong[i] 表示i点属于的连通分支
bool Instack[N];

vector<int> bcc[N]; //标号从1开始
 
void tarjan(int u ,int fa){  
	DFN[u] = Low[u] = ++ Time ;  
	Stack[top ++ ] = u ;  
	Instack[u] = 1 ;  
 
	for (int i = head[u] ; ~i ; i = edge[i].nex ){  
		int v = edge[i].to ;  
		if(DFN[v] == -1)
		{  
			tarjan(v , u) ;  
			Low[u] = min(Low[u] ,Low[v]) ;
			if(DFN[u] < Low[v])
			{
				edge[i].sign = 1;//为割桥
			}
		}  
		else if(Instack[v]) Low[u] = min(Low[u] ,DFN[v]) ;
	}  
	if(Low[u] == DFN[u]){  
		int now;
		taj ++ ; bcc[taj].clear();
		do{
			now = Stack[-- top] ;  
			Instack[now] = 0 ; 
			Belong [now] = taj ;
			bcc[taj].push_back(now);
		}while(now != u) ;
	}
}
 
void tarjan_init(int all){
	memset(DFN, -1, sizeof(DFN));
	memset(Instack, 0, sizeof(Instack));
	top = Time = taj = 0;
	for(int i=0;i<all;i++)if(DFN[i]==-1 )tarjan(i, i); //注意开始点标！！！默认从0开始
}
vector<int>G[N];
int du[N];
void suodian(){
	memset(val, 0, sizeof(val));
	for(int i = 1; i <= taj; i++)for(int j = 0; j < bcc[i].size(); j++)if(a[bcc[i][j]]>0)val[i] += a[bcc[i][j]];
	memset(du, 0, sizeof(du));
	for(int i = 1; i <= taj; i++)G[i].clear();
	for(int i = 0; i < edgenum; i++){
		int u = Belong[edge[i].from], v = Belong[edge[i].to];
		if(u!=v)G[u].push_back(v), du[v]++;
	}
 
}

int D[N];
bool inq[N];

int spfa(){
	memset(inq, 0, sizeof(inq));
	queue<int>q;
	G[0].clear();
	q.push(0);
	D[0] = 0;	val[0] = 0;
	for(int i = 1; i <= taj; i++){if(du[i] == 0)G[0].push_back(i); D[i] = -inf;}
	int ans = 0;
	while(!q.empty()){
		int u = q.front(); q.pop(); inq[u] = 0;
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			if(D[v] < D[u] + val[v])
			{
				D[v] = D[u] + val[v];
				ans = max(ans, D[v]);
				if(inq[v] == 0)inq[v] = 1, q.push(v);
			}
		}
	}
	return ans;
}

int main(){
	int u, v, i, j;
	while(~scanf("%d %d",&n,&m)){
		memset(head, -1, sizeof(head)); edgenum = 0;
		for(i = 0; i < n; i++)scanf("%d",&a[i]);
		while(m--) {
			scanf("%d%d",&u,&v); // 模板实现输入节点从0开始标号。而测试用例从1开始编号，因此对输入数据的节点号都减一
			u = u-1;
			v = v-1;
			add(u,v);
		}
		tarjan_init(n);
		suodian();
		printf("%d\n",spfa());
	}
	return 0;
}
