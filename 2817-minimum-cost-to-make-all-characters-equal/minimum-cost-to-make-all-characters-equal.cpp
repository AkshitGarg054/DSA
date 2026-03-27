class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();   
        long long ans = 0;

        for(int i = 1; i < n; i++) {
            // for every position where conflict is occuring
            // either flip the left part or the right part
            if(s[i] != s[i-1]) ans += min(i, n-i);
        }

        return ans;
    }
};