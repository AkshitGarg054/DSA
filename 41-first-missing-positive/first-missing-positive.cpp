class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // we need to set all positive elements at their correct position. (For nums[i], correct pos is nums[i] - 1) ...see that there is no correct position for 0.
        // After this, the first index which does not contain its correct element, will contain our answer.
        for(int i = 0; i < n; i++) {
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) { // check whether nums[i] is present at its correct position (nums[i] - 1) or not.
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};