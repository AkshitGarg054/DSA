class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 1) return 1;
        if(n == 2) return 2;

        unordered_map<int, int> mp;

        int l = 0, r = 0;
        int maxi = 0;

        while(r < n) {
            mp[fruits[r]]++;

            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};