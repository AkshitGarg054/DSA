class Solution {
public:
    bool solve(TreeNode* root, long long low, long long high) {
        if(root == NULL) return true;
        if(root -> val <= low || root -> val >= high) return false; // every node's value must lie between low and high

        bool left = solve(root -> left, low, root -> val);
        bool right = solve(root -> right, root -> val, high);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};