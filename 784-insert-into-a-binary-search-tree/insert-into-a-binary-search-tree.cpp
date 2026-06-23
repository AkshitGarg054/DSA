class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* ans = new TreeNode(val);
            return ans;
        }

        TreeNode* temp = root;
        TreeNode* desired;

        while(temp != NULL) {
            if(temp -> val > val) {
                desired = temp;
                temp = temp -> left;
            }
            else {
                desired = temp;
                temp = temp -> right;
            }
        }

        if(desired -> val > val) desired -> left = new TreeNode(val);
        else desired -> right = new TreeNode(val);

        return root;
    }
};