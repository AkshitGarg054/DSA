class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(max_heap.empty() && min_heap.empty()) max_heap.push(num);
        else {
            if(max_heap.top() < num) min_heap.push(num);
            else max_heap.push(num);
        }

        int n = max_heap.size();
        int m = min_heap.size();

        if(abs(n - m) == 2) { // got unbalanced
            if(n > m) { // pop from n and push into m
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
        double median;
        int n = max_heap.size();
        int m = min_heap.size();

        if((n + m) % 2 == 0) median = (max_heap.top() + min_heap.top()) / 2.0;
        else {
            if(n > m) median = max_heap.top();
            else median = min_heap.top();
        }

        return median;
    }
};