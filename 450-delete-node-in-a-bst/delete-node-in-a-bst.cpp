class Solution {
public:
    TreeNode* findLastRight(TreeNode* root) {
        while(root -> right != NULL) root = root -> right;
        return root;
    }

    TreeNode* helper(TreeNode* root) { // root node needs to be deleted
        if(root -> right == NULL) return root -> left;
        else if(root -> left == NULL) return root -> right;
        else { // both childs exist
            TreeNode* rightChild = root -> right;
            TreeNode* lastRight = findLastRight(root -> left);
            lastRight -> right = rightChild;
            return root -> left;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) return helper(root);

        TreeNode* dummy = root;

        while(root != NULL) {
            if(root -> val > key) {
                if(root -> left && root -> left -> val == key) {
                    root -> left = helper(root -> left); // pass the node that we want to delete
                    break;
                }
                else root = root -> left;
            }
            else {
                if(root -> right && root -> right -> val == key) {
                    root -> right = helper(root -> right);
                    break;
                }
                else root = root -> right;
            }
        }

        return dummy;
    }
};