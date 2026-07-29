class Solution {
public:
    // This fails for nums = [3, 3], target == 6 because in map, it only stores 3 -> 1
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp; // value -> index

        for(int i = 0; i < nums.size(); i++) {
            int value = nums[i];

            if(mp.count(target - value)) {
                int index1 = mp[target - value];
                return {index1, i}; 
            }

            mp[value] = i; 
        }

        return {};
    }
};