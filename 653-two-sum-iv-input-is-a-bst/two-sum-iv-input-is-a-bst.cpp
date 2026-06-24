class Solution {
public:
    // This ques is the nicest application of BST Iterator.
    // The idea is exactly like two sum in a sorted array: smallest + largest.
    // Since inorder of BST is sorted, we create:
    // Forward iterator: gives next element from the left side
    // Backward iterator: gives prev element from the right side

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