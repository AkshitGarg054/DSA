class Solution {
public:
    // Preorder: root, left, right
    // Inorder: Left, root, right
    unordered_map<int, int> mp; // value -> index

    TreeNode* build(int pre_start, int pre_end, int in_start, int in_end, vector<int> &preorder, vector<int> &inorder) {
        if(pre_start > pre_end) return NULL;

        int value = preorder[pre_start];
        int index = mp[value]; // find the index of 'value' in inorder array
        int leftSize = index - in_start;

        TreeNode* root = new TreeNode(value); 
        root -> left = build(pre_start + 1, pre_start + leftSize, in_start, index - 1, preorder, inorder);
        root -> right = build(pre_start + leftSize + 1, pre_end, index + 1, in_end, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int pre_start = 0, pre_end = n - 1;
        int in_start = 0, in_end = n - 1;

        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        return build(pre_start, pre_end, in_start, in_end, preorder, inorder);
    }
};