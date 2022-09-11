/**
 * @file hihoCoder1097-Kruskal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 *  1098 : 最小生成树二·Kruscal算法 描述
随着小Hi拥有城市数目的增加，在之间所使用的Prim算法已经无法继续使用了——
但是幸运的是，经过计算机的分析，小Hi已经筛选出了一些比较适合建造道路的路线，
这个数量并没有特别的大。
所以问题变成了——小Hi现在手上拥有N座城市，且已知其中一些城市间建造道路的费用，
小Hi希望知道，最少花费多少就可以使得任意两座城市
都可以通过所建造的道路互相到达（假设有A、B、C三座城市，
只需要在AB之间和BC之间建造道路，那么AC之间也是可以通过这两条道路连通的）。
提示：积累的好处在于可以可以随时从自己的知识库中提取想要的！
输入
每个测试点（输入文件）有且仅有一组测试数据。
在一组测试数据中：
第1行为2个整数N、M，表示小Hi拥有的城市数量和小Hi筛选出路线的条数。
接下来的M行，每行描述一条路线，其中第i行为3个整数N1_i, N2_i, V_i，
分别表示这条路线的两个端点和在这条路线上建造道路的费用。
对于100%的数据，满足N<=10^5, M<=10^6，
于任意i满足1<=N1_i, N2_i<=N, N1_i≠N2_i, 1<=V_i<=10^3.
对于100%的数据，满足一定存在一种方案，
使得任意两座城市都可以互相到达。
输出
对于每组测试数据，输出1个整数Ans，表示为了使任意两座城市
都可以通过所建造的道路互相到达至少需要的建造费用。
注意：Kruskal算法如何检查插入一个边是否会构成环路呢？
如果把这个最小生成树看成一个集合，那么插入一个会构成环路的边
就相当于把两个本就属于同一个集合的点连接到成在同一个集合中。
所以，可以使用并查集的数据结构来解决这个问题。


Sample Input
5 29
1 2 674
2 3 249
3 4 672
4 5 933
1 2 788
3 4 147
2 4 504
3 4 38
1 3 65
3 5 6
1 5 865
1 3 590
1 4 682
2 4 227
2 4 636
1 4 312
1 3 143
2 5 158
2 3 516
3 5 102
1 5 605
1 4 99
4 5 224
2 4 198
3 5 894
1 5 845
3 4 7
2 4 14
1 4 185


Sample Output
92

*/


/*
Kruskal算法原理：
现在我们假设一个图有m个节点，n条边。
首先，我们需要把m个节点看成m个独立的生成树，
并且把n条边按照从小到大的数据进行排列。
在n条边中，我们依次取出其中的每一条边，
● 如果发现边的两个节点分别位于两棵树上，那么把两棵树合并成为一颗树；
● 如果树的两个节点位于同一棵树上，那么忽略这条边，继续运行。
● 等到所有的边都遍历结束之后，如果所有的生成树可以合并成一条生成树，
那么它就是我们需要寻找的最小生成树，反之则没有最小生成树。
参考：https://blog.csdn.net/liangzhaoyang1/article/details/51050408
*/

#include<bits/stdc++.h>

using namespace std;

int arr[100001];//用于保存节点的pre节点序号
int size[100001];//用于保存每个树的大小

void init(int n){//并查集的初始化
    for(int i=1;i<=n;i++)arr[i]=i;
    for(int i=1;i<=n;i++)size[i]=1;
}

int find(int i){//找树的祖先节点
    while(arr[i]!=i)i=arr[i];
    return i;
}

bool connect(int i,int j){//连接两个节点
    int a=find(i),b=find(j);
    if(a==b)return false;
    if(size[a]>size[b]){
        size[a]+=size[b];
        arr[b]=a;
    }else {
        size[b]+=size[a];
        arr[a]=b;
    }
    return true;
}

int main(){
    
    int n,m;
    cin>>n>>m;
    init(n);
    vector<int>mark(n);
    vector<vector<int>>road(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>road[i][0]>>road[i][1]>>road[i][2];
    }
    int totalcost=0;
    auto comp=[](vector<int>a,vector<int>b)->bool{//将所有的边按权值的大小升序排序，以便构造最小生成树
        return a[2]<b[2];
    };
    sort(road.begin(),road.end(),comp);
    for(int i=0,counter=1;i<m&&counter<n;i++){//注意，最小生成树的边为n-1
        if(connect(road[i][0], road[i][1])){//如果连接成功，则统计费用
            totalcost+=road[i][2];
            counter++;
        }
    }
    cout<<totalcost<<endl;//输出结果
}