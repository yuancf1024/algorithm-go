/**
 * @file 860.Lemonade-Change.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdbool.h>

// #define num 10001
// for循环+条件判断的实现
bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five == 0) {
                return false;
            }
            five--;
            ten++;
        } else {
            if (five > 0 && ten >0) {
                five--;
                ten--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

// switch的条件判断实现
bool lemonadeChange1(int* bills, int billsSize) {
    // 分别记录五元、十元的数量（二十元不用记录，因为不会用到二十元找零）
    int fiveCount = 0;
    int tenCount = 0;

    for (int i = 0; i < billsSize; ++i) {
        // 分情况讨论每位顾客的付款
        switch(bills[i]) {
            // 情况一：直接收款五元
            case 5:
                fiveCount++;
                break;
            // 情况二：收款十元
            case 10:
                // 若没有五元找零，返回false
                if (fiveCount == 0) {
                    return false;
                }
                // 收款十元并找零五元
                fiveCount--;
                tenCount++;
                break;
            // 情况三：收款二十元
            case 20:
                // 若可以，优先用十元和五元找零
                // （因为十元只能找零20，所以需要尽量用掉。而5元能找零10元和20元）
                if (fiveCount > 0 && tenCount > 0) {
                    fiveCount--;
                    tenCount--;
                }
                // 若没有十元，但是有三张五元，就用三张五元找零
                else if (fiveCount >= 3) {
                    fiveCount -= 3;
                }
                // 若无法找开，返回false
                else {
                    return false;
                }
                break;
        }
    }
    // 全部都可以找开，返回true
    return true;
}

int main() {
    int billsSize = 5;
    int bills[5] = {5, 5, 5, 10, 20};

    bool res = lemonadeChange1(bills, billsSize);

    printf("%d\n", res);

    return 0;
}