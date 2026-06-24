class Solution {
public:
    unordered_set<int> leaves;
    unordered_map<int, TreeNode*> mp; // (mp[root -> val] = Tree) for quick lookups

    bool merge_and_validate(TreeNode* root, long long mini, long long maxi) {
        if(root == NULL) return true;
        if(root -> val <= mini || root -> val >= maxi) return false; // standard

        if(root -> left == NULL && root -> right == NULL) {
            if(mp.count(root -> val)) {
                TreeNode* newTree = mp[root -> val];
                mp.erase(root -> val);

                root -> left = newTree -> left; 
                root -> right = newTree -> right;
            }
        }

        auto left = merge_and_validate(root -> left, mini, root -> val);
        auto right = merge_and_validate(root -> right, root -> val, maxi);

        return left && right;
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();

        for(auto root: trees) {
            mp[root -> val] = root;
            if(root -> left) leaves.insert(root -> left -> val);
            if(root -> right) leaves.insert(root -> right -> val);
        }

        // step1: get the root of the final BST
        TreeNode* root = NULL;
        int count = 0;

        for(auto it: trees) {
            if(!leaves.count(it -> val)) {
                root = it;
                count = 1;
            }
        }
        
        if(count != 1) return NULL; // merging is not possible
        mp.erase(root -> val); // remove the final root from the map

        // recursively merge and validate the BST
        if(merge_and_validate(root, LLONG_MIN, LLONG_MAX) && mp.empty()) return root;
        return NULL; // else
    }
};