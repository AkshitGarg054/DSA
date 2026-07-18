class Solution {
public:
    // The absolute value suggests sorting.
    // Let's say, array = [1, 3, 6, 8, 10] (after sorting) and query = 7
    // Then, [1, 3, 6] | [8, 10] 
    // Everything on left needs to be increased and on right needs to be decreased.
    // Use prefix sum.


    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];

        vector<long long> ans;

        for(auto &target: queries) {
            long long count = 0;
            // find the lb of target in sorted nums
            int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

            if(lb == n) { // all elements are smaller than target
                long long expected = 1LL * target * n;
                long long actual = prefix[n - 1];
                count += (expected - actual);
            }
            else if(nums[lb] == target) {
                // smaller or equal elements
                long long expected = 1LL * target * (lb + 1);
                long long actual = prefix[lb];
                count += (expected - actual);

                // greater elements
                expected = 1LL * target * (n - lb - 1);
                actual = prefix[n - 1] - prefix[lb];
                count += (actual - expected);
            }
            else {
                // smaller elements
                long long expected = 1LL * target * lb;
                long long actual = (lb == 0 ? 0 : prefix[lb - 1]);
                count += (expected - actual);

                // greater elements
                expected = 1LL * target * (n - lb);
                actual = prefix[n - 1] - (lb == 0 ? 0 : prefix[lb - 1]);
                count += (actual - expected);
            }

            ans.push_back(count);
        }

        return ans;
    }
};