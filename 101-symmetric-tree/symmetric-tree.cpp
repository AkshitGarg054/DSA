class Solution {
public:
    // level order traversal
    vector<vector<TreeNode*>> solve(TreeNode* root) {
        vector<vector<TreeNode*>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> inner;

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                inner.push_back(curr);
                if(curr != NULL) {
                    if(curr -> left) q.push(curr -> left);
                    else q.push(NULL);
                    if(curr -> right) q.push(curr -> right);
                    else q.push(NULL);
                }    
            }

            ans.push_back(inner);
        }

        return ans;
    }

    bool isSymmetric(TreeNode* root) {
        vector<vector<TreeNode*>> left = solve(root -> left);
        vector<vector<TreeNode*>> right = solve(root -> right);
        if(left.size() != right.size()) return false;

        for(int i = 1; i < left.size(); i++) {
            reverse(left[i].begin(), left[i].end());
        }

        for(int i = 0; i < left.size(); i++) {
            if(left[i].size() != right[i].size()) return false;
            
            for(int j = 0; j < left[i].size(); j++) {
                if(left[i][j] == NULL && right[i][j] == NULL) continue;
                else if(left[i][j] == NULL || right[i][j] == NULL) return false;
                else if(left[i][j] -> val != right[i][j] -> val) return false;
            }
        }

        return true;
    }
};