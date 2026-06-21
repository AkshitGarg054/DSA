class Solution {
public:
    // duplicate characters ki baat ho rhi haii, so use set
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        unordered_set<char> st;
        int l = 0, r = 0;
        int maxi = INT_MIN;

        while(r < n) {
            while(st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};