class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp; // mp[child] = parent

    void findParent(TreeNode* root, TreeNode* parent) {
        if(root == NULL) return;

        mp[root] = parent;
        findParent(root -> left, root);
        findParent(root -> right, root);
    }

    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        if(left == 0 && right == 0 && root -> val == 0) {
            if(mp[root] -> left == root) mp[root] -> left = NULL;
            if(mp[root] -> right == root) mp[root] -> right = NULL;
        }

        if(root == NULL) return 0;
        return left + right + (root -> val);
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* temp = new TreeNode(-1);
        findParent(root, temp);

        solve(root);
        if(root -> val == 0 && root -> left == NULL && root -> right == NULL) return NULL;
        return root;
    }
};