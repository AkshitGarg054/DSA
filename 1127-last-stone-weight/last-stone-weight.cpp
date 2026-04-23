class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq; // max heap
        for(int i = 0; i < n; i++) pq.push(stones[i]);

        while(pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            int diff = s1 - s2;
            if(diff != 0) pq.push(diff);
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};