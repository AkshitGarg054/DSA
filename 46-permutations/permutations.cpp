class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> vis;

    void solve(int i, vector<int> &temp, vector<int> &nums) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!vis.count(nums[i])) {
                temp.push_back(nums[i]);
                vis.insert(nums[i]);

                solve(i + 1, temp, nums);

                temp.pop_back(); // backtrack
                vis.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        solve(0, temp, nums);
        return ans;
    }
};