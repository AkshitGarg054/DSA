class Solution {
public:
    unordered_map<int, int> mp; // to start the index of every element of inorder

    TreeNode* build(int pre_start, int pre_end, int in_start, int in_end, vector<int>& preorder, vector<int>& inorder) {
        if(pre_start > pre_end) return NULL;

        int ele = preorder[pre_start];
        int index = mp[ele];
        int left_size = index - in_start;

        TreeNode* root = new TreeNode(ele);

        // inorder:  ......R......
        // preorder: R............
        root -> left = build(pre_start + 1, pre_start + left_size, in_start, index - 1, preorder, inorder);
        root -> right = build(pre_start + 1 + left_size, pre_end, index + 1, in_end, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_start = 0;
        int pre_end = preorder.size() - 1;
        int in_start = 0;
        int in_end = inorder.size() - 1;
         
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        
        return build(pre_start, pre_end, in_start, in_end, preorder, inorder);
    }
};