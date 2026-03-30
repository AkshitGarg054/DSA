class Solution {
public:
    void preorder(TreeNode* curr, vector<int> &ans) {
        if(curr == NULL) return;

        ans.push_back(curr -> val);
        preorder(curr -> left, ans);
        preorder(curr -> right, ans);        
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        preorder(root, ans);
        return ans;
    }
};