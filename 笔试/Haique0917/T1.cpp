/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 朋友们的喜好
 * 
 * 直接模拟 用python
 */


/* 笑死😂 用python写
name = ['Niumei', 'YOLO', 'Niu Ke Le', 'Mona'];
friends = [];
friends.append(name);

food = ['pizza', 'fish', 'potato', 'beef'];
friends.append(food);
number = [3, 6, 0, 3];
friends.append(number);

print(friends);
*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    vector<string> name = {"Niumei", "YOLO", "Niu Ke Le", "Mona"};
    vector<string> food = {"pizza", "fish", "potato", "beef"};
    vector<int> number = {3, 6, 0, 3};
    for (int i = 0; i < 4; ++i) {
        cout << name[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        cout << food[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        cout << number[i] << " ";
    }
    cout << endl;
    return 0;
}