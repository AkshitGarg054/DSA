class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        int left = 0; // left and right are the pointers on fruits array.
        int sum = 0, ans = 0;

        // we will check all [left, right] intervals and find the number of fruits that we can pick in each interval and then take the maximum of all.
        for(int right = 0; right < n; right++) {
            sum += fruits[right][1];

            while(left <= right) {
                int l = fruits[left][0];
                int r = fruits[right][0];

                int leftFirst = 2 * max(0, startPos - l) + max(0, r - startPos);
                int rightFirst = 2 * max(0, r - startPos) + max(0, startPos - l);
                if(min(leftFirst, rightFirst) <= k) break;

                sum -= fruits[left][1];
                left++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};