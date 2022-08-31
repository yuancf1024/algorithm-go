/**
 * @file Singleton.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 线程安全的单例模式
 * 
 * 要理解单例模式，只需要一个实例就可以了。
 * 比如，一台计算机上可以连好几台打印机，
 * 但是这个计算机上的打印程序只能有一个，
 * 这里就可以通过单例模式来避免两个打印作业同时输出到打印机中，
 * 即在整个的打印过程中只有一个打印程序的实例。
 * 对于这种问题，《设计模式》一书中给出了一种很不错的实现，
 * 
 * 定义一个单例类，使用类的私有静态指针变量指向类的唯一实例，
 * 并用一个公有的静态方法来获取该实例。
 * 
 * 单例模式的作用就是保证在整个应用程序的生命周期中的任何一个时刻，
 * 单例类的实例都只存在一个（当然也可以不存在）。
 * 
 * 单例模式通过类本身来管理其唯一实例，唯一的实例是类的一个普通对象，
 * 但设计这个类时，让它只能创建一个实例并提供对此实例的全局访问
 * 
 * 单例模式思路：静态成员建议在类外进行初始化
 * 
 * 1. 构造函数声明为private或protect防止被外部函数实例化
 * 2. 内部保存一个private static的类指针保存唯一的实例
 * 3. 实例的动作由一个public的类方法代劳
 * 
 * 懒汉模式：在getinstance中实例化
 * 饿汉模式：在单例类定义时实例化
 */

#include <bits/stdc++.h>

using namespace std;

/*
懒汉模式：只有当调用getInstance的时候，才会去初始化这个单例
*/
class Singleton {
private:
    static Singleton* m_pInstance; // 使用类的私有静态指针变量指向类的唯一实例
    Singleton() { // 构造函数私有
        // 初始化
    }
    ~Singleton(){}

public:
    static Singleton* GetInstance() { // 用一个公有的静态方法来获取该实例
        if (m_pInstance == nullptr) { // 判断是否第一次调用
            m_pInstance = new Singleton();
        }
        return m_pInstance;
    }
};

// 静态成员在类外初始化
Singleton* Singleton::m_pInstance = nullptr; // 初始化静态数据成员

int main() {
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();

    if (s1 == s2) {
        cout << "s1 == s2" << endl;
    }
    return 0;
}

/*
s1 == s2
*/

/*
饿汉模式：类一旦加载，就把单例初始化完成，
保证getInstance的时候，单例是已经存在的了
*/

class single {
private:
    static single* p;
    single(){}
    ~single(){}

public:
    static single* getinstance();

};

single* single::p = new single();
single* single::getinstance() {
    return p;
}