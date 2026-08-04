class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        for(int i = 0; i < n; i++) {
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i + 1 != nums[i] && i + 1 > mini) ans.push_back(i + 1);
        }

        for(int i = n + 1; i <= maxi; i++) {
            if(!st.count(i) && i > mini) ans.push_back(i);
        }
        return ans;
    }
};