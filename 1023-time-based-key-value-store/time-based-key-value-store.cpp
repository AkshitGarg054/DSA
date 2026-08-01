class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        if(timestamp < mp[key][0].first) return "";
        
        // find the index of required timestamp pair in the vector
        int low = 0, high = mp[key].size() - 1;
        int index = low;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(mp[key][mid].first <= timestamp) {
                index = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }

        return mp[key][index].second;
    }
};