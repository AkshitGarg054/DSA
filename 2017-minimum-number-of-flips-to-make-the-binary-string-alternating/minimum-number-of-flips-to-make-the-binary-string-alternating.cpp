class Solution {
public:
    // An alternating string can have two possibilites: 010101... or 101010....
    // So, if there were no rotation, then answer = min(mismatches with pattern1, mismatches with pattern2);
    // Now, trying every rotating any calculate the minimum mismatches is difficult.
    // So, we create t = s + s.
    // Now, every rotation of s appears as a substring of length n inside t.
    // For every window of size n in t, calculate the min operations and take the min of all.

    int solve1(string &s, int l, int r) {
        // To check with 01010...
        int ops = 0;
        char expected = '0';
        for(int i = l; i <= r; i++) {
            if(s[i] != expected) ops++;
            expected = (expected == '0' ? '1' : '0');
        }
        return ops;
    }

    int solve2(string &s, int l, int r) {
        // To check with 10101...
        int ops = 0;
        char expected = '1';
        for(int i = l; i <= r; i++) {
            if(s[i] != expected) ops++;
            expected = (expected == '0' ? '1' : '0');
        }
        return ops;
    }

    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int diff1 = solve1(t, 0, n - 1);
        int diff2 = solve2(t, 0, n - 1);

        int mini = min(diff1, diff2);
        int l = 0, r = n;

        while(r < 2*n) {
            // incoming ele...
            char exp1 = (r % 2 == 0) ? '0' : '1'; // 01010 contains 0 at even indices
            char exp2 = (r % 2 == 0) ? '1' : '0'; // 10101 contains 0 at odd indices

            if(t[r] != exp1) diff1++;
            if(t[r] != exp2) diff2++;

            while(r - l + 1 > n) {
                char exp1 = (l % 2 == 0) ? '0' : '1'; 
                char exp2 = (l % 2 == 0) ? '1' : '0'; 
                if(t[l] != exp1) diff1--;
                if(t[l] != exp2) diff2--;
                l++;
            }

            mini = min({mini, diff1, diff2});
            r++;
        }

        return mini;
    }
};