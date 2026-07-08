class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string, int> mp;
        for(auto &s: words) mp[s]++;

        auto cmp = [&](auto &a, auto &b) {
            if(a.first == b.first) return a.second > b.second; // lexicographically smallest string upar hogi
            return a.first < b.first; // larger freq upar hogi
        };  

        // to write a custom comparator of pq, we always need to declare it like a min-heap first.
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for(auto [str, freq]: mp) pq.push({freq, str});

        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};