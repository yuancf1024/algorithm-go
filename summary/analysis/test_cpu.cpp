#include <iostream>
#include <chrono>
#include <thread>
using namespace std; // 命名空间std内定义的所有标识符都有效（曝光）。就好像它们被声明为全局变量一样
/*
所谓namespace，是指标识符的各种可见范围.
为了避免名字冲突，就把标准库中的一切都被放在名字空间std中.
命名空间std封装的是标准程序库的名称，标准程序库为了和以前的头文件区别，一般不加".h"
*/
using namespace chrono; // chrono是c++ 11中的时间库，提供计时，时钟等功能

// O(n)
void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

// O(n^2)
void function2(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }
}

// O(nlogn)
void function3(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < n; j = j*2) { // 注意这里j=1
            k++;
        }
    }
}

int main() {
    long long n; // 数据规模
    while(1) {
        cout << "输入n：";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        // function1(n);
        function2(n);
        // function3(n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        cout << "耗时：" << milliseconds(end_time).count() - milliseconds(start_time).count()
            << " ms" << endl;
    }
}

/*
O(n)算法，输入n：100000000
耗时：122 ms
输入n：1000000000
耗时：1147 ms
输入n：500000000
耗时：583 ms

O(n^2)算法，输入n：1000
耗时：1 ms
输入n：10000
耗时：126 ms
输入n：20000
耗时：462 ms
输入n：25000
耗时：723 ms
输入n：22500
耗时：581 ms

O(nlogn)算法，输入n：1000000
耗时：31 ms
输入n：10000000
耗时：358 ms
输入n：20000000                            
耗时：739 ms
*/