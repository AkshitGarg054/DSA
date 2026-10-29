class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 1) return 1;
        if(n == 2) return 2;

        int f1 = -1, f2 = -1;
        int count1 = 0, count2 = 0;
        int l = 0, r = 0;
        int maxi = INT_MIN;

        while(r < n) {
            int x = fruits[r];

            if(x == f1) count1++;
            else if(x == f2) count2++;
            else if(count1 == 0) f1 = x, count1 = 1;
            else if(count2 == 0) f2 = x, count2 = 1;
            else {
                while(count1 > 0 && count2 > 0) {
                    if(fruits[l] == f1) count1--;
                    else count2--;
                    l++;
                }

                if(count1 == 0) f1 = x, count1 = 1;
                else f2 = x, count2 = 1;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};