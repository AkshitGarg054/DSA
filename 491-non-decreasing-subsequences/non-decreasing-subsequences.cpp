class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, vector<int> &temp, vector<int> &nums) {
        if(temp.size() >= 2) ans.push_back(temp);

        unordered_set<int> vis;

        for(int i = index; i < nums.size(); i++) { // subsequences are built in order, that's why started from i = index
            if(vis.count(nums[i])) continue;

            if(temp.empty() || temp.back() <= nums[i]) {
                vis.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(i + 1, temp, nums);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0, temp, nums);
        return ans;
    }
};