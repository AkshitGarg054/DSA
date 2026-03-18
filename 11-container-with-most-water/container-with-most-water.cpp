class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int low = 0, high = n-1;
        int ans = INT_MIN;

        while(low < high) {
            int h = min(height[low], height[high]);
            ans = max(ans, h * (high - low));

            if(height[low] < height[high]) low++;
            else high--;
        }

        return ans;
    }
};