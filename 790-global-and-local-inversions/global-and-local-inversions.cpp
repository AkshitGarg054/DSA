class Solution {
public:
    // This question is based on the concept of counting inversions problem.

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;

        // start from 2, because a gap of 2 is the min distance for a non-local inversion
        for(int i = 2; i < n; i++) {
            maxi = max(maxi, nums[i - 2]);
            if(maxi > nums[i]) return false; // non-local inversion found
        }

        return true;
    }
};