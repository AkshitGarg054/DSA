class Solution {
public:
    vector<vector<int>> ans;

    void solve(int sum, TreeNode* root, vector<int> &temp, int target) {
        if(root == NULL) return;

        sum += root -> val;
        temp.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL) {
            if(sum == target) ans.push_back(temp);
            temp.pop_back(); // backtrack before returning
            return;
        }

        solve(sum, root -> left, temp, target);
        solve(sum, root -> right, temp, target);

        temp.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(0, root, temp, targetSum);
        return ans;
    }
};