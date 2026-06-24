class Solution {
public:
    void storeLeft(TreeNode* root, stack<TreeNode*> &st) {
        if(root == NULL) return;
        while(root != NULL) {
            st.push(root);
            root = root -> left;
        }
    }

    void storeRight(TreeNode* root, stack<TreeNode*> &st) {
        if(root == NULL) return;
        while(root != NULL) {
            st.push(root);
            root = root -> right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> leftStack;
        stack<TreeNode*> rightStack;

        storeLeft(root, leftStack);
        storeRight(root, rightStack);

        int left = leftStack.top() -> val;
        int right = rightStack.top() -> val;

        while(left < right) {
            int sum = left + right;

            if(sum == k) return true;
            else if(sum < k) { // select the next left
                TreeNode* curr = leftStack.top();
                leftStack.pop();
                storeLeft(curr -> right, leftStack);
                left = leftStack.top() -> val;
            }
            else { // select the previous of right
                TreeNode* curr = rightStack.top();
                rightStack.pop();
                storeRight(curr -> left, rightStack);
                right = rightStack.top() -> val;
            }
        }

        return false;
    }
};