class Solution {
public:
    bool is_same(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        if(root -> val != subRoot -> val) return false;

        auto left = is_same(root -> left, subRoot -> left);
        auto right = is_same(root -> right, subRoot -> right);

        return left && right;
    }

    bool solve_node(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;

        if(is_same(root, subRoot)) return true;
        if(solve_node(root -> left, subRoot)) return true;
        if(solve_node(root -> right, subRoot)) return true;

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        
        return solve_node(root, subRoot);
    }
};