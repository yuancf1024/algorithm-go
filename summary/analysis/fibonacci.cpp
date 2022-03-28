#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

// 初级递归实现，缺点：return 行出现了2次递归
int fibonacci(int i) {
    if (i <= 0) return 0;
    if (i == 1) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

// 非递归实现，仅考虑n <= 46的情况
int fibonacci_1(int i) {
    if (i <= 0) return 0;
    if (i == 1 || i == 2) return 1;
    int a = 1;
    int b = 1;
    for (int j = 2; j < i; j++) {
        int tmp = a;
        a = b;
        b = tmp + a;
    }
    cout << b <<endl;
    return 0;
}

// 优化的递归实现
int fibonacci_2(int first, int second, int n) {
    if (n <= 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    else if (n == 3) {
        return first + second;
    }
    else {
        return fibonacci_2(second, first + second, n - 1);
    }
}

void time_consumption() {
    int n;
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        // fibonacci(n);
        // fibonacci_2(1, 1, n);
        fibonacci_1(n);

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        cout << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
    }
}

int main() {
    time_consumption();
    return 0;
}