class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, vector<int> &temp, vector<int> &nums) {
        if(index == nums.size()) {
            if(temp.size() >= 2) ans.push_back(temp);
            return;
        }

        if(temp.empty() || temp.back() <= nums[index]) {
            temp.push_back(nums[index]);
            solve(index + 1, temp, nums);
            temp.pop_back();
        }

        if(temp.empty() || temp.back() != nums[index]) { // to avoid duplicate subsequences
            solve(index + 1, temp, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0, temp, nums);
        return ans;
    }
};