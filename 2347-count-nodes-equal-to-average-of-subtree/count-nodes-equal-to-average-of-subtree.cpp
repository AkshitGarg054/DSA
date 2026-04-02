class Solution {
public:
    // bottom up DFS / postorder traversal
    // for every node, get sum and count from left subtree
    // get sum and count from right subtree

    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) return {0, 0};

        auto left = dfs(root -> left);
        auto right = dfs(root -> right);

        int sum = left.first + right.first + root -> val;
        int count = left.second + right.second + 1;

        if(sum / count == root -> val) ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};