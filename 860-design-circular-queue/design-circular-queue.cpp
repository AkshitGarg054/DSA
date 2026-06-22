class MyCircularQueue {
public:
    vector<int> q;
    int sz, capacity;
    int front = 0, rear = -1;

    MyCircularQueue(int k) {
        q.resize(k);
        sz = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(sz == capacity) return false; // queue is full
        rear = (rear + 1) % capacity;
        q[rear] = value;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(sz == 0) return false; // queue is empty
        front = (front + 1) % capacity;
        sz--;
        return true;
    }
    
    int Front() {
        if(sz == 0) return -1; // queue is empty
        return q[front];
    }
    
    int Rear() {
        if(sz == 0) return -1; // queue is empty
        return q[rear];
    }
    
    bool isEmpty() {
        if(sz == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(sz == capacity) return true;
        return false;
    }
};
