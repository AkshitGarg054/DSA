class Solution {
public:
    // say, indices till len/2 : 0, 1, 2, 3, 4
    // 2 * i : 0, 2, 4, 6, 8
    // 2 * i + 1 : 1, 3, 5, 7, 9
    // that is, we want odd index values to be double of even index values
    // in short, we want (n / 2) pairs of doubles
    // mtlb, agar ek bhi element aisa mil gya jiska double exist nhi krta, then directly return false

    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto x : arr) mp[x]++;

        // sort by absolute values
        // we need to find 2x for every x, so sorting is necessary
        // For -ve elements, If you process -4 first, you may wrongly try to pair it with -8, but actually -4 should be used as the double of -2.
        sort(arr.begin(), arr.end(), [&](const int a, const int b) {
            return abs(a) < abs(b);
        });

        for(auto x : arr) {
            if(mp[x] == 0) continue; // when 2*x will come as x
            if(mp[2*x] == 0) return false; // double pair does not exist for this x

            mp[x]--;
            mp[2*x]--;
        }

        return true;
    }
};