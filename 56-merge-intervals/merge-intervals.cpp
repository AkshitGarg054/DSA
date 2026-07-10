class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> prev = intervals[0];

        for(int i = 1; i < n; i++) {
            vector<int> curr = intervals[i];

            if(prev[1] >= curr[0] && prev[1] <= curr[1]) {
                prev[0] = min(prev[0], curr[0]);
                prev[1] = max(prev[1], curr[1]);
            }
            else if(prev[1] < curr[0]) {
                ans.push_back(prev);
                prev = curr;
            }
        }

        ans.push_back(prev);
        return ans;
    }
};