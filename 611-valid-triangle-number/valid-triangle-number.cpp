class Solution {
public:
    // we want : a + b > c AND b + c > a AND a + c > b
    // After sorting, fix the largest side nums[k].
    // Find how many pairs satisfy : nums[i] + nums[j] > nums[k] 
    // use i = 0, j = k-1

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int k = n-1; k >= 2; k--) {
            int i = 0, j = k-1;

            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    count += (j - i); // valid for all i till j-1
                    j--;
                }
                else i++; // need bigger value
            }
        }

        return count;
    }
};