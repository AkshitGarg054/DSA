class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        vector<int> h_diff;
        h_diff.push_back(horizontalCuts[0] - 0);
        for(int i = 1; i < n; i++) h_diff.push_back(horizontalCuts[i] - horizontalCuts[i-1]);
        h_diff.push_back(h - horizontalCuts[n-1]);

        vector<int> v_diff;
        v_diff.push_back(verticalCuts[0] - 0);
        for(int i = 1; i < m; i++) v_diff.push_back(verticalCuts[i] - verticalCuts[i-1]);
        v_diff.push_back(w - verticalCuts[m-1]);

        int height = *max_element(h_diff.begin(), h_diff.end());
        int width = *max_element(v_diff.begin(), v_diff.end());

        return (1LL * height * width) % MOD;
    }
};