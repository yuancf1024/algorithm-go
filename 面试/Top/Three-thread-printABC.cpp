/**
 * @file Three-thread-printABC.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * 写三个线程交替打印ABC
 */

#include <bits/stdc++.h>

using namespace std;

mutex mymutex;

condition_variable cv;

int flag = 0;

void printA() { 
    unique_lock<mutex> lk(mymutex);
    int count = 0;
    while (count < 10) {
        while (flag != 0) { // 等于0时打印a，不等于等待
            cv.wait(lk);
        }
        cout << "thread 1: a" << endl;
        flag = 1;
        cv.notify_all();
        count++;
    }
    cout << "my thread 1 finish" << endl;
}

void printB() { 
    unique_lock<mutex> lk(mymutex);
    for (int i = 0; i < 10; ++i) {
        while (flag != 1) {
            cv.wait(lk);
        }
        cout << "thread 2: b" << endl;
        flag = 2;
        cv.notify_all();
    }
    cout << "my thread 2 finish" << endl;
}

void printC() {
    unique_lock<mutex> lk(mymutex);
    for (int i = 0; i < 10; ++i) {
        while (flag != 2) {
            cv.wait(lk);
        }
        cout << "thread 3: c" << endl;
        flag = 0;
        cv.notify_all();
    }
    cout << "my thread 3 finish" << endl;
}

int main() { 
    thread th1(printA); // 线程允许多个函数同时执行
    thread th2(printB);
    thread th3(printC);

    th1.join(); // 等待线程完成其执行
    th2.join();
    th3.join();

    cout << "main thread " << endl;

    return 0;
}

/*
g++ -o Three-thread-printABC Three-thread-printABC.cpp -lpthread

./Three-thread-printABC

$ ./Three-thread-printABC 
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
thread 2: b
thread 3: c
thread 1: a
my thread 1 finish
thread 2: b
my thread 2 finish
thread 3: c
my thread 3 finish
main thread 
 */