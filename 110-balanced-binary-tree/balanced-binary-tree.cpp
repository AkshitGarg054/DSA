class Solution {
public:
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = 1 + solve(root -> left);
        int right = 1 + solve(root -> right);

        if(abs(left - right) <= 1) return max(left, right); // return the height upwards towards the root
        return 1e9; // return this poison value upwards
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int height = solve(root);
        if(height >= 1e9) return false;
        return true;
    }
};