class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                Node* curr = q.front();
                q.pop();

                if(i != sz - 1) curr -> next = q.front();
                else curr -> next = NULL;

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }

        return root;
    }
};