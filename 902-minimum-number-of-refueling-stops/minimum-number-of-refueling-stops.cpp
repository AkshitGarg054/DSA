class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(target <= startFuel) return 0;

        priority_queue<int> pq; // max heap
        int curr_fuel = startFuel;
        int count = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            int pos = stations[i][0];
            int fuel = stations[i][1];

            curr_fuel -= (pos - prev);

            while(!pq.empty() && curr_fuel < 0) {
                curr_fuel += pq.top();
                pq.pop();
                count++;
            }
            
            if(curr_fuel < 0) return -1; // if still the fuel is not enough, then return -1
            pq.push(fuel); // push only when we reached the station successfully
            prev = pos;
        }

        // travel from last station to target
        curr_fuel -= (target - prev);

        while(!pq.empty() && curr_fuel < 0) {
            curr_fuel += pq.top();
            pq.pop();
            count++;
        }
        
        if(curr_fuel < 0) return -1;
        return count;
    }
};