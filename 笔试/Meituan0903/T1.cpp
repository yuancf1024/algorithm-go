/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 乒乓球，被称为中国的“国球”，
 * 是一种世界流行的球类体育项目。
 * 一局比赛的获胜规则如下：

当一方赢得至少11分，并且超过对方2分及以上时，
获得该局的胜利。

按照上述规则，小美和小团正在进行一局比赛，
当前比赛尚未结束，此时小美的得分为a，小团的得分为b。
小美想知道，在最理想的情况下，
她至少还要得多少分才可以赢下这场比赛。

输入描述
输入两个整数a、b。
a表示当前小美获得的分数，b表示小团的分数。

0 ≤ a, b ≤ 99，保证输入的比分合法，
并且在该比分下比赛尚未结束。

输出描述
输出一个整数，表示小美至少还要得多少分
才能获得这局比赛的胜利。


样例输入
30 31

样例输出
3


提示
输入样例2

0 9
输出样例2

11

 

样例说明

样例1中小美获得了30分，小团获得31分，
小美再得3分，就能以33:31的比分获胜。

样例2中小美获得了0分，小团获得了9分，
小美再得11分，就能以11:9的比分获胜。
 */

/*
30 31
3

0 9
11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // int res;

    // 核心代码
    // if (a <= b && b >= 9) {
    //     res = b - a + 2;
    // } else if (a < 11){
    //     res = 11 - a;
    // } else if (a - b == 1){
    //     res = 1;
    // }
    // cout << res << endl;

    // 大佬的AK写法
    cout << max({0, b - a + 2, 11 - a});

    
    return 0;
}

/*
说明：
所有测试数据均已输出正确结果！
^_^
*/