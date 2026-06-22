class MyCircularDeque {
public:
    vector<int> q;
    int sz, capacity;
    int front, rear;

    MyCircularDeque(int k) {
        q.resize(k);
        sz = 0;
        capacity = k;
        
        front = 0;
        rear = k - 1; // IMPORTANT CHANGE 1 from circular queue: Initialize rear to k - 1 instead of -1
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        
        // IMPORTANT CHANGE 2: Stepping backwards in a circular array
        front = (front - 1 + capacity) % capacity;
        q[front] = value;
        sz++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        
        rear = (rear + 1) % capacity;
        q[rear] = value;
        sz++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        
        front = (front + 1) % capacity;
        sz--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        
        // IMPORTANT CHANGE 2: Stepping backwards in a circular array
        rear = (rear - 1 + capacity) % capacity;
        sz--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == capacity;
    }
};