class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();

        // min_cost[i] = cheapest cost seen for chocolate i so far
        vector<long long> min_cost(nums.begin(), nums.end());
        long long answer = LLONG_MAX;

        for(int k = 0; k < n; k++) { // k = number of rotations

            // update min cost for each chocolate after k rotations
            for(int i = 0; i < n; i++) {
                min_cost[i] = min(min_cost[i], (long long)nums[(i - k + n) % n]);
            }

            // total cost = sum of min costs + rotation cost
            long long total = 1LL * k * x;
            for(int i = 0; i < n; i++) total += min_cost[i];

            answer = min(answer, total);
        }

        return answer;
    }
};