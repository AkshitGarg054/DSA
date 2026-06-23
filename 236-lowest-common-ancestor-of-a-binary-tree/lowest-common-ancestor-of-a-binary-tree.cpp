class Solution {
public:
    // approach 2: Find the path from root node to p, and root node to q
    // and then going till the prefix matches, to find the LCA

    bool find_path(TreeNode* root, TreeNode* target, vector<TreeNode*> &path) {
        if(root == NULL) return false;

        path.push_back(root);
        if(root == target) return true;
        
        bool left = find_path(root -> left, target, path);
        bool right = find_path(root -> right, target, path);

        if(left || right) return true; // if we get true from either left or right, then we are done, so we returned here so that dubara pop_back() na ho

        path.pop_back(); // backtrack 
        return false; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        vector<TreeNode*> path_p, path_q;

        find_path(root, p, path_p);
        find_path(root, q, path_q);

        TreeNode* ans = NULL;
        int n = min(path_p.size(), path_q.size());

        for(int i = 0; i < n; i++) {
            if(path_p[i] == path_q[i]) ans = path_p[i];
            else break;
        }
        
        return ans;
    }
};