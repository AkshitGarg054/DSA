class Solution {
public:
    // Approach 2: Two pass method by balancing the counters
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int ans = 0;

        // left to right pass
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') left++;
            else right++;

            if(left == right) ans = max(ans, left * 2);
            else if(right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;

        // right to left pass
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') left++;
            else right++;

            if(left == right) ans = max(ans, left * 2);
            else if(left > right) {
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};