class Solution {
public:
    // group of 3 piles me se, maximum wali to hmesha alice hi lega, usko to kuch kr nhi skte
    // aurr bob last wali pile lega, so hme 3 piles ki aisi arrangement select kr skte hn jisme
    // last wali pile me hmesha min value wali pile rakhen
    // so, sort the array in ascending order, and first ki n piles bob ke liye reserved rakho
    // aurr khud ke liyee, take every 2nd pile (from right to left)

    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int sum = 0;

        for(int i = n-2; i >= n/3; i = i-2) sum += piles[i];
        return sum;
    }
};