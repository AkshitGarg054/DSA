/*
class Node {
public:
    int val;
    vector<Node*> children;
};
*/

class Solution {
public:
    void preorder(Node* curr, vector<int> &ans) {
        if(curr == NULL) return;

        ans.push_back(curr -> val);
        for(Node* child : curr -> children) preorder(child, ans);
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        preorder(root, ans);
        return ans;
    }
};