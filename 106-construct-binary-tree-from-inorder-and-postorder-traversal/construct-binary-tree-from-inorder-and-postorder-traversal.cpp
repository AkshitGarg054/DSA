class Solution {
public:
    unordered_map<int, int> mp; // to start the index of every element of inorder

    TreeNode* build(int post_start, int post_end, int in_start, int in_end, vector<int>& postorder, vector<int>& inorder) {
        if(post_start > post_end) return NULL;

        int ele = postorder[post_end];
        int index = mp[ele];
        int left_size = index - in_start;

        TreeNode* root = new TreeNode(ele);

        // inorder:   ......R......
        // postorder: ............R (Left, right, root) 
        root -> left = build(post_start, post_start + left_size - 1, in_start, index - 1, postorder, inorder);
        root -> right = build(post_start + left_size, post_end - 1, index + 1, in_end, postorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_start = 0;
        int post_end = postorder.size() - 1;
        int in_start = 0;
        int in_end = inorder.size() - 1;
         
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        
        return build(post_start, post_end, in_start, in_end, postorder, inorder);
    }
};