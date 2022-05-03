/* C 训练营合影
训练营圆满结束，同学们站在一起合影。
已知第i个同学喜欢的颜色是ai
​（注：可能有多个同学喜欢同一种颜色）。
合影的照片用一个数组表示，bi代表照片第i段的颜色。
对于一个照片的区间而言，只要这个区间存在某同学喜欢的颜色，
这个同学就会喜欢这个区间。
现在有q次询问，每次询问一个区间[l,r]
有多少个同学喜欢。

input:
4 5 // 同学数量，照片长度
2 6 3 6 // 同学喜欢的颜色
1 6 3 6 6 // 合影照片每一段的颜色。
3
1 1
2 3
4 5

output:
0
3
2

*/

// 这个程序不太好理解，根据群友的反馈，直接使用哈希表是会超时的

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn], c[maxn], b[maxn];

struct node {
    int l, r, id;
} s[maxn];

int n, m, o, q, t;
int num[maxn], sum[maxn], ans[maxn];

bool cmp(const node &x, const node &y) {
    if (x.l/t == y.l/t) return x.r > y.r;
    return x.l < y.l;
}

int main() {
    memset(a, 0, sizeof a); // a 存储每个同学喜欢的颜色
    memset(b, 0, sizeof b); // 存储a、c中的颜色
    memset(c, 0, sizeof c); // c 存储合影照片每一段的颜色
    memset(num, 0, sizeof num);
    memset(sum, 0, sizeof sum);

    scanf("%d%d", &n, &m); // n代表 同学数量，m 代表照片长度
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[++cnt] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
        b[++cnt] = c[i];
    }
    sort(b+1, b+cnt+1); // 按照颜色从小到大排序
    o = unique(b+1, b+cnt+1) - b - 1; // 去重，b中颜色数量

    // cout << "color num: " << o << endl;

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b+1, b+o+1, a[i]) - b; // a[i]存储的是在b中的序号
        num[a[i]]++; // a中颜色的数量
    }

    for (int i = 1; i <= m; i++) {
        c[i] = lower_bound(b+1, b+o+1, c[i]) - b;
    }

    // 调试打印
    // puts("a");
    // for (int i = 1; i <= n; i++) {
    //     printf("%d", a[i]);
    // }
    // puts("");

    // puts("c");
    // for (int i = 1; i <= m; i++) {
    //     printf("%d", c[i]);
    // }
    // puts("");
    /*
    4 5
    2 6 3 6
    1 6 3 6 6
    3
    1 1
    2 3
    4 5a
    2434
    c
    14344
    */

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &s[i].l, &s[i].r); // s 存储询问区间
        if (s[i].r < s[i].l) swap(s[i].l, s[i].r);
        s[i].id = i;
    }

    t = (int)(sqrt(1.0*m) + 0.5); // 作用？

    sort(s+1, s+q+1, cmp);
    int l = 0, r = 0, res = 0;
    for (int i = 1; i <= q; i++) {
        while (r < s[i].r) {
            r++;
            sum[c[r]]++;
            if (sum[c[r]] == 1) {
                res += num[c[r]];
            }
        }

        while (r > s[i].r) {
            sum[c[r]]--;
            if (sum[c[r]] == 0) {
                res -= num[c[r]];
            }
            r--;
        }

        while (l > s[i].l) {
            l--;
            sum[c[l]]++;
            if (sum[c[l]] == 1) {
                res += num[c[l]];
            }
        }

        while (l < s[i].l) {
            sum[c[l]]--;
            if (sum[c[l]] == 0) {
                res -= num[c[l]];
            }
            l++;
        }
        ans[s[i].id] = res;
    }
    
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }

    // system("pause");
    return 0;
}
