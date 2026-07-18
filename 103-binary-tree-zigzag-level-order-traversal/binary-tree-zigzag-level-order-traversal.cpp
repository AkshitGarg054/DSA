class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        if(root -> left == NULL && root -> right == NULL) {
            ans.push_back({root -> val});
            return ans;
        };

        queue<TreeNode*> q;
        q.push(root);
        bool left = true; 

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;  

            while(sz--) {
                auto curr = q.front();
                q.pop();

                temp.push_back(curr -> val);
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }

            if(left) ans.push_back(temp);
            else {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }

            left = !left;
        }

        return ans;
    }
};