class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = INT_MIN;
        int maxi_freq = 0;

        for(int i = 0; i < k; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                maxi_freq = 1;
            }
            else if(nums[i] == maxi) maxi_freq++;
        }

        vector<int> ans;
        ans.push_back(maxi);

        int l = 0, r = k;

        while(r < n) {
            // extend window
            if(nums[r] > maxi) {
                maxi = nums[r];
                maxi_freq = 1;
                l++; // to always maintain k size
            }
            else if(nums[r] == maxi) {
                maxi_freq++;
                l++;
            }
            else { // in this case (nums[r] < maxi), firstly shrink the window and insert new maxi instead of inserting old maxi in the answer
                if(nums[l] == maxi && maxi_freq > 1) {
                    maxi_freq--;
                    l++;
                }
                else if(nums[l] == maxi && maxi_freq == 1) {
                    l++;

                    // recompute maximum in window
                    maxi = INT_MIN;
                    maxi_freq = 0;

                    for(int i = l; i <= r; i++) {
                        if(nums[i] > maxi) {
                            maxi = nums[i];
                            maxi_freq = 1;
                        }
                        else if(nums[i] == maxi) {
                            maxi_freq++;
                        }
                    }
                }
                else if(nums[l] != maxi) {
                    l++;
                }
            }
            
            ans.push_back(maxi);
            r++;
        }

        return ans;
    }
};