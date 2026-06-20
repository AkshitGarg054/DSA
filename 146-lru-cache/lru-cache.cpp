class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll; // the list stores pairs of {key, val}
    unordered_map<int, list<pair<int, int>>::iterator> mp; // the map links the key to the exact location (iterator) of the node in the list

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        // if key exists, move it to the front using splice
        dll.splice(dll.begin(), dll, mp[key]); // splice(destination, source_list, element_iterator)
        return mp[key] -> second; // return the value 
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            mp[key] -> second = value;
            dll.splice(dll.begin(), dll, mp[key]);
            return;
        }

        if(dll.size() == capacity) {
            int lru_key = dll.back().first;
            dll.pop_back();
            mp.erase(lru_key);
        }

        // insert the new key-value pair at the front
        dll.push_front({key, value});
        mp[key] = dll.begin(); // store its iterator in the map
    }
};
