class RandomizedSet {
public:
    unordered_map<int, int> mp; // value -> index
    vector<int> arr;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)) {
            mp[val] = arr.size();
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)) {
            int index = mp[val];
            int prev_index = arr.size() - 1;
            swap(arr[index], arr[prev_index]);

            mp[arr[index]] = index; // update the index of last element
            mp.erase(val);
            arr.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index = rand() % arr.size();
        return arr[index];
    }
};
