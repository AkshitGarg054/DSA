class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0}); // 1st building is always of height 0
        sort(restrictions.begin(), restrictions.end()); // sort by building index

        int m = restrictions.size();
    
        // forward pass
        for(int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }

        // backward pass
        for(int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }

        int ans = 0;

        // find max peak between consecutive restrictions
        for(int i = 1; i < m; i++) {
            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];
            int x1 = restrictions[i - 1][0];    
            int x2 = restrictions[i][0];

            int peak = max(h1, h2) + ((x2 - x1) - abs(h1 - h2)) / 2;
            ans = max(ans, peak); 
        }

        int lastPos = restrictions.back()[0];
        int lastHeight = restrictions.back()[1];
        int lastPeak = lastHeight + (n - lastPos);
        ans = max(ans, lastPeak);

        return ans;
    }
};