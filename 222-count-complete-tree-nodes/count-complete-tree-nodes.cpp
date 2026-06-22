class Solution {
public:
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        return left + right + 1; 
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        return solve(root);
    }
};