class Solution {
public:
    vector<vector<int>> ans;
    // use ordered map because we want columns in sorted order
    map<int, vector<pair<int, int>>> mp; // col --> {(row, val)}

    void solve(TreeNode* root, int row, int col) {
        if(root == NULL) return;

        mp[col].push_back({row, root -> val}); 

        solve(root -> left, row + 1, col - 1);
        solve(root -> right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return ans;

        solve(root, 0, 0);

        for(auto &[col, vec]: mp) {
            sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
                if(a.first == b.first) return a.second < b.second;
                return a.first < b.first; // sort by row in ascending
            });

            vector<int> curr;
            for(auto &[row, val] : vec) curr.push_back(val);
            ans.push_back(curr);
        }

        return ans;
    }
};