#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 20
#define MAX_VEX 20
#define Vex 2
#define Arc 2

/*
需要自行输入：每一条边的起点和终点；
不能按照给定输入直接运行
*/


// 有向图邻接表的建立初始化
typedef enum{
	DG=1,AG,WDG,WAG//分别为无向图，有向图，带权无向图，带权有向图 
}Graphkind;

typedef struct Arcnode{
	int adjvex;//邻接点在数组中的位置
	struct Arcnode* nextarc;
	int info; //和弧相关的信息 
}Arcnode;

typedef struct Vnode{
	char data;
	Arcnode* firstarc;
}Vnode;

typedef struct {
	Vnode adjlist[MAX_VEX];
	int vexnum,arcnum;
	Graphkind kind;
}Algraph;

Algraph CreatGraph(Algraph &G,char a[],int n,int e) 
{

	G.vexnum=n;
	G.arcnum=e;
	for(int i=0;i<G.vexnum;i++)
	{
		G.adjlist[i].data=a[i];
		G.adjlist[i].firstarc=NULL;
	}
	for(int j=0;j<G.arcnum;j++)
	{
		int x,y;
		printf("依次输入每一条边的起点和终点：");
		scanf("%d%d",&x,&y);
		Arcnode* s=(Arcnode*)malloc(sizeof(Arcnode));
		s->adjvex=y;
		s->nextarc=G.adjlist[x].firstarc;
		G.adjlist[x].firstarc=s; 
	}
	return G;
}

// 深度优先遍历

int count[Vex]={0}; 
void DFStravel(Algraph G,int v)
{
	printf("%c ",G.adjlist[v].data);
	count[v]=1;
	Arcnode* p=G.adjlist[v].firstarc;
	while(p)
	{
		int j;
		j=p->adjvex;
		if(count[j]==0) DFStravel(G,j);
		p=p->nextarc;
	}
}

// 广度优先遍历

typedef struct squeue{
	int *data;
	int front;
	int rear;
}squeue;

void initsqueue(squeue& Q)
{
	Q.data=(int*)malloc(Maxsize*sizeof(int));
	Q.front=0;
	Q.rear=0;
}

void Enqueue(squeue& Q,int e)
{
	if((Q.rear+1)%Maxsize!=Q.front)
	{
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%Maxsize;
	}
}

int Dequeue(squeue& Q)
{
	int e;
	if(Q.rear!=Q.front)
	{
		e=Q.data[Q.front];
		Q.front=(Q.front+1)%Maxsize;
		return e;
	}
}

int visit[Vex]={0};
void BFStravel(Algraph G)
{
	squeue Q;
	initsqueue(Q);
	for(int i=0;i<G.vexnum;i++)
	if(visit[i]==0)
	{
	Enqueue(Q,i);
	visit[i]=1;
	while(Q.front!=Q.rear)
	{
		int k=Dequeue(Q);
		printf("%c ",G.adjlist[k].data);
		Arcnode* p=G.adjlist[k].firstarc;
		while(p)
		{
			int j=p->adjvex;
			if(visit[j]==0)
			{
				Enqueue(Q,j);
				visit[j]=1;
			}
			p=p->nextarc;
		}
	}		
	}
}


int main()
{
	char a[100]="ABCDEFGHIJK";
	Algraph G;
	CreatGraph(G,a,Vex,Arc);
	for(int i=0;i<Vex;i++)//把邻接表输出
	{
		printf("%d: %c ",i,G.adjlist[i].data);
		Arcnode* p=G.adjlist[i].firstarc;
		while(p)
		{
			printf("%d ",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
	for(int i=0;i<G.vexnum;i++)//对每个点进行深度优先遍历
	if(count[i]==0) DFStravel(G,i);
	printf("\n");
	BFStravel(G);
}