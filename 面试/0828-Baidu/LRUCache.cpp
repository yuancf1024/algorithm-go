#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    map<int, list<pair<int,int>>::iterator> Cache;
    list<pair<int, int>> Dlist;
    int cap;
public:
    LRUCache(int c) { 
        cap = c; 
    }

    // 查
    int get(int key) {
        // 未查到
        if (Cache.find(key) == Cache.end()) {
            return -1;
        }
        // 查到 更新链表位置
        else {
            auto it = Cache.find(key)->second;
            int value = (*it).second;

            Dlist.erase(it);
            Dlist.push_front({key, value});
            Cache[key] = Dlist.begin();
            return value;
        }
    }
    // 增
    void put(int key, int value) {
        auto it = Cache.find(key);
        // 增加已有
        if (it != Cache.end()) {
            auto listIt = it->second;

            Dlist.erase(listIt);
            Dlist.push_front({key, value});
            Cache[key] = Dlist.begin();
        }
        // 增加新的
        else {
            // 超过容量
            if (Cache.size() >= cap) {
                // 删除
                auto pairOld = Dlist.back();
                Dlist.pop_back();
                Cache.erase(pairOld.first);
            }
            else {
            // 未 直接加
            Dlist.push_front({key, value});
            Cache[key] = Dlist.begin();
            }
        }
    }
};

int main() {
    int cap = 10;
    LRUCache* lru = new LRUCache(cap);
    lru->put(1,2);
    int res = lru->get(1);
    cout << res << endl;
    return 0;
}