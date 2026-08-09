class Solution {
public:
    // Since you are allowed to insert exactly one new letter anywhere in the string, that letter should obviously be an 'L', a 'C', or a 'T' to help complete as many sequences as possible.
    // We have three options: 
    // 1. Insert an 'L' at the very beginning --> bonus gained = Total number of existing "CT" pairs.
    // 2. Insert a 'C' somewhere in the middle --> Bonus gained = Total number of existing "LC" pairs.
    // 3. Insert a 'C' somewhere in the middle --> bonus gained = L's on left * T's on right.

    long long numOfSubsequences(string s) {
        long long L = 0, LC = 0, LCT = 0;

        // Existing number of "LCT" subsequences
        for (char ch : s) {
            if (ch == 'L') L++;
            else if (ch == 'C') LC += L;
            else if (ch == 'T') LCT += LC;
        }

        // Option 1: Insert 'L' at the beginning.
        // It can pair with every existing "CT" subsequence.
        long long CT = 0, C = 0;
        for (char ch : s) {
            if (ch == 'C') C++;
            else if (ch == 'T') CT += C;
        }

        long long ans = LCT + CT;

        // Option 2: Insert 'T' at the end.
        // It can pair with every existing "LC" subsequence.
        ans = max(ans, LCT + LC);

        // Option 3: Insert 'C' somewhere.
        // Number of new LCT = (# L on left) * (# T on right)
        long long totalT = 0;
        for (char ch : s) {
            if(ch == 'T') totalT++;
        }

        long long leftL = 0, rightT = totalT;

        for (int i = 0; i < s.size(); i++) {
            ans = max(ans, LCT + leftL * rightT);
            if (s[i] == 'L') leftL++; 
            if (s[i] == 'T') rightT--;
        }

        return ans;
    }
};