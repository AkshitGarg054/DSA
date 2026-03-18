class Solution {
public:
    bool check(vector<int> &piles, int k, int h) {
        long long hours = 0;

        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] < k) hours += 1;
            else hours += (piles[i] + k - 1LL) / k; // ceil(piles[i] / k)
        }

        return (hours <= (long long)h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};