class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        vector<int> dp(cols, 1);

        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < i; j++) {
                bool valid = true; // check if col j and col i can be kept together

                for(int r = 0; r < rows; r++) {
                    if(strs[r][j] > strs[r][i]) {
                        valid = false;
                        break;
                    }
                }

                if(valid) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int maxi = *max_element(dp.begin(), dp.end());
        return cols - maxi;
    }
};