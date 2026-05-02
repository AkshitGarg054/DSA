class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {
            string s = to_string(i);
            bool valid = true;
            bool changed = false;

            for(int j = 0; j < s.size(); j++) {
                int ch = s[j];
            
                if(ch == '3' || ch == '4' || ch == '7') {
                    valid = false;
                    break;
                }
                if(ch == '2' || ch == '5' || ch == '6' || ch == '9') changed = true; // we want a number that is different from x
            }

            if(valid && changed) count++;
        }

        return count;
    }
};