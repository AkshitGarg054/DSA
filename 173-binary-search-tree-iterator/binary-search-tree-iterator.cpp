class BSTIterator {
public:
    // very important question to understand the new concept of finding the inorder traversal using stack
    stack<TreeNode*> st;

    void storeLeft(TreeNode* root) {
        if(root == NULL) return;
        while(root != NULL) {
            st.push(root);
            root = root -> left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeft(root);
    }
    
    int next() {
        auto ans = st.top();
        st.pop();
        if(ans -> right != NULL) storeLeft(ans -> right);
        return ans -> val;
    }
    
    bool hasNext() {
        return st.size() > 0;
    }
};