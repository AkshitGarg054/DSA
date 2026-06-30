class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // precompute palindromes 
        vector<vector<bool>> isPal(n, vector<bool>(n, false)); // isPal[i][j] tells if s[i..j] is a palindrome or not

        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // calculate minimum cuts
        vector<int> cuts(n, 0); // cuts[i] stores the min cuts needed for the prefix s[0...i]

        for(int i = 0; i < n; i++) {
            if(isPal[0][i] == true) { // if the prefix upto i is a palindrome, then no cuts needed till i
                cuts[i] = 0;
            }
            else {
                cuts[i] = i; // max possible cuts till prefix i

                // try making a cut after every index j
                for(int j = 0; j < i; j++) {
                    if(isPal[j + 1][i]) { // check if right side is a palindrome
                        cuts[i] = min(cuts[i], cuts[j] + 1);
                    }
                }
            }
        }

        return cuts[n - 1];
    }
};