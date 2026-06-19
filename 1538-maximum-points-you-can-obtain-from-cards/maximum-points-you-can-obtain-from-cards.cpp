class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> prefix(k);
        prefix[0] = cardPoints[0];
        for(int i = 1; i < k; i++) prefix[i] = prefix[i - 1] + cardPoints[i];

        vector<int> suffix(k);
        suffix[k - 1] = cardPoints[n - 1];
        for(int i = k - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + cardPoints[n - k + i]; 

        int maxi = max(prefix[k - 1], suffix[0]);
        
        for(int i = 0; i < k - 1; i++) {
            int temp = prefix[i] + suffix[i + 1];
            maxi = max(maxi, temp);
        }

        return maxi;
    }
};