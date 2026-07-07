class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        int start = newInterval[0];
        int end = newInterval[1];
        int index = -1;

        for(int i = 0; i < n; i++) {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if(curr_end < start) ans.push_back({curr_start, curr_end});
            else if(end < curr_start) {
                ans.push_back({start, end});
                index = i; // newInterval inserted till here
                break;
            }
            else {
                start = min(curr_start, start);
                end = max(curr_end, end);
            } 
        }

        if(index == -1) { // newInterval belongs to end 
            ans.push_back({start, end});
            index = n;
        }

        for(int i = index; i < n; i++) ans.push_back({intervals[i][0], intervals[i][1]});
        return ans;
    }
};