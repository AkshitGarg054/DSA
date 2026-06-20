class LRUCache {
private:
    unordered_map<int, pair<int, int>> mp; // key --> {value, last_used_time}
    int timer;
    int capacity;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        timer = 0;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            timer++;
            mp[key].second = timer;
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        timer++;
        mp[key] = {value, timer};

        if(mp.size() > capacity) { // evict the least recently used key
            int mini = INT_MAX;
            int required_key = -1;

            for(auto [key, p]: mp) {
                int k = key;
                int t = p.second;

                if(t < mini) {
                    mini = t;
                    required_key = k;
                }
            }

            mp.erase(required_key);
        }
    }
};
