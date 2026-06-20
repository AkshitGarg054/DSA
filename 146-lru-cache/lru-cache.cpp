class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);  

    unordered_map<int, Node*> mp;
    int capacity;

    void addNode(Node* newNode) {
        Node* oldNode = head -> next;

        head -> next = newNode;
        oldNode -> prev = newNode;

        newNode -> next = oldNode;
        newNode -> prev = head;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode -> prev;
        Node* oldNext = oldNode -> next;

        oldPrev -> next = oldNext;
        oldNext -> prev = oldPrev;
    }

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* getNode = mp[key];
        int ans = getNode -> val;

        mp.erase(key);
        delNode(getNode);
        addNode(getNode);

        mp[key] = head -> next;
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
        }

        if(mp.size() == capacity) {
            mp.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }

        Node* newNode = new Node({key, value});
        addNode(newNode);
        mp[key] = newNode;
    }
};
