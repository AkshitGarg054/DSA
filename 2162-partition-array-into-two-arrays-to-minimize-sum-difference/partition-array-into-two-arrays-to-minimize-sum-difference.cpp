class Solution {
public:
    // This is not a simple subset sum problem like "Last stone weight II".
    // here we don't simply need the maximum subset sum <= target
    // we also need to keep the size of subset = n (max subset sum with SIZE constraint)
    // also there are negative elements in the question
    // correct approach : Meet-in-the-Middle with size constraint
    // DP fails because DP doesn’t enforce selecting exactly n elements and fails with negative numbers. (very large constraints)

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        // it stores : what are all the sums possible for a subset of size i
        vector<vector<int>> left_sums(n + 1), right_sums(n + 1);

        // storing all possible sums in left and right part
        for(int mask = 0; mask < (1 << n); mask++) { // if n = 3, then we will create masks till 2^3 - 1 (010 means take 2nd ele only)
            int sz = 0, l = 0, r = 0;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) { // ith bit of mask is 1 (means ith element needs to be included)
                    sz++;
                    l += nums[i];
                    r += nums[n + i];
                }
            }

            left_sums[sz].push_back(l);
            right_sums[sz].push_back(r);
        }

        int mini = INT_MAX;

        // sort the right half arrays to apply binary search
        for (int i = 0; i <= n; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        // meet in the middle
        for(int k = 0; k <= n; k++) {
            for(int x : left_sums[k]) {
                // If we picked 'k' elements from the left, we MUST pick 'n - k' from the right.
                // We want the combined sum (x + y) to be as close to total_sum / 2 as possible.
                // minimize (total_sum - 2*(x + y))
                // use binary search to find y
                // ideal y = (total_sum / 2) - x 
                int target = total_sum / 2 - x;
                vector<int> &right_arr = right_sums[n - k];

                int lb = lower_bound(right_arr.begin(), right_arr.end(), target) - right_arr.begin();
                if(lb != right_arr.size()) {
                    int y = right_arr[lb];
                    mini = min(mini, abs(total_sum - 2 * (x + y)));
                }

                // also check the element just before it (which is < target)
                if(lb > 0) {
                    int y = right_arr[lb - 1];
                    mini = min(mini, abs(total_sum - 2 * (x + y)));
                }
            }
        }

        return mini;
    }
};