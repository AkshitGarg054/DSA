class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        int maxi = 0;
        int index = -1;

        sort(nums.begin(), nums.end());

        for(int i=0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }

            if(dp[i] > maxi) {
                maxi = dp[i];
                index = i;
            }
        }

        vector<int> temp;

        while(true) {
            temp.push_back(nums[index]);
            if(parent[index] == index) break;
            index = parent[index];
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};