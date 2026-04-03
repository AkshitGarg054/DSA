class Solution {
public:
    int n;
    vector<vector<int>> ans;
    unordered_set<int> st;

    void solve(vector<int> &temp, vector<int> &nums) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!st.count(nums[i])) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp, nums);
                
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(temp, nums);
        return ans;
    }
};