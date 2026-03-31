class Solution {
public:
    // Mirror DFS or Paired DFS
    bool isMirror(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        if(a -> val != b -> val) return false;

        return isMirror(a -> left, b -> right) && isMirror(a -> right, b -> left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root -> left, root -> right);
    }
};