class Solution {
public:
    // start iterating.
    // at every position where s[i] and target[i] are not equal, we need to flip the suffix
    // and every time, we need to compare with the updated s. (not the initial s)

    int minFlips(string target) {
        int n = target.size();
        string s = string(n, '0');
        int count = 0;

        char next = s[0];
        for(int i = 0; i < n; i++) {
            if(next != target[i]) {
                count++;
                next = target[i];
            }
        }

        return count;
    }
};