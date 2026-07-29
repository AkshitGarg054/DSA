class Solution {
public:
    // This fails for nums = [3, 3], target == 6 because in map, it only stores 3 -> 1
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp; // value -> index
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i; 

        for(int i = 0; i < n; i++) {
            int val = nums[i];
            int index = i;

            if(mp.count(target - val) && mp[target - val] != index) { // val + x = target
                int index1 = mp[target - val];
                return {index1, index};
            }
        }

        return {};
    }
};