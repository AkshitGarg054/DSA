class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        // {sum, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // min heap

        // convert nums1 and nums2 in a matrix in your mind.
        // push only the 0th column for now.
        for(int i = 0; i < min(k, n); i++) pq.push({nums1[i] + nums2[0], i, 0});

        vector<vector<int>> ans;
        int count = 0;

        while(!pq.empty() && count < k) {
            auto it = pq.top();
            pq.pop();

            int i = it[1], j = it[2];
            ans.push_back({nums1[i], nums2[j]});
            if(j + 1 < m) pq.push({nums1[i] + nums2[j + 1], i, j + 1}); // push the next element of ith row 

            count++;
        }

        return ans;
    }
};