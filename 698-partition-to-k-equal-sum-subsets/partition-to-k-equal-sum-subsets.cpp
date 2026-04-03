class Solution {
public:
    int solve(int index, int sum, int k, int target, vector<int> &nums, vector<int> &vis) {
        if(k == 1) return true; // if only 1 subset left, remaining elements must form it
        if(sum == target) {
            return solve(0, 0, k-1, target, nums, vis);
        }

        for(int i = index; i < nums.size(); i++) {
            if(vis[i]) continue;
            if(sum + nums[i] > target) continue;

            vis[i] = 1;
            if(solve(i + 1, sum + nums[i], k, target, nums, vis) == true) return true;
            vis[i] = 0; // backtrack
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(auto ele : nums) sum += ele;
        if(sum % k != 0) return false; 

        int target = sum / k;
        // we just need to count the number of subsets with sum = target
        // if count == k, then return true, else false
        // but the problem in this approach is that :
        // we are just counting, how many subsets of the array have sum = target (subsets can overlap)
        // but we actually want the disjoint subsets where every element is used exactly once
        vector<int> vis(n, 0); // therefore, we need a vis array

        sort(nums.rbegin(), nums.rend()); // sort in descending
        if(nums[0] > target) return false;

        return solve(0, 0, k, target, nums, vis); // index, sum
    }
};