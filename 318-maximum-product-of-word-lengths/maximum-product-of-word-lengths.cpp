class Solution {
public:
    // How can we solve this using BITMASKING?
    // See isme bhi hme yehi check krna haii ki jo chars ith word me exist krte hn vo jth me hnn ya nhii.
    // so, in short, intuition milri haii ki har ek word ka bitmask bnayenge.
    // but the problem is that ki har word ka size to alg alg haii to compare kaise krenge.
    // For this, hm alg alg size ka bitmask ni bnayenge, blki 26 size ka bitmask bnayenge ..for a to z
    // Bit 0 --> 'a', 1 --> 'b' (word: abc --> bitmask: 000....111)
    // So, jo kaam abhi hm freq map se kr rhe hn, vahi kaam hm ab bitmask se krenge.
    // mask[i] |= (1 << (ch - 'a')); --> build mask for each char
    // If two words share any char, then their mask will overlap and --> (mask[i] & mask[j]) != 0  // common character exists

    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);

        // create mask for each word
        for(int i = 0; i < n; i++) {
            for(auto ch : words[i]) {
                mask[i] |= (1 << (ch - 'a'));
            }
        }

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((mask[i] & mask[j]) == 0) { // bracket is necessary due to operator precedence.
                    int product = words[i].size() * words[j].size();
                    maxi = max(maxi, product);
                }
            }
        }

        return maxi;
    }
};