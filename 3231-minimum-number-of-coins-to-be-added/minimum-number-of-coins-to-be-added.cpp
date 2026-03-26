class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        sort(coins.begin(), coins.end()); // important

        int added = 0;
        int next_needed = 1;
        int i =  0; // index of current coin

        while(next_needed <= target) {
            if(i < n && coins[i] <= next_needed) {
                next_needed += coins[i];
                i++;
            }
            else {
                next_needed += next_needed;
                added++;
            }
        }

        return added;
    }
};