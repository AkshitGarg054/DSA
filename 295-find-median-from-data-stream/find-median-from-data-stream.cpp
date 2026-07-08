class MedianFinder {
public:
    priority_queue<int> max_heap; // max heap is used to store the smaller half of the numbers
    priority_queue<int, vector<int>, greater<>> min_heap; // used to store the larger half of the numbers

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() && min_heap.empty()) max_heap.push(num); // can push into min heap also
        else {
            if(num > max_heap.top()) min_heap.push(num); // coz every element in max_heap should be <= every element in min_heap and max_heap.top() is largest ele of smaller half
            else max_heap.push(num);
        }

        int n = max_heap.size();
        int m = min_heap.size();

        if(abs(n - m) == 2) { // became unbalanced
            if(n > m) { // pop from max_heap and push into min_heap
                int ele = max_heap.top();
                max_heap.pop();
                min_heap.push(ele);
            }
            else {
                int ele = min_heap.top();
                min_heap.pop();
                max_heap.push(ele);
            }
        }
    }
    
    double findMedian() {
        int n = max_heap.size();
        int m = min_heap.size();
        double median;

        if((n + m) % 2 == 0) median = (max_heap.top() + min_heap.top()) / 2.0;
        else {
            if(n > m) median = max_heap.top();
            else median = min_heap.top();
        }

        return median;
    }
};
