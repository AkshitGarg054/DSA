class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;
        Node* temp = head;

        // traverse on original list and create a copied node for each original node
        // and store the mapping of original node to the copied node
        while(temp != NULL) {
            mp[temp] = new Node(temp -> val);
            temp = temp -> next; 
        }

        // now, assign pointers to the copied nodes by traversing again on the original list
        temp = head;
        while(temp != NULL) {
            mp[temp] -> next = mp[temp -> next];
            mp[temp] -> random = mp[temp -> random]; 
            temp = temp -> next;
        }

        return mp[head];
    }
};