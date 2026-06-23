class Solution {
public:
    vector<vector<int>> ans;
    int sum = 0;

    void solve(TreeNode* root, int target, vector<int> &path) {
        if(root == NULL) return;

        sum += root -> val;
        path.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL) {
            if(sum == target) ans.push_back(path);
        } 

        solve(root -> left, target, path);
        solve(root -> right, target, path);
        
        sum -= root -> val; // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return ans;

        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};