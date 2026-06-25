class Solution {
public:
    int count = 0;

    void solve(TreeNode* root, int maxi) {
        if(root == NULL) return;

        if(root -> val >= maxi) {
            maxi = root -> val;
            count++;
        }

        solve(root -> left, maxi);
        solve(root -> right, maxi); // backtracking is internally handled by recursion here (try visualizing)
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;

        solve(root, INT_MIN);
        return count;
    }
};