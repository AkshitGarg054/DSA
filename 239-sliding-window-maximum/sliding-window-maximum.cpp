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
            // extend window: incoming ele can be = maxi, > maxi, < maxi
            if(nums[r] > maxi) {
                maxi = nums[r];
                maxi_freq = 1;
                l++; // no matter what nums[l] is, coz we got the new maxi
            }
            else if(nums[r] == maxi) {
                if(nums[l] != maxi) maxi_freq++;
                l++;
            }
            else { // nums[r] < maxi
                // there can be two cases: either nums[l] == maxi or != maxi
                if(nums[l] != maxi) l++;
                else { // nums[l] == maxi
                    if(maxi_freq == 1) { // compute new maxi
                        l++;
                        maxi = INT_MIN;
                        maxi_freq = 0;

                        for(int i = l; i <= r; i++) {
                            if(nums[i] > maxi) {
                                maxi = nums[i];
                                maxi_freq = 1;
                            }
                            else if(nums[i] == maxi) maxi_freq++;
                        }
                    }
                    else {
                        maxi_freq--;
                        l++;
                    }
                }
            }

            ans.push_back(maxi);
            r++;
        }
        
        return ans;
    }
};