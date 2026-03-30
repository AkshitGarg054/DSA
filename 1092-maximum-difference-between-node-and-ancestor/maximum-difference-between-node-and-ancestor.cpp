class Solution {
public:
    // looks like DFS.
    // whenever answer depends on values above or below the node, we can think of DFS.
    // The pattern is :
    // either pass useful information in DFS, 
    // or return useful information from DFS.
    int ans = 0;

    void dfs(TreeNode* curr, int mini, int maxi) {
        if(curr == NULL) return;

        // calculate updated ans (absolute diff of mini and maxi with curr val)
        ans = max(ans, max(abs(curr -> val - mini), abs(curr -> val - maxi)));

        // calculate mini and maxi including curr node for passing to next recursive call
        mini = min(mini, curr -> val);
        maxi = max(maxi, curr -> val);

        dfs(curr -> left, mini, maxi);
        dfs(curr -> right, mini, maxi);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root -> val, root -> val); // mini, maxi
        return ans;
    }
};