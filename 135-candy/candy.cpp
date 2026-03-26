class Solution {
public:
    // just try doing a simple pass on a random test case
    // say, [4, 6, 7, 1, 8, 4, 3, 6]

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // atleast one candy to each

        vector<int> left(n, 1); // atleast one candy to each
        vector<int> right(n, 1);

        // forward pass
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
        }

        // backward pass
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(left[i], right[i]);
        }

        return ans;
    }
};