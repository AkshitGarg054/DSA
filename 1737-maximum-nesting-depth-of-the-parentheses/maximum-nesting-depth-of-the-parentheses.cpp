class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int balance = 0;
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == '(') balance++;
            else if(ch == ')') balance--;
            maxi = max(maxi, balance);
        }

        return maxi;
    }
};