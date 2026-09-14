class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;

    void findParent(TreeNode* node, TreeNode* parent) {
        if(node == NULL) return;

        mp[node] = parent;
        findParent(node -> left, node);
        findParent(node -> right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) return {};

        TreeNode* temp = new TreeNode(-1);
        findParent(root, temp);

        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;

        int levels = 0;

        while(!q.empty()) {
            int sz = q.size();
            if(levels == k) break;
            levels++;

            while(sz--) {
                auto curr = q.front();
                q.pop();

                if(curr -> left && !vis[curr -> left]) {
                    q.push(curr -> left);
                    vis[curr -> left] = true;
                }

                if(curr -> right && !vis[curr -> right]) {
                    q.push(curr -> right);
                    vis[curr -> right] = true;
                }

                if(mp.count(curr) && !vis[mp[curr]] && mp[curr] -> val != -1) {
                    q.push(mp[curr]);
                    vis[mp[curr]] = true;
                }
            }
        }

        vector<int> ans;
        
        while(!q.empty()) {
            ans.push_back(q.front() -> val);
            q.pop();
        }

        return ans;
    }
};