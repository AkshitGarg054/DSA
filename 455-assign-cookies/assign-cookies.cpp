class Solution {
public:
    int solve(int i, int j, vector<int> &g, vector<int> &s) {
        if(i == g.size()) return 0;
        if(j == s.size()) return 0;

        int take = 0, skip = 0;
        if(g[i] <= s[j]) take = 1 + solve(i + 1, j + 1, g, s);
        else skip = solve(i, j + 1, g, s);

        return take + skip;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        return solve(0, 0, g, s);
    }
};