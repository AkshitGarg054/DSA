class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for(auto trip: trips) {
            int count = trip[0];
            int from = trip[1], to = trip[2];

            diff[from] += count;
            diff[to] -= count;
        }

        if(diff[0] > capacity) return false;
        
        for(int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
            if(diff[i] > capacity) return false;
        }

        return true;
    }
};