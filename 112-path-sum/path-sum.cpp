class Solution {
public:
    // at every node, subtract the current node value from targetSum, then check left and right subtree
    // if you reach a leaf node, and remaining target becomes exactly that leaf value, then return true

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        if(root -> left == NULL && root -> right == NULL) {
            return root -> val == targetSum;
        }

        return hasPathSum(root -> left, targetSum - root -> val) || hasPathSum(root -> right, targetSum - root -> val);
    }
};