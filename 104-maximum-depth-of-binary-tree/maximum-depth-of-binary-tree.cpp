class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        // depth wise iteration 
        queue<TreeNode*> st;
        int count = 0;
        st.push(root);
        int size = 0;
        while(!st.empty()){
            size = st.size();
            while(size--){
                auto it = st.front();
                st.pop();
                if (it->left != nullptr){
                    st.push(it->left);
                }
                if (it->right != nullptr){
                    st.push(it->right);
                }
            }
            count++;
        }


        return count;
    }
};