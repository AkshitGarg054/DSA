class Solution {
public:
    bool is_same(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        if(a -> val != b -> val) return false;

        return is_same(a -> left, b -> left) && is_same(a -> right, b -> right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        if(is_same(root, subRoot) == true) return true;

        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};