class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        if(a <= 2 && b <= 2) return string(a, 'a') + string(b, 'b');

        while(a > 0 || b > 0) {
            int n = ans.size();
            if(n >= 2 && ans[n-2] == 'a' && ans[n-1] == 'a') {
                ans += 'b';
                b--;
            }
            else if(ans.size() >= 2 && ans[n-2] == 'b' && ans[n-1] == 'b') {
                ans += 'a';
                a--;
            }
            else {
                if(a > b) {
                    ans += 'a';
                    a--;
                }
                else {
                    ans += 'b';
                    b--;
                }
            }
        }

        return ans;
    }
};