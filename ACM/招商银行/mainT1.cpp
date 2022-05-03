/* A 分发糖果
训练营有三位同学抽到了大奖，现在准备把一些糖果分发给这三位同学。
已知一共有n包糖果，每包糖果里有 2 颗或者3颗。
请问是否有一种分发方案，使得这三位同学拿到的糖果数量相等？
请注意，不能把整包糖果拆开分发。

3
3
2 3 3
4
2 2 2 3
8
2 3 2 2 2 2 3 2

Note: 注意在线模式的用法 **每输入一组数据，就会输出一个结果**
Output：
3
3
2 3 3
NO
4
2 2 2 3
NO
8
2 3 2 2 2 2 3 2
YES
*/

// 参考大佬：xywu

#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int>a[10];
vector<int>b[10];
int main() {
    scanf("%d", &t); // 读取第一行数字，数据组数

    while(t--) { // 循环输入并判断
        int n2 = 0, n3 = 0, sum = 0, x; // 定义变量：2的个数，3的个数，总和
        scanf("%d", &n); // 该组数据有几个数字

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == 2) n2++;
            else n3++;
            sum += x;
        }

        if (sum % 3 > 0) { // 因为是均分，总和只有是3的倍数才可能均分
            printf("NO\n");
            continue;
        }
        int s = sum / 3;
        a[1].clear();
        a[2].clear();
        a[3].clear();

        b[1].clear();
        b[2].clear();
        b[3].clear();

        for (int i = 0; i <= n2; i++) {
            for (int j = 0; j <= n3; j++) {
                if (i*2 + 3*j == s) { // 能够分配一位同学
                    a[1].push_back(i);
                    b[1].push_back(j);
                }
                if (i*2 + 3*j == 2*s) { // 能够分配二位同学
                    a[2].push_back(i);
                    b[2].push_back(j);
                }
                if (i*2 + 3*j == 3*s) { // 能够分配三位同学
                    a[3].push_back(i);
                    b[3].push_back(j);
                }
            }
        }
        int flag = 0; // 我当时也大概知道需要三层for循环遍历，但是不知道如何实现，大佬还是牛
        for (int i = 0; i < a[1].size(); i++) {
            for (int j = 0; j < a[2].size(); j++) {
                for (int k = 0; k < a[3].size(); k++) {
                    if (a[1][i] <= a[2][i] && a[2][i] <= a[3][i]
                    && b[1][i] <= b[2][i] && b[2][i] <= b[3][i]) {
                        flag = 1;
                    }
                    if (flag == 1) break;
                }
                if (flag == 1) break;
            }
            if (flag == 1) break;
        }

        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    // system("pause");
    return 0;
}
