class Solution {
public:
    // instead of thinking where should each coin go,
    // think: how many coins pass through the edge connecting a subtree to its parent.
    // say, subtree has 5 nodes but 2 coins, so it need 3 coins through that edge.
    // similarly, if subtree has 5 nodes and 8 coins, then it will send back 3 coins through that edge
    // so, for each subtree, we just need to count the number of nodes and the sum of node values.
    // add their absolute difference to the final answer.
    int moves = 0;

    pair<int, int> solve(TreeNode*root) {
        if(root == NULL) return {0, 0};

        auto left = solve(root -> left);
        auto right = solve(root -> right);

        int count = 1 + left.first + right.first;
        int sum = (root -> val) + left.second + right.second;

        moves += abs(left.first - left.second) + abs(right.first - right.second);

        return {count, sum};
    }

    int distributeCoins(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return moves;
    }
};