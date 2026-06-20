class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp; // to store {val -> index} mapping for O(1) lookups

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)) {
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)) {
            int index = mp[val];
            int last_val = arr.back();

            swap(arr[index], arr.back());
            arr.pop_back();
            
            mp[last_val] = index;
            mp.erase(val); // this needs to be below only (to handle the case where value removed is the last value itself)

            return true;
        }

        return false;
    }
    
    int getRandom() {
        int random_index = rand() % arr.size();
        return arr[random_index];
    }
};