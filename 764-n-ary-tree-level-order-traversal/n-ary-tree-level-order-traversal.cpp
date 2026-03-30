/*
class Node {
public:
    int val;
    vector<Node*> children;
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans; // output : [[1], [2, 3], [4, 5, 6, 7]]
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> inner;

            while(sz--) {
                Node* curr = q.front();
                q.pop();

                inner.push_back(curr -> val);
                for(Node* child : curr -> children) q.push(child); 
            }

            ans.push_back(inner);
        }

        return ans;
    }
};