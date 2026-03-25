class Solution {
public:
    // We only have two types of mismatch : xy mismatch or yx mismatch
    // if xy, xy OR yx, yx mismatch are present --> can be fixed in 1 swap
    // but, xy, yx mismatch requires --> 2 swaps

    // There are two questions --
    // Whether it is possible to make the strings equal?
    // count of mismatches (xy + yx) should be even -> i.e either both odd or both even
    // How many swaps are needed?
    // if both xy and yx are even --> (xy + yx)/2 swaps 
    // if both xy and yx are odd --> xy/2 + yx/2 + 2 swaps

    // x x y y x y
    // y y x x y x

    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int xy = 0, yx = 0;
    
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            else if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        
        if((xy + yx) % 2 != 0) return -1;

        if(xy % 2 == 0 && yx % 2 == 0) return (xy + yx) / 2;
        return xy/2 + yx/2 + 2;
    }
};