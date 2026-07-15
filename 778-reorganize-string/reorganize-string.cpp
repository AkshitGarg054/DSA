class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(auto &ch: s) mp[ch]++;

        priority_queue<pair<int, char>> pq;
        for(auto &[ch, freq]: mp) pq.push({freq, ch});

        string ans = "";

        while(pq.size() >= 2) {
            auto [f1, ch1] = pq.top();
            pq.pop();
            auto [f2, ch2] = pq.top();
            pq.pop();

            ans += ch1;
            f1--;
            ans += ch2;
            f2--;

            if(f1 > 0) pq.push({f1, ch1});
            if(f2 > 0) pq.push({f2, ch2});
        }

        if(!pq.empty()) {
            auto [f, ch] = pq.top();
            if(f > 1) return ""; // not possible
            ans += ch;
        }

        return ans;
    }
};