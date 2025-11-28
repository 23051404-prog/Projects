#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    list<pair<int,int>> dll; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();

        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if (dll.size() == capacity) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

int main() {
    LRUCache cache(2);

    cout << cache.get(2) << endl;  
    cache.put(2, 6);
    cout << cache.get(1) << endl;  
    cache.put(1, 5);
    cache.put(1, 2);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;

    return 0;
}
