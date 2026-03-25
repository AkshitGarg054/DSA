class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for(auto num : barcodes) mp[num]++;

        priority_queue<pair<int, int>> pq; // {freq, int}
        for(auto [num, freq] : mp) pq.push({freq, num});

        vector<int> ans;
        while(pq.size() > 1) {
            auto curr = pq.top();
            pq.pop();
            auto prev = pq.top();
            pq.pop();

            ans.push_back(curr.second); // insert greater freq first
            curr.first--; // reduce freq
            ans.push_back(prev.second);
            prev.first--;

            if(curr.first > 0) pq.push(curr);
            if(prev.first > 0) pq.push(prev);
        }

        if (!pq.empty()) ans.push_back(pq.top().second);
        return ans;
    }
};