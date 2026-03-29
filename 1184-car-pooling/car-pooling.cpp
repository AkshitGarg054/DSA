class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for(auto trip : trips) {
            int p = trip[0], from = trip[1], to = trip[2];
            diff[from] += p;
            diff[to] -= p;
        }

        int sum = 0;
        for(int i = 0; i < diff.size(); i++) {
            sum += diff[i];
            if(sum > capacity) return false;
        }

        return true;
    }
};