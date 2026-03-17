class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int, int>> starts(n); // {start, original index}
        for(int i = 0; i < n; i++) starts[i] = {intervals[i][0], i};

        sort(starts.begin(), starts.end()); // lower bound is applied on sorted array only

        // we need to find the lower bound for every interval[1]
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int lb = lower_bound(starts.begin(), starts.end(), make_pair(intervals[i][1], -1)) - starts.begin();
            if(lb == n) ans[i] = -1;
            else ans[i] = starts[lb].second; 
        }

        return ans;
    }
};