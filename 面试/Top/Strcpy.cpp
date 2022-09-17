#include <bits/stdc++.h>

using namespace std;

char* strcpy(char* dst, const char* src) { // 源字符串参数用const修饰，防止修改源字符串
	// assert(dst != NULL && src != NULL);
    if (src == NULL || dst == NULL) {
        cout << "Error" << endl;
        return NULL;
    }
    char* ret = dst; // 返回目标地址
    while ((*dst++ = *src++) != '\0') {
    }
    return ret;
}

int main() {
    char dst[10];
    // char* dst = "Chris";
    char* src = "Yuan";
    char* res = strcpy(dst, src);
    // cout << *res << endl; // res是字符指针，如果单纯的打印输出，只会显示首字符
    for (; *res != '\0'; res++) { // 对于字符指针，应该遍历输出打印
        cout << *res;
    }
    return 0;
}