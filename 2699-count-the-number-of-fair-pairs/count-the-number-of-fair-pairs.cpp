class Solution {
public:
    // lower ≤ nums[i] + nums[j] ≤ upper
    // This is same as :
    // (count_pairs with sum <= upper) - (count_pairs with sum < lower)
    // So, whenever we are giving a range like (lowe to upper)
    // then always think of finding for <= upper and < lower and subtract

    long long count_pairs(vector<int> &nums, int limit) {
        long long count = 0;
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum <= limit) {
                count += (r - l);
                l++;
            }
            else r--;
        }

        return count;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return count_pairs(nums, upper) - count_pairs(nums, lower - 1);
    }
};