/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小红的乘法操作 20分
 * 
 * 小红可以对一个数进行如下两种操作：
 * 将这个数乘以x；或将这个数乘以y。操作的次数是没有限制的。
 * 小红想知道，自己最少经过多少次操作以后，可以把a变成b？
 * 
输入描述：
四个正整数x,y,a,b,用空格隔开
2<=x,y<=100
1<=a,b<=10^9

输出描述：
如果小红无论如何都无法把a变成b，则输出-1；
否则输出小红操作的最少次数。
可以证明，如果存在某种操作，那么最少次数一定是固定的。


示例1：
2 3 5 20

2

x=2,y=3，进行两次乘2操作，可以把5变成20
*/

/*
1. 直接慢慢除x，除y会超时 pass 50%
2. 改了一下 pass 56.25%
3. 增加返回-1的case pass 68.75% 没有超时，但是有的返回不正确
4. 将t%x t%y 的两个条件语句分开写 pass75%
5. 增加了无法操作成功，然后跳出while循环的条件 pass 87.5%





*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    // 核心代码
    int res = 0;
    if (b % a == 0) {
        int t = b / a;
        // 暴力搜索会超时
        while (t != 1) {
            int temp = t;
            
            if (t % x == 0) {
                t /= x;
                res++;
            } 
            if (t%y == 0) {
                t /= y;
                res++;
            }
            if (t == temp) {
                res= -1;
                break;
            }
        }
    } else if (a == b) {
        res = 0;
    }
    else {
        res = -1;
    }

    // while (b != a) {
    //     if (b % x == 0) {
    //         b /= x;
    //         res++;
    //     }
    //     if (b % y == 0) {
    //         b /= y;
    //         res++;
    //     }
    // }
    cout << res << endl;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main() { 
//     int x, y, a, b;
//     cin >> x >> y >> a >> b;

//     // 核心代码
//     int res = 0;
//     if (b % a == 0) {
//         int t = b / a;
//         // 暴力搜索会超时
//         while (t != 1) {
//             if (t % x == 0) {
//                 t /= x;
//                 res++;
//             } else if (t%y == 0) {
//                 t /= y;
//                 res++;
//             }
//         }
//     } else {
//         res = -1;
//     }

//     // while (b != a) {
//     //     if (b % x == 0) {
//     //         b /= x;
//     //         res++;
//     //     }
//     //     if (b % y == 0) {
//     //         b /= y;
//     //         res++;
//     //     }
//     // }
//     cout << res << endl;
//     return 0;
// }