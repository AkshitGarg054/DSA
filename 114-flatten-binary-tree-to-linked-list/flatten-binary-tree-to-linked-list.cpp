class Solution {
public:
    // For every node:
    // 1. Flatten left subtree.
    // 2. Flatten right subtree.
    // 3. Attach flattened left subtree between root and right subtree.

    TreeNode* flattenTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode* rightSubtree = flattenTree(root -> right); // save the right subtree
        root -> right = flattenTree(root -> left);
        root -> left = NULL;

        TreeNode* head = root -> right;

        if(head != NULL) {
            TreeNode* temp = head;
            while(temp -> right != NULL) temp = temp -> right; // find the last node of flattened left subtree
            temp -> right = rightSubtree;
        }
        else root -> right = rightSubtree;
        
        return root;
    }

    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};