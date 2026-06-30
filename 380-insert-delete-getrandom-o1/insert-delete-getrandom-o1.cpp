class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp; // value -> index 

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
            mp.erase(val); // this should be at the last, in order (to handle the case when val removed is the last val itself)
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int index = rand() % arr.size();
        return arr[index];
    }
};