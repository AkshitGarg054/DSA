class Solution {
public:
    // we can find the inorder traversal and then iterate on the array and compare the current element with its prev and find the incorrect pairs.
    // we can get atmost 2 incorrect pairs.
    // if we get 1 incorrect, say (p1, q1) --> then swap: (q1, p1)
    // if we get 2 incorrect, say (p1, q1), (p2, q2) --> then swap first and last: (q2, q1), (p2, p1)
    // But, instead of explicitly finding the inorder, we can do this during recursion too.
    // as we need to compare with prev, so we need to keep track of prev node in inorder traversal.
    // NOTE: we only need to update the prev for (root -> right) because sirf (root -> right) ka hi (root) prev hoga, (root -> left) ka nhii. ...because root->val is smaller than root->right->val only, not root->left->val.

    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* last = NULL;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root -> left);
        if(prev != NULL && prev -> val > root -> val) { // invalid pair
            if(first == NULL) first = prev; 
            last = root;
        }

        prev = root;
        inorder(root -> right);
    }

    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        inorder(root);
        
        // now swap the first and last node
        int temp = first -> val;
        first -> val = last -> val;
        last -> val = temp;
    }
};