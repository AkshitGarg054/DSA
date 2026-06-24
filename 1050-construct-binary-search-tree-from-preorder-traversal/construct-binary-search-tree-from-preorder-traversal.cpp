class Solution {
public:
    TreeNode* build(vector<int> &preorder, int pre_start, int pre_end) {
        if(pre_start > pre_end) return NULL;

        int ele = preorder[pre_start];
        TreeNode* root = new TreeNode(ele);

        // preorder: R..... ...... (NLR)
        // example: [8, 5, 1, 7, 10, 12] where N = 8, L = [5, 1, 7], R = [10, 12]
        // we want the first element greater than ele
        int index = pre_start + 1;
        while(index <= pre_end && preorder[index] < root -> val) index++;

        root -> left = build(preorder, pre_start + 1, index - 1);
        root -> right = build(preorder, index, pre_end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        int pre_start = 0;
        int pre_end = preorder.size() - 1;

        return build(preorder, pre_start, pre_end);
    }
};