class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, int sum, vector<int> &temp, vector<int> &candidates, int target) {
        if(index == candidates.size()) {
            if(sum == target) ans.push_back(temp);
            return;
        }

        // take
        if(sum + candidates[index] <= target) {
            temp.push_back(candidates[index]);
            solve(index, sum + candidates[index], temp, candidates, target);
            temp.pop_back(); // backtrack
        }

        // skip 
        solve(index + 1, sum, temp, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<int> temp;
        solve(0, 0, temp, candidates, target);
        return ans;
    }
};