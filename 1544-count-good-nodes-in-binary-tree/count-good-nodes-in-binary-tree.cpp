class Solution {
public:
    int count = 0;

    void solve(TreeNode* curr, int maxi, int &ans) {
        if(curr == NULL) return;

        if(curr -> val >= maxi) {
            maxi = curr -> val;
            ans++;
        }

        solve(curr -> left, maxi, ans);
        solve(curr -> right, maxi, ans);
    } 

    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxi = INT_MIN;
        solve(root, maxi, ans);
        return ans;
    }
};