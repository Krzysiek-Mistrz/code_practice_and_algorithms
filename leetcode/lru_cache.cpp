#include <unordered_map>
#include <list>

class LRUCache {
private:
    int cap; 
    std::list<std::pair<int, int>> cache_list;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map;

    void make_most_recently_used(int key) {
        cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
    }

public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }

        make_most_recently_used(key);

        return cache_map[key]->second;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            cache_map[key]->second = value;
            make_most_recently_used(key);

            return;
        }
        
        if (cache_list.size() == cap) {
            int oldest_key = cache_list.back().first;
            cache_map.erase(oldest_key);
            cache_list.pop_back();
        }
        
        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
    }
};