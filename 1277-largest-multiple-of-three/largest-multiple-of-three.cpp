class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n = digits.size();

        sort(digits.begin(), digits.end()); // sort 
        int sum = accumulate(digits.begin(), digits.end(), 0);

        if(sum % 3 == 0) {
            if(digits[n-1] == 0) return "0";
            string s = "";
            for(int i = n-1; i >= 0; i--) s += (digits[i] + '0'); // return s after reversing
            return s; 
        }
        else if(sum % 3 == 1) {
            // either remove one element with mod = 1 OR remove two elements with mod = 2 (minimum value elements)
            // checking for mod = 1 element first. (coz removing less elements is beneficial to get largest num)
            bool found = false;
            for(int i = 0; i < n; i++) {
                if(digits[i] % 3 == 1) {
                    found = true;
                    digits[i] = -1; // we don't want to take it
                    break;
                }
            }

            if(found == false) { // check for 2 elements with mod = 2
                vector<int> mod2(2, -1); // store index of those two elements
                
                for(int i = 0; i < n; i++) {
                    if(digits[i] % 3 == 2) {
                        if(mod2[0] == -1) mod2[0] = i;
                        else {
                            mod2[1] = i;
                            break;
                        }
                    }
                }

                if(mod2[1] != -1) { // two elements found
                    digits[mod2[0]] = -1;
                    digits[mod2[1]] = -1;
                }
                else return ""; // two elements are not found
            }
        }
        else {
            // either remove one element with mod = 2 OR remove two elements with mod = 1 (minimum value elements)
            // checking for mod = 2 element first. (coz removing less elements is beneficial to get largest num)
            bool found = false;
            for(int i = 0; i < n; i++) {
                if(digits[i] % 3 == 2) {
                    found = true;
                    digits[i] = -1; // we don't want to take it
                    break;
                }
            }

            if(found == false) { // check for 2 elements with mod = 1
                vector<int> mod1(2, -1); // store index of those two elements
                
                for(int i = 0; i < n; i++) {
                    if(digits[i] % 3 == 1) {
                        if(mod1[0] == -1) mod1[0] = i;
                        else {
                            mod1[1] = i;
                            break;
                        }
                    }
                }

                if(mod1[1] != -1) { // two elements found
                    digits[mod1[0]] = -1;
                    digits[mod1[1]] = -1;
                }
                else return ""; // two elements are not found
            }
        }

        string ans = "";
        for(int i = n-1; i >= 0; i--) {
            if(digits[i] != -1) ans += (digits[i] + '0');
        }

        if(ans[0] == '0') return "0";
        return ans;
    }
};