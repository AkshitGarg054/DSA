class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n > m) return false;
        if(n == 1) return true; // replace the only char
        
        vector<int> left(n, -1), right(n, -1);

        // traverse from left to right and populate the left array
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(s[i] == t[j]) {
                left[i] = j;
                i++; // start looking for next char now
            }
            j++;
        }

        if(left[n - 1] != -1) return true; // if the entire string already got matched

        // traverse from right to left and populate the right array
        i = n - 1, j = m - 1;
        while(i >= 0 && j >= 0) {
            if(s[i] == t[j]) {
                right[i] = j;
                i--;
            }
            j--;
        }

        if(right[0] != -1) return true; // entire string got matched

        // check if replacement works
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(right[1] != -1 && right[1] > 0) return true; // replacing the first char, and checkin if suffix fits
            }
            else if(i == n - 1) {
                if(left[n - 2] != -1 && left[n - 2] < m - 1) return true; // replacing the last char, and checkin if prefix fits  
            }
            else {
                if(left[i - 1] != -1 && right[i + 1] != -1 && right[i + 1] - left[i - 1] > 1) return true; // replacing the middle char
            }
        }

        return false;
    }
};