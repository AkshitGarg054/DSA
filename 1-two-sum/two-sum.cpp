class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> v;
        for(int i=0; i < n; i++) {  
            v.push_back({nums[i], i});  
        }  

        // v will be sorted by value
        sort(v.begin(), v.end());  
        int i = 0;
        int j = n - 1;
        
        while(i < j) {
            int left = v[i].first;
            int right = v[j].first;

            if(left + right < target) {
                i++;
            }
            else if(left + right > target) {
                j--;
            }
            else {
                return {v[i].second, v[j].second};
            }
        }

        return {-1};
    }
};