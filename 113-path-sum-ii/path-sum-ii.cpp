class Solution {
public:
    // When we get back from recursion, the changes in the variables/vectors etc are undone as we roll back because the call stack is cleared. Because in every stack a new copy of variables are created (if you haven’t passed them from reference & operator)
// SO, if you pass your variables with reference, then no new copy of that is made of recursive call. The same variable goes through all calls. In that case, you will have to explicitly remove element. 
// I would suggest you to pass tmp by reference and see what happens . You will understand for sure

    vector<vector<int>> ans;

    void solve(int sum, TreeNode* root, vector<int> temp, int target) {
        if(root == NULL) return;

        sum += root -> val;
        temp.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL) {
            if(sum == target) ans.push_back(temp);
            return;
        }

        solve(sum, root -> left, temp, target);
        solve(sum, root -> right, temp, target);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(0, root, temp, targetSum);
        return ans;
    }
};