class Solution {
public:
    // Tree Serialization + Hashing Pattern

    string solve(TreeNode* curr, unordered_map<string, int> &mp, vector<TreeNode*> &ans) {
        if(curr == NULL) return "N";

        string serial = to_string(curr -> val) + "," + solve(curr -> left, mp, ans) + "," + solve(curr -> right, mp, ans);
        if(mp[serial] == 1) ans.push_back(curr);
        mp[serial]++;

        return serial;  
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        if(root == NULL) return ans;
        
        unordered_map<string, int> mp;
        solve(root, mp, ans);
        return ans;
    }
};