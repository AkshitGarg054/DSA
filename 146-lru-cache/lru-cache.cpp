// To access the Least recently used value in O(1) time, I am using doubly linkedlist where the latest used/accessed value is put at start of the linkedlist. This way, the least recently used is always at the end of list.

class Node {
public:
    int k, v;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        this -> k = k;
        this -> v = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int sz;

    Node* head = new Node(-1, -1); // to access the head while adding new nodes at start.
    Node* tail = new Node(-1, -1); // to access the tail while adding new nodes at end.
    
    // The actual list will be between the head and tail pointers, that is:
    // HEAD <-- ......actual list...... -> TAIL.

    LRUCache(int capacity) {
        sz = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    // as the actual list is in between, so we need to delete the node from in between.
    void deleteNode(Node* node) {
        Node* p = node -> prev;
        Node* n = node -> next;
        p -> next = n;
        n -> prev = p;
        // delete(node); // we are not deleting the node, we are just removing it from the linkedlist.
    }

    void insertAtHead(Node* node) {
        Node* n = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = n;
        n -> prev = node;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        int ans = mp[key] -> v;
        deleteNode(mp[key]); // delete from back and insert at front.
        insertAtHead(mp[key]);
        return ans;
    }
    
    void put(int key, int value) {
        // if key already exists, then just update it and put in front.
        if(mp.count(key)) {
            mp[key] -> v = value;
            deleteNode(mp[key]);
            insertAtHead(mp[key]);
            return;
        }

        // if node with the given key does not exists.
        if(mp.size() >= sz) {
            // delete the lru node, change its (k, v) to the required (k, v) and then insert it at front.
            Node* target = tail -> prev;
            deleteNode(target);
            mp.erase(target -> k);  // delete the old key from the map.

            target -> k = key; // update the node with new key value pair
            target -> v = value;

            insertAtHead(target); // insert at head
            mp[key] = target;
            return;
        }

        // if the node with the given key does not exist, but we have enough size to insert it.
        // then just create a new node and insert at head.
        Node* newNode = new Node(key, value);
        insertAtHead(newNode);
        mp[key] = newNode;
        return; 
    }
};
