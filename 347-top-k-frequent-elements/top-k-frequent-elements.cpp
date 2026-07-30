class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(auto &ele: nums) mp[ele]++;

        priority_queue<pair<int, int>> pq; // max heap

        for(auto &[ele, f]: mp) pq.push({f, ele});
        
        vector<int> ans;

        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};