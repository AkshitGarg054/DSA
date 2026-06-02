class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int arrows = 0;

        int curr_l = points[0][0], curr_r = points[0][1];

        for(int i = 1; i < n; i++) {
            curr_l = max(curr_l, points[i][0]);
            curr_r = min(curr_r, points[i][1]);

            if(curr_l > curr_r) { // there is no intersection between the current range and the next balloon.
                // we need to use this arrow for the current range, and take a new arrow for the remaining balloons.
                arrows++;
                curr_l = points[i][0];
                curr_r = points[i][1];
            }
        }

        return arrows + 1; // +1 for the last range
    }
};