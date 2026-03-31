class Solution {
public:
    int solve(TreeNode* curr, unordered_map<int, int> &mp) {
        if(curr == NULL) return 0;
        int sum = curr -> val + solve(curr -> left, mp) + solve(curr -> right, mp); 
        mp[sum]++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);

        int maxi = 0;
        for(auto [key, val] : mp) maxi = max(maxi, val);

        vector<int> ans;
        for(auto [key, val] : mp) {
            if(val == maxi) ans.push_back(key);
        }

        return ans;
    }
};