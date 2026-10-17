class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if(a[1] == b[1]) return a[0] > b[0]; // IMPORTANT
            return a[1] < b[1];
        });

        int prev1 = intervals[0][1] - 1;
        int prev2 = intervals[0][1];
        int count = 2;

        for(int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start > prev2) { // neither point is in the interval
                count += 2;
                prev1 = end - 1;
                prev2 = end;
            }
            else if(start > prev1) { // only prev2 is in the interval
                count += 1;
                prev1 = prev2;
                prev2 = end;
            }
        }

        return count;
    }
};