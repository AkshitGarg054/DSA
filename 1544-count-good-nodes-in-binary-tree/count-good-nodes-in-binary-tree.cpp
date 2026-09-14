class Solution {
public:
    int count = 0;

    // as maxi is passed by value, so each recursion call will get its own copy of maxi. So, maximum from left subtree won't interfere in the right tree.
    void solve(TreeNode* root, int maxi) {
        if(root == NULL) return;

        if(root -> val >= maxi) {
            maxi = root -> val;
            count++;
        }

        solve(root -> left, maxi);
        solve(root -> right, maxi);
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;

        solve(root, -1e9);
        return count;
    }
};