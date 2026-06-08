class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans;
        int count_pivot = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) ans.push_back(nums[i]);
            else if(nums[i] == pivot) count_pivot++;
        }

        for(int i = 0; i < count_pivot; i++) ans.push_back(pivot);

        for(int i = 0; i < n; i++) {
            if(nums[i] > pivot) ans.push_back(nums[i]);
        }

        return ans;
    }
};