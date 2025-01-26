// Problem : 146. LRU Cache
// Link : https://leetcode.com/problems/lru-cache/description/
// Topics : Hash Table, Linked List, Design, Doubly-Linked List
// Difficulty : Medium
// Time Complexity : O(1)
// Space Complexity : O(n)
// Solution 1 : Using Doubly Linked List and Hash Map
class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){ // Key doesn't exists
            return -1;
        }

        // key exists
        auto it = map[key];
        cache.splice(cache.begin(), cache, it); // place current key, value pair at the beginning (Most Recently used) position
        return it->second; // return value
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){ // key exists
            auto it = map[key];
            cache.splice(cache.begin(), cache, it);
            it->second = value;
            return;
        }

        // if cache is full - remove Least Recently Used from the cache and then from map
        if(cache.size() == capacity){
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }

        // if key doesn't exists and the cache is not full
        cache.emplace_front(key, value);
        map[key] = cache.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */