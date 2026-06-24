class Solution {
public:
    bool check(TreeNode* root, long long low, long long high) {
        if(root == NULL) return true;
        if(root -> val <= low || root -> val >= high) return false; // value should remain between low and high
        
        bool left = check(root -> left, low, root -> val);
        bool right = check(root -> right, root -> val, high);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};