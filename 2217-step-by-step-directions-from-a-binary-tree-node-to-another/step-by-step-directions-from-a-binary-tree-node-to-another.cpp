class Solution {
public:
    TreeNode* find_LCA(TreeNode* root, int p, int q) {
        if(!root || root -> val == p || root -> val == q) return root;

        TreeNode* left = find_LCA(root -> left, p, q);
        TreeNode* right = find_LCA(root -> right, p, q);

        // if p is found on one side and q on other side, then this node is LCA
        if(left && right) return root; 

        return left ? left : right; // else, return the non-null side.
    }

    bool find(TreeNode* root, int target, string &path) {
        if(root == NULL) return false;
        if(root -> val == target) return true;

        path.push_back('L');
        if(find(root -> left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(find(root -> right, target, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = find_LCA(root, startValue, destValue);

        string start = "";
        string dest = "";

        find(lca, startValue, start);
        find(lca, destValue, dest);

        string up = string(start.size(), 'U');
        return up + dest;
    }
};