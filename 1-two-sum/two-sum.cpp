class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) arr[i] = {nums[i], i};

        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;

        while(i < j) {
            int ele1 = arr[i].first;
            int ele2 = arr[j].first;

            if(ele1 + ele2 == target) return {arr[i].second, arr[j].second};
            else if(ele1 + ele2 > target) j--;
            else i++;
        }

        return {-1, -1};
    }
};