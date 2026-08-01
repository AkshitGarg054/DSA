class Solution {
public:
    // we will store the remainders in the map.
    // If the same remainder exists in the past which is equal to the current remainder,
    // then it means that the sum of in-between elements is divisible by k, coz they contributed 0 to the remainder.
    // Suppose: prefix1 % k = r and prefix2 % k = r
    // Then: (prefix2 - prefix1) % k = 0

    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // store remainders and their index at which it occurs
        mp[0] = -1;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if(mp.count(rem)) {
                if(i - mp[rem] >= 2) return true;
            }
            else mp[rem] = i;
        }
        
        return false;
    }
};