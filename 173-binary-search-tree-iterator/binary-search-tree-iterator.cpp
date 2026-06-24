class BSTIterator {
public:
    // This approach uses O(n) space

    vector<int> vec;
    int ptr;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root -> left);
        vec.push_back(root -> val);
        inorder(root -> right);
    }

    BSTIterator(TreeNode* root) {
        inorder(root);
        ptr = -1;
    }
    
    int next() {
        ptr++;
        return vec[ptr];
    }
    
    bool hasNext() {
        return (ptr + 1 < vec.size()); 
    }
};