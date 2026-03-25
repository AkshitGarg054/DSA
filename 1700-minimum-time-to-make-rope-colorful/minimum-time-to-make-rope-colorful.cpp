class Solution {
public:
    // If we have consecutive same colors, keep the balloon with maximum removal time and remove all others

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;

        int i = 0;
        while(i < n) {
            int sum = neededTime[i];
            int maxi = neededTime[i];

            int j = i + 1;
            while(j < n && colors[i] == colors[j]) { // iterate on consecutives
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }

            ans += sum - maxi; // remove all except max one
            i = j;
        }

        return ans;
    }
};