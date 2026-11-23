class MedianFinder {
public:
    priority_queue<int> max_heap; // max heap is used to store the smaller half of the numbers
    priority_queue<int, vector<int>, greater<>> min_heap; // used to store the larger half of the numbers

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num); // always push the incoming element in min heap

        int ele = min_heap.top(); // pop from minheap and push to max heap
        min_heap.pop();
        max_heap.push(ele);

        if(max_heap.size() > min_heap.size()) { // if maxheap size is greater than minheap size, then pop from maxheap and push to minheap
            ele = max_heap.top();
            max_heap.pop();
            min_heap.push(ele);
        }
    }
    
    double findMedian() {
        int n = max_heap.size();
        int m = min_heap.size();
        double median;

        if((n + m) % 2 == 0) median = (max_heap.top() + min_heap.top()) / 2.0;
        else median = min_heap.top();

        return median;
    }
};
