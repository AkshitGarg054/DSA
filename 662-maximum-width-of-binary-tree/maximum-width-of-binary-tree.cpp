class Solution {
public:
    // we need to count the gap between the leftmost and the rightmost node in each level.
    // so we need to assign each node the index it would have in a complete binary tree.
    // and that index is: if parent = i, then left_child = 2*i + 1, right_child = 2*i + 2
    // and gap = rightmost_index - leftmost_index + 1 

    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long ans = 0;

        queue<pair<TreeNode*, long long>> q; // {node, index}
        q.push({root, 0});

        while(!q.empty()) {
            int n = q.size();

            long long first_index = q.front().second; // to prevent overflow
            long long mini, maxi;

            for(int i = 0; i < n; i++) {
                auto [node, index] = q.front();
                q.pop();

                index -= first_index; // this start the index of a level from 0
                if(i == 0) mini = index;
                if(i == n - 1) maxi = index;

                if(node -> left) q.push({node -> left, 2*index + 1});
                if(node -> right) q.push({node -> right, 2*index + 2});
            }

            ans = max(ans, maxi - mini + 1);
        }

        return ans;
    }
};