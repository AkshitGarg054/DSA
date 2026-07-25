class Solution {
public:
    // If a value x exists, then it belongs at index (x - 1).
    // So we repeatedly swap until every valid value reaches its correct index.

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // with each swap, one element goes to its correct position, so the approach is O(n)
        for(int i = 0; i < n; i++) {
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};