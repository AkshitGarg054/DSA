class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int left = height(root -> left);
        int right = height(root -> right);

        return max(left, right) + 1;
    }

    int findBottomLeftValue(TreeNode* root) {
        int levels = height(root); // we got the number of levels

        // now apply level order traversal and return the first node value of the last level.
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                if(level == levels) return curr -> val;
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }

            level++;
        }

        return -1;
    }
};