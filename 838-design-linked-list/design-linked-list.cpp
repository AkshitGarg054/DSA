class MyLinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp -> next;
        }

        return temp -> data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        
        if(head == NULL) head = tail = newNode;
        else {
            newNode -> next = head; 
            head = newNode;
        }

        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) head = tail = newNode;
        else {
            tail -> next = newNode;
            tail = newNode;
        }

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;

        if(index == 0) {
            addAtHead(val);
            return; 
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i = 0; i < index - 1; i++) temp = temp -> next;

        newNode -> next = temp -> next;
        temp -> next = newNode; 
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        if(index == 0) {
            Node* temp = head;
            head = head -> next;
            delete temp;

            if(size == 1) tail = NULL;
            size--;
            return;
        }

        Node *temp = head;
        for(int i = 0; i < index - 1; i++) temp = temp -> next;

        Node* to_del = temp -> next; // node to be deleted
        temp -> next = to_del -> next;

        if(to_del == tail) tail = temp;
        delete to_del;
        size--;
    }
};
