class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int flips = 0;

        // if (flips == odd) then value at ith index in s is 1
        // else if(flips == even) thn value at ith index in s is 0
        for(int i = 0; i < n; i++) {
            char value = target[i];

            if(flips % 2 != 0 && value == '0') flips++;
            else if(flips % 2 == 0 && value == '1') flips++; 
        }

        return flips;
    }
};