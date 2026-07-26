class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);    
        if(totalGas < totalCost) return -1;

        // now, answer is guaranteed.
        int currGas = 0;
        int start = 0; // for 0th index.

        for(int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i]; // curr total gas in our tank.
            if(currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }

        return start;
    }
};