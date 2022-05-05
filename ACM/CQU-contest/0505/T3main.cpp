/* T4 Pour water 倒水
Description

In order to explain the traversal algorithm, the teacher specially 
bought three water bottles with the capacity of A, B and C. 
At first, the water bottle An and B was empty, 
while C was filled with water. Water can be poured from one water 
bottle to another, but each time the water bottle must be emptied 
or filled. Find all the amount of water left in the C water bottle 
when bottle An is empty.

Input
A separate line consists of three integers A, B, and C(1≤A,B,C≤40).

Output
There is only one line that lists all the water contained in bottle 
C when A is empty, output in ascending order. Numbers are separated 
by spaces, and there are no spaces before the first number and 
after the last number.

Sample Input 1 

8 9 10

Sample Output 1

1 2 8 9 10

Hint

For example, pour out 8 to A in C, pour the remaining 2 into B, 
and then pour all the water in A into C, then there is 8 water in C.

题解: 3个杯子A,B,C倒水,其中开始的时候A、B为空,C装满水,求操作一波后,C能够装的水的容量.

比赛Golang实现思路: 遍历,条件判断c和a、b之间的大小关系,然后将c,c-a,c-b,a-b添加进数组;
最后对数组从小到大排序,然后输出.

推荐思路: 大佬 @iphelf 的思路

DFS深度优先搜索

*/

// 该实现有bug
/*
无法处理有2个被子容量相同的case
input
6 7 7
true output
1 6 7
***********
程序output
0 1 6 7
***********
*/

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 500;

bool visited[MaxN][MaxN][MaxN];
int v[3];
int c[3];
set<int> ans;

void dfs() {
    if (visited[c[0]][c[1]][c[2]]) return;
    visited[c[0]][c[1]][c[2]] = true;
    if (c[0] == 0) ans.insert(c[2]);
    int moved;
    for (int from = 0; from < 3; from++) {
        for (int to = 0; to < 3; to++) {
            if (from != to) {
                moved = min(c[from], v[to] - c[to]);
                c[from] -= moved;
                c[to] += moved;
                dfs();
                c[from] += moved;
                c[to] -= moved;
            }
        }
    }
}

int main() {
    while (scanf("%d%d%d", &v[0], &v[1], &v[2]) != EOF) {
        for (int i = 0; i <= v[0]; i++) {
            for (int j = 0; j <= v[1]; j++) {
                for (int k = 0; k <= v[2]; k++) {
                    visited[i][j][k] = false;
                }
            }
        }
        c[0] = c[1] = 0;
        c[2] = v[2];
        ans.clear();
        dfs();
        vector<int> vAns(ans.begin(), ans.end());
        sort(vAns.begin(), vAns.end());
        for (int i = 0; i < vAns.size(); i++) {
            printf("%d%c", vAns[i], i == vAns.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}