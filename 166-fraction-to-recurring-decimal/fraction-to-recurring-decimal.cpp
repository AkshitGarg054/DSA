class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans = ""; 
        if(numerator < 0 && denominator < 0) ans = "";
        else if(numerator < 0 || denominator < 0) ans += '-';

        long long n = 1LL * abs((long long)numerator); 
        long long d =  1LL * abs((long long)denominator); 

        // integer part
        ans += to_string(n / d);
        long long rem = n % d;

        if(rem == 0) return ans;
        ans += '.';                    

        // let's calculate the fractional part
        unordered_map<long long, int> seen; // remainder -> index (that is, at which position the rem was seen) ...to handle 1/6 = 0.1(6)
    
        string fraction = ""; 
        bool repeating = false;

        // dry run with 7/5, 1/3 and 1/6 
        while(true) {
            if(rem == 0) break;
            if(seen.count(rem)) {
                repeating = true;
                break;
            }

            seen[rem] = fraction.size();

            rem = rem * 10;
            fraction += to_string(rem / d);
            rem = rem % d;
        }

        if(repeating == false) {
            ans = ans + fraction;
            return ans;
        }

        // else
        fraction.insert(seen[rem], "(");
        ans = ans + fraction + ')';
        return ans;
    }
};