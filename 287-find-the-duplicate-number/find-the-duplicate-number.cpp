class Solution {
public:
    // approach 3: tortoise and hare algo

    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        // detect cycle
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // move slow pointer back to start
        slow = nums[0];

        // keep moving both by 1
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // or fast
    }
};