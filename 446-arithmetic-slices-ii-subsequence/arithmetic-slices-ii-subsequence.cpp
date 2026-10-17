class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<unordered_map<long long, int>> mp(n); // one map for each index, where key = diff and value = freq

        for(int i=0; i < n; i++) {
            for(int j=0; j < i; j++) {
                long long diff = (long long)nums[i] - (long long)nums[j];

                if(mp[j].count(diff)) {
                    mp[i][diff] = mp[i][diff] + mp[j][diff] + 1;
                    result += mp[j][diff]; // length of atleast 3 is confirmed
                }
                else mp[i][diff] += 1;  
            }
        }

        return result;
    }
};