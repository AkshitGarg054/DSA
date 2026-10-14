class Solution {
    // maths behind this problem:
    /*
    split nums to two grps: P and N two grps P: num with + sign and N: num with - sign
    now the task is sum(P)-sum(N)=target -> see its very intuitive to understand it: now also sum(P)+sum(N) = sum

    sum(P) = (sum+target)/2

    hence out goal become to find the subset of numbers P that adds up to targetSum = (target+sum)/2

    handle the edge cases:
    1. [1,2,3] 1+2+3=6 and -1-2-3=-6 so the target problem can give is between -6<=target<=6
    if(abs(target)>sum) return 0; // impossible to form this target with given array

    2. (target+sum) % 2 == 0 must else return 0 ways... [1,1,1,1,1] target=2 ans is 0 ways...

    3. also if (sum+target)<0 return 0, we can't form neg subset sum with all pos numbers
    */

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n : nums) sum += n;

        if(abs(target) > sum || (target + sum) % 2 != 0 || (target + sum) < 0)
            return 0;

        int targetSum = (sum + target) / 2;
        return solve(0, targetSum, nums);
    }

    // ways to get the target sum from the subarrays of the given array or
    // How many subsets of nums add up to (target + totalSum)/2
    int solve(int idx, int sum, vector<int>& nums) {

        // eye opening base case after doing coin change... see below - very imp guide...
        if(idx >= nums.size()) { // check sum only when we reached at the end of the array
            if(sum == 0) {
                return 1;
            }
            return 0;
        }

        int take = 0;
        if(sum >= nums[idx])
            take = solve(idx + 1, sum - nums[idx], nums);

        int not_take = solve(idx + 1, sum, nums);

        return take + not_take;
    }
};