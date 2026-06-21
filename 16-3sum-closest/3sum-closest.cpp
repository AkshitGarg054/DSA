class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff = INT_MAX;
        int dir = 0; // 1 if sum > target, -1 if sum < target

        sort(nums.begin(), nums.end());
    
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == target) return target;

                else if(sum < target) {
                    int diff = abs(sum - target);

                    if(diff < min_diff) {
                        min_diff = diff;
                        dir = -1;
                    }

                    j++;
                }
                else {
                    int diff = abs(sum - target);

                    if(diff < min_diff) {
                        min_diff = diff;
                        dir = 1;
                    }

                    k--;
                }
            }
        }

        if(dir == -1) return target - min_diff;
        return target + min_diff;
    }
};