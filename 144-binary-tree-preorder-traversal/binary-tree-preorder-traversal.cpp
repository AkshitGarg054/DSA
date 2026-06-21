class Solution {
public:
    vector<int> ans;

    void solve(TreeNode* root) {
        if(root == NULL) return;

        ans.push_back(root -> val);
        solve(root -> left);
        solve(root -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};