class Solution {
public:
    int sum = 0;

    bool solve(TreeNode* root, int target) {
        if(root == NULL) return false;

        sum += root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            if(sum == target) return true;
        } 

        bool left = solve(root -> left, target);
        bool right = solve(root -> right, target);
        if(left || right) return true;

        sum -= root -> val; // backtrack
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        return solve(root, targetSum);
    }
};