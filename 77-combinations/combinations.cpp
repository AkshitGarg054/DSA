class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, int n, vector<int> &temp, int k) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // as order matters, so we will start the loop from 'start'
        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i + 1, n, temp, k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, temp, k);
        return ans;
    }
};