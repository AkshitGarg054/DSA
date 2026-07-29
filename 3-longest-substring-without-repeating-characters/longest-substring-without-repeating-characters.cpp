class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

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

        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};