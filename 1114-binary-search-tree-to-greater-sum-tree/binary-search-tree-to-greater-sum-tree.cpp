class Solution {
public:
    // inorder traversal gives nodes in ascending order.
    // we can get the inorder array and then add its suffixSum value to every node
    // and then reconstruct the tree from the new inorder.
    // but, instead of doing this, we can directly run a REVERSE INORDER.

    int sum = 0;

    void reverse_inorder(TreeNode* root) {
        if(root == NULL) return;

        reverse_inorder(root -> right);
        sum += root -> val;
        root -> val = sum;
        reverse_inorder(root -> left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;

        reverse_inorder(root);
        return root;
    }
};