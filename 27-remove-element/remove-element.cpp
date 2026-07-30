class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int i = -1, j = -1; // i -> first 'val' element, j -> first non-val ele after 'val'
        for(int index = 0; index < n; index++) {
            if(nums[index] == val) {
                i = index;
                break;
            }
        }

        if(i == -1) return n;

        for(int index = i + 1; index < n; index++) {
            if(nums[index] != val) {
                j = index;
                break;
            }
        }

        if(j == -1) return i;

        while(j < n) {
            if(nums[j] == val) j++;
            else swap(nums[i++], nums[j++]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != val) ans++;
        }

        return ans;
    }
};