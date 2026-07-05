class Solution {
public:
    int solve(string &s, int &i) {
        int n = s.size();
        if(n == 1) return s[0] - '0'; 

        long long number = 0;
        int sign = 1;
        long long ans = 0;

        while(i < n) {

            if(isdigit(s[i])) {
                number = 1LL * number * 10 + (s[i] - '0');
                i++;
            }
            else if(s[i] == '+' || s[i] == '-') {
                ans += 1LL * sign * number;
                number = 0;
                if(s[i] == '+') sign = 1;
                else sign = -1;
                i++;
            }
            else if(s[i] == '(') {
                i++; // skip this bracket
                ans += 1LL * sign * solve(s, i);
            }
            else if(s[i] == ')') {
                i++; // skip bracket
                break;
            }
            else i++; // for spaces
        }

        ans += 1LL * sign * number;
        return (int)ans;
    }

    int calculate(string s) {
        int i = 0;
        return solve(s, i);
    }
};