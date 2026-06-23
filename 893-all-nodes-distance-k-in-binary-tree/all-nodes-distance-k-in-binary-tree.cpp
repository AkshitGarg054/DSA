class Solution {
public:
    // here, we also need to move upwards towards parent
    // so, we will store parent for every node in a map
    // and then simply apply BFS from the target node and stop after exactly k levels.
    // because, after k levels, all nodes in the queue are the answer.
    // NOTE: with left, right and parent, for each node, we are treating this tree as an undirected graph, so we also need to keep a visited list.
    // So, we can say whenever we also visit parent in a tree, then it becomes a undirected graph. (Nice concept)

    unordered_map<TreeNode*, TreeNode*> parent; // to store parent of each child node

    void findParents(TreeNode* root) {
        if(root == NULL) return;

        if(root -> left) {
            parent[root -> left] = root;
            findParents(root -> left);
        }
        
        if(root -> right) {
            parent[root -> right] = root;
            findParents(root -> right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;

        q.push(target);
        vis[target] = true;

        int level = 0;

        while(!q.empty()) {
            int n = q.size();   
            if(level == k) break;
            level++;

            for(int i = 0; i < n; i++) {
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

                if(parent.count(curr) && !vis[parent[curr]]) {
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
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