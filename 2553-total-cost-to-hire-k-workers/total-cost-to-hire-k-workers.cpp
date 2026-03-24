class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        
        // create two min heaps
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;

        int l = 0, r = n-1;

        for(int i = 0; i < candidates && l <= r; i++) left.push(costs[l++]);
        for(int i = 0; i < candidates && l <= r; i++) right.push(costs[r--]);

        long long ans = 0;

        while(k) {
            int ele1 = left.empty() ? INT_MAX : left.top();
            int ele2 = right.empty() ? INT_MAX : right.top();

            if(ele1 > ele2) {
                ans += ele2;
                right.pop();
                if(l <= r) right.push(costs[r]);
                r--;
            }
            else {
                ans += ele1;
                left.pop();
                if(l <= r) left.push(costs[l]);
                l++;
            }

            k--;
        }

        return ans;
    }
};