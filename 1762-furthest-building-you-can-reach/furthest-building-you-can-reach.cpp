class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq; // max heap
        int farthest = n - 1;

        // firstly, make the jumps with the bricks as much as possible (ladders are precious, we will save them)
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if(diff <= 0) continue;

            if(diff <= bricks) { // can be settled with bricks
                bricks -= diff;
                pq.push(diff);
            }
            else if(!pq.empty() && pq.top() > diff) { // use ladder for past height, instead of bricks
                ladders -= 1;
                bricks += pq.top();
                pq.pop();

                bricks -= diff;
                pq.push(diff);
            }
            else ladders -= 1; // use ladders, if bricks are not enough for any height now

            if(ladders < 0) return i - 1; // ith building can't be reached
        }
        
        return farthest;
    }
};