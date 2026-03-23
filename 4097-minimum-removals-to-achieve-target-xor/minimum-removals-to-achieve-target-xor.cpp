class Solution {
public:
    unordered_map<string, int> mp;

    int solve(int i, int xorr, vector<int> &nums, int target) {
        if(i == nums.size()) {
            if(xorr == target) return 0;
            else return INT_MAX;
        }

        string key = to_string(i) + "#" + to_string(xorr);
        if(mp.count(key)) return mp[key];


        long long keep = solve(i + 1, xorr ^ nums[i], nums, target);
        long long remove = 1LL + solve(i + 1, xorr, nums, target);

        return mp[key] = min(keep, remove);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        int ans =  solve(0, 0, nums, target); // index, xorr
        if(ans == INT_MAX) return -1;
        return ans;
    }
};