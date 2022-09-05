/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 夏日生存狂想曲 20分
 * 
在别墅小岛上，有一群崩坏兽要进攻别墅了，米小游需要部署英雄们的防御。
在一张n*m的矩形地图上(地图行编号从1到n，列的编号从1到m)
米小游每次可以在一个格子中放置英雄，也有可以移除英雄，
每个格子最多只能存在一个英雄，你需要实现这个功能。

米小游总会做一些游戏开发者们意想不到的事情，比如：
将英雄放在已经存在英雄的格子上；
将英雄放置在地图外的格子上；
尝试移除某个空格子上的英雄(该格子为空，上面并没有英雄)；
尝试移除某个格子上的英雄，但该格子在地图外。
你需要忽略这些奇奇怪怪的非法操作，
只保留并响应合法的操作。

在按时间顺序进行q次操作后，你需要输出地图最终的英雄分布。

输入描述：
第一行三个整数n,m(1<=n,m<=100),q(1<=q<=10^5)
分别表示地图大小，操作个数。

接下来q行，每行输入三个整数t(1<=t<=2), 
x, y(-2^31<=x,y<=2^31-1)
当t=1时，再输入一个长度不超过20只由可见ASCII字符(不包括空格、回车)
组成的字符串s表示在地图第x行第y列格子放置一个名为s的英雄；
当t=2时表示移除地图第x行第y列格子的英雄。

输出描述：
输出n行，每行m个字符串表示地图每个格子上的英雄名字，
若格子内没有英雄，则输出"NULL".
(题目保证，不会有名字为NULL的英雄)


示例1：
1 2 7
1 1 1 Elysia
1 1 2 Elysia
1 0 0 Elysia
1 1 1 Elysia
2 1 1
2 1 1
2 0 0

NULL Elysia

示例2：
4 4 22
1 1 1 Kevin
1 1 2 Elysia
1 1 3 Aponia
1 1 4 Eden
1 2 1 Vill-V
1 2 2 Kalpas
1 2 3 Su
1 2 4 Sakura
1 3 1 Kosma
1 3 2 Mobius
1 3 3 Griseo
1 3 4 Hua
1 4 1 Pardofelis
1 1 1 ying
1 2 2 yingying
1 3 3 yingyingying
1 4 4 I'mElysia'sdog
1 520 1314 Elysiaismywife!
1 -114514 -1919810 biezaizhelifadian!
1 28930389 100179189 jiuzaizhelifadian!
2 4 4
2 810975 922768

Kevin Elysia Aponia Eden 
Vill-V Kalpas Su Sakura 
Kosma Mobius Griseo Hua 
Pardofelis NULL NULL NULL

 */

/*
通过全部测试案例!
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<string>> map(n, vector<string>(m, "NULL"));

    string s;
    int t;
    ll x, y;

    // 读入数据

    while (q > 0) {
        q--;
        cin >> t >> x >> y;;
        if (t == 1) {
            // 处理非法操作
            // 超出地图
            
            cin >> s;
            if (x < 1 || x > n || y < 1 || y > m) {
                continue;
            }
            // x,y已经存在英雄
            if (map[x-1][y-1] != "NULL") {
                continue;
            }
            // 正常操作 放置英雄
            map[x-1][y-1] = s;
        } else {
            // 超出地图
            if (x < 1 || x > n || y < 1 || y > m) {
                continue;
            }
            // 移除空格子上的英雄
            if (map[x-1][y-1] == "NULL") {
                continue;
            }
            
            // 移除英雄
            map[x-1][y-1] = "NULL";
        }
    }

    // 打印输出
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m-1;++j) {
            cout << map[i][j] << " ";
        }
        cout << map[i][m-1];
        cout << endl;
    }
    return 0;
}