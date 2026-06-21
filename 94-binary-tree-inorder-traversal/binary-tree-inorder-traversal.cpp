class Solution {
public:
    // iterative traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> vis;
        st.push(root);

        while(!st.empty()) {
            TreeNode* curr = st.top();

            if(curr -> left && !vis[curr -> left]) st.push(curr -> left);
            else {
                ans.push_back(curr -> val);
                vis[curr] = true;
                st.pop();
                if(curr -> right && !vis[curr -> right]) st.push(curr -> right);
            }
        }

        return ans;
    }
};