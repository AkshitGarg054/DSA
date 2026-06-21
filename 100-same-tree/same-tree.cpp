class Solution {
public:
    int solve(TreeNode *p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p -> val != q -> val) return false;

        bool left = solve(p -> left, q -> left);
        bool right = solve(p -> right, q -> right);

        if(left && right) return true;
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        return solve(p, q);
    }
};