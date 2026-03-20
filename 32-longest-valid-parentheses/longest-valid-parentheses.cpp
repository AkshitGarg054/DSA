class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
    
        int left = 0, right = 0;
        int maxi = 0;

        // forward pass
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') left++;
            else right++;

            if(left == right) maxi = max(maxi, left * 2);
            else if(right > left) { // extra right bracket encountered
                left = 0;
                right = 0;
            } 
        }

        left = 0, right = 0;

        // backward pass
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') left++;
            else right++;

            if(left == right) maxi = max(maxi, left * 2);
            else if(left > right) { // extra left bracket encountered
                left = 0;
                right = 0;
            } 
        }

        return maxi;
    }
};