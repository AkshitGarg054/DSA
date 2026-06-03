class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landDuration.size();
        int m = waterDuration.size();

        // calculating the minimum time for a land or water ride individually
        int mini_land = INT_MAX;
        int mini_water = INT_MAX;

        for(int i = 0; i < n; i++) {
            int land = landStartTime[i] + landDuration[i];
            mini_land = min(mini_land, land);
        }

        for(int i = 0; i < m; i++) {
            int water = waterStartTime[i] + waterDuration[i];
            mini_water = min(mini_water, water);
        }

        int ans = INT_MAX;

        // Assuming we took the land ride first then we are taking the water ride.
        vector<pair<int, int>> water(m);
        for(int i = 0; i < m; i++) water[i] = {waterDuration[i], waterStartTime[i]};
        sort(water.begin(), water.end());

        for(int i = 0; i < m; i++) {
            int wait = water[i].second - mini_land;
            if(wait <= 0) ans = min(ans, mini_land + water[i].first);
            else ans = min(ans, mini_land + wait + water[i].first);
        }

        // Assuming we took the water ride first then we are taking the land ride.
        vector<pair<int, int>> land(n);
        for(int i = 0; i < n; i++) land[i] = {landDuration[i], landStartTime[i]};
        sort(land.begin(), land.end());

        for(int i = 0; i < n; i++) {
            int wait = land[i].second - mini_water;
            if(wait <= 0) ans = min(ans, mini_water + land[i].first);
            else ans = min(ans, mini_water + wait + land[i].first);
        }

        return ans;
    }
};