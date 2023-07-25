#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief
 * 1. 改变形参值，不会影响到实参，因此在Test1中的GetMemory返回之后，str依然为NULL
 * 2. strcpy不安全
 * 3. malloc没有free内存泄露
*/
// Test1
void GetMemory1(char* p) { 
    p = (char*)malloc(100); 
}

void Test1(void) { 
    char* str = NULL;
    GetMemory1(str);
    strcpy(str, "hello world");
    printf("%s\n", str);
}
// GetMemory并不能传递动态内存，Test函数中的str一直都是NULL
// strcpy(str, "hello world"); 将使程序崩溃

/**
 * @brief 
 * 1. 返回局部变量的指针，GetMemory返回时p已无效
 */
char *GetMemory2(void) {
    char p[] = "hello world";
    return p;
}

void Test2(void) {
    // char *str = GetMemory2();
    char *str = NULL;
    str = GetMemory2();
    printf("%s\n", str);
}

/**
 * @brief
 *
 */
char *GetMemory3(void) {
    return "hello world";
}

void Test3(void) {
  char *str = NULL;
  str = GetMemory3();
  printf("%s\n", str);
}


int main() {
  
    // printf("Test1的输出: \n");
    // Test1();

    // printf("Test2的输出: \n");
    // Test2();

    printf("Test3的输出: \n");
    Test3();
}

