class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void solve(int index, vector<int> &temp, vector<int> &nums) {
        if(index == n) {
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[index]);
        solve(index + 1, temp, nums);
        temp.pop_back();

        // not take
        solve(index + 1, temp, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(0, temp, nums);
        return ans;
    }
};