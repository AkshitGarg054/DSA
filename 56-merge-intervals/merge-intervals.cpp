class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int curr_l = intervals[0][0];
        int curr_r = intervals[0][1];

        for(int i = 1; i < n; i++) {
            int check_l = intervals[i][0];
            int check_r = intervals[i][1];

            if(check_l > curr_r) { // don't overlap anymore, create a new interval
                ans.push_back({curr_l, curr_r});
                curr_l = check_l;
                curr_r = check_r;
            }
            else curr_r = max(curr_r, check_r); // overlap
        }

        ans.push_back({curr_l, curr_r});
        return ans;
    }
};