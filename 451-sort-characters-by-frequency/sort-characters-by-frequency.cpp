class Solution {
public:
    // approach 2: using custom comparator
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<int, int> mp;
        for(auto ch: s) mp[ch]++;

        sort(s.begin(), s.end(), [&](char &a, char &b) {
            if(mp[a] == mp[b]) return a > b;
            return mp[a] > mp[b];
        });

        return s;
    }
};