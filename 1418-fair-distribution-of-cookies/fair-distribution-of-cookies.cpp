class Solution {
public:
    // we can assign any bag to any child
    // This is a question of backtracking / recusion on buckets
    // try giving each bag to every child
    int ans = INT_MAX;

    void solve(int index, vector<int> &child, vector<int> &cookies) {
        if(index == cookies.size()) {
            int unfairness = *max_element(child.begin(), child.end());
            ans = min(ans, unfairness);
            return;
        }

        for(int i = 0; i < child.size(); i++) {
            child[i] += cookies[index];
            solve(index + 1, child, cookies);
            child[i] -= cookies[index]; // backtrack
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        solve(0, child, cookies);
        return ans;
    }
};