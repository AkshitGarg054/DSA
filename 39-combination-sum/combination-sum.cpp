class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void solve(int index, vector<int> &nums, int target, vector<int> &temp) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < n; i++) {
            temp.push_back(nums[i]);
            solve(i, nums, target - nums[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};