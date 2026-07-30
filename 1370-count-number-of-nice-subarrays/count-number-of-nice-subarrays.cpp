class Solution {
public:
    // Use: Exactly(k) = AtMost(k) - AtMost(k-1)

    int solve(vector<int> &nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;
        int count = 0;
        int odds = 0;

        while(r < n) {
            if(nums[r] % 2 != 0) odds++;

            while(odds > k) {
                if(nums[l] % 2 != 0) odds--;
                l++;
            }

            count += (r - l + 1);
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};