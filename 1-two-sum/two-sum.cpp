class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) vec[i] = {nums[i], i};

        sort(vec.begin(), vec.end());
        int i = 0, j = n - 1;

        while(i < j) {
            if(vec[i].first + vec[j].first == target) return {vec[i].second, vec[j].second};
            else if(vec[i].first + vec[j].first > target) j--;
            else i++;
        }

        return {-1, -1};
    }
};