class Solution {
public:
    // The value of LCA of p and q will be between the values of p and q.
    // that is, if p -> val = mini and q -> val = maxi
    // then value of LCA will lie between [mini, maxi]

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        int mini = min(p -> val, q -> val);
        int maxi = max(p -> val, q -> val);

        while(root != NULL) {
            if(root -> val < mini) root = root -> right;
            else if(root -> val > maxi) root = root -> left;
            else break; // find the first value between [mini, maxi]
        }

        return root;
    }
};