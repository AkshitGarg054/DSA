class Solution {
public:
    // Sorting + LIS (We need both width and height to be strictly increasing)
    // Sort by width in ascending order. If widths are equal, sort heights in descending order.
    // Because two envelopes with the same width cannot fit inside each other. Sorting heights in descending order ensures they won't both be included in the increasing subsequence.

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [&](auto &a, auto &b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> arr;
        for(int i = 0; i < n; i++) arr.push_back(envelopes[i][1]); // we just need the order of heights sorted based on the widths to find the LIS

        vector<int> dp; // dp stores the smallest possible ending element for every LIS length

        for(int i = 0; i < n; i++) {
            int h = arr[i];
            int pos = lower_bound(dp.begin(), dp.end(), h) - dp.begin(); // find the index of height > h

            if(pos == dp.size()) dp.push_back(arr[i]);
            else dp[pos] = arr[i];
        }

        return dp.size();
    }
};