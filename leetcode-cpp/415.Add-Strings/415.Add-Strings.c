/**
 * @file 415.Add-Strings.c
 * @author your name (you@domain.com)
 * @brief leetcode-415.字符串相加 C
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char* ans = (char*)malloc(sizeof(char) * (fmax(i, j) + 3));
    int len = 0;

    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[len++] = '0' + result % 10;
        add = result / 10;
        i--, j--;
    }
    // 计算完以后的答案需要翻转过来
    for (int i = 0; 2 * i < len; i++) {
        int t = ans[i];
        ans[i] = ans[len - i - 1], ans[len- i - 1] = t;
    }
    ans[len++] = 0;
    return ans;
}

int main() {
    char* s1 = "123";
    char* s2 = "11";

    char* res = addStrings(s1, s2);

    // 打印结果输出
    while (*res != '\0') {
        printf("%c", *res++);
    }

    printf("\n");

    return 0;
}